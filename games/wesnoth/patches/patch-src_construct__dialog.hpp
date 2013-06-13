$NetBSD: patch-src_construct__dialog.hpp,v 1.1 2013/06/13 21:41:48 joerg Exp $

--- src/construct_dialog.hpp.orig	2013-06-13 20:18:13.000000000 +0000
+++ src/construct_dialog.hpp
@@ -190,11 +190,11 @@ public:
 		int x, y;
 		SDL_Rect interior, message, textbox;
 		unsigned int menu_width;
-		std::map<preview_pane *const, SDL_Rect > panes;
+		std::map<preview_pane *, SDL_Rect > panes;
 		int label_x, label_y;
 		int menu_x, menu_y, menu_height;
 		int image_x, image_y, caption_x, caption_y;
-		std::map<dialog_button *const, std::pair<int,int> > buttons;
+		std::map<dialog_button *, std::pair<int,int> > buttons;
 		//use get_frame().get_layout() to check frame dimensions
 	};
 	typedef dialog_frame::style style;
