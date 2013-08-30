$NetBSD: patch-src_filechooser.cpp,v 1.2 2013/08/30 08:14:42 obache Exp $

The key argument of std::map must not be const as it can't be assigned
internally otherwise.

--- src/filechooser.cpp.orig	2013-06-13 20:21:52.000000000 +0000
+++ src/filechooser.cpp
@@ -96,7 +96,7 @@ gui::dialog::dimension_measurements file
 	//shift the extra buttons up
 	if (show_directory_buttons_)
 	{
-		std::map<gui::dialog_button *const, std::pair<int,int> >::iterator i;
+		std::map<gui::dialog_button *, std::pair<int,int> >::iterator i;
 		for(i = dim.buttons.begin(); i != dim.buttons.end(); ++i)
 		{
 			const int btn_h = i->first->height();
