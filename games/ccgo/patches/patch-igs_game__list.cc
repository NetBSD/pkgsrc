$NetBSD: patch-igs_game__list.cc,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- igs/game_list.cc.orig	2015-12-25 16:58:38.000000000 +0000
+++ igs/game_list.cc
@@ -253,7 +253,7 @@ void GameList::update(const Game & g)
 
 			skip_move(i->game.get_num());
 			i->state = GS_NORMAL;
-			i->show->input_line.connect(bind(game_input_kibitz.make_slot(), i->game.get_num()));
+			i->show->input_line.connect(bind(game_input_kibitz.make_slot(), std::placeholders::_1, std::placeholders::_2, i->game.get_num()));
 			i->show->set_play(i->game.get_white() == name, i->game.get_black() == name);
 			if (i->game.get_white() == name || i->game.get_black() == name) { // am i playing
 				my_match = i->game.get_num();
