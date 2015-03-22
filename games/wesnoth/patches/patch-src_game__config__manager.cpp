$NetBSD: patch-src_game__config__manager.cpp,v 1.1 2015/03/22 20:05:29 joerg Exp $

--- src/game_config_manager.cpp.orig	2015-03-21 22:11:07.000000000 +0000
+++ src/game_config_manager.cpp
@@ -68,7 +68,7 @@ bool game_config_manager::init_game_conf
 	// Add preproc defines according to the command line arguments.
 	game_config::scoped_preproc_define multiplayer("MULTIPLAYER",
 		cmdline_opts_.multiplayer);
-	game_config::scoped_preproc_define test("TEST", cmdline_opts_.test);
+	game_config::scoped_preproc_define test("TEST", bool(cmdline_opts_.test));
 	game_config::scoped_preproc_define editor("EDITOR", jump_to_editor_);
 	game_config::scoped_preproc_define title_screen("TITLE_SCREEN",
 		!cmdline_opts_.multiplayer && !cmdline_opts_.test && !jump_to_editor_);
