$NetBSD: patch-src_game_Highscores.cpp,v 1.1 2024/04/21 17:07:36 adam Exp $

Fix build with newer boost.

--- src/game/Highscores.cpp.orig	2024-04-21 17:03:18.448207624 +0000
+++ src/game/Highscores.cpp
@@ -105,7 +105,7 @@ bool Highscores::add(HighscoresEntry ent
 		ofile.close();
 
 		boost::filesystem::copy_file(hsTempFile, hsFile, 
-				boost::filesystem::copy_option::overwrite_if_exists);
+				boost::filesystem::copy_options::overwrite_existing);
 		boost::filesystem::remove(hsTempFile);
 
 		cout << "Scores was updated." << endl;
