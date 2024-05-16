$NetBSD: patch-engine_core_gui_fifechan_fifechanmanager.cpp,v 1.1 2024/05/16 13:38:42 wiz Exp $

boost 1.85 support.
https://github.com/fifengine/fifengine/issues/1085#issuecomment-2115210942

--- engine/core/gui/fifechan/fifechanmanager.cpp.orig	2019-01-11 17:24:38.000000000 +0000
+++ engine/core/gui/fifechan/fifechanmanager.cpp
@@ -249,7 +249,9 @@ namespace FIFE {
 
 		IFont* font = NULL;
 		GuiFont* guifont = NULL;
-		if( bfs::extension(fontpath) == ".ttf" || bfs::extension(fontpath) == ".ttc" ) {
+                bfs::path p = fontpath;
+                std::string s = p.extension().string();
+                if( s == ".ttf" || s == ".ttc" ) {
 			font = new TrueTypeFont(fontpath, fontsize);
 		} else {
 			font = new SubImageFont(fontpath, fontglyphs);
