#include "Level.h"
#include <string>
#include "Utils.h"
#include "monsters/Monster.h"
#include "data/DataCenter.h"
#include <allegro5/allegro_primitives.h>
#include "shapes/Point.h"
#include "shapes/Rectangle.h"
#include <array>

using namespace std;

void Level::init() {
    level = -1;
    background_path.clear();
}

void Level::load_level(int lvl) {
    level = lvl;
    DataCenter* DC = DataCenter::get_instance();

    char buf[50];
    sprintf(buf, "./assets/level/LEVEL%d.png", lvl);
    background_path = buf;

    DC->monsters.clear();

    // spawn 10 small monsters for level 1
    for(int i = 0; i < 10; i++) {
        DC->monsters.emplace_back(Monster::create_monster(MonsterType::SLIME));
    }

    debug_log("<Level> load level %d, spawn 20 small monsters.\n", lvl);
}

void Level::update() {
    
}

void Level::draw() {
    if(background_path.empty()) return;

    ALLEGRO_BITMAP* bg = al_load_bitmap(background_path.c_str());
    if(bg) {
        al_draw_bitmap(bg, 0, 0, 0);
        al_destroy_bitmap(bg);
    }
}