$NetBSD: patch-src_main-win.c,v 1.2 2016/05/22 19:38:24 youri Exp $

Fix build.

--- src/main-win.c.orig	2014-11-16 15:22:49.000000000 +0000
+++ src/main-win.c
@@ -378,7 +378,7 @@ gboolean main_win_open( MainWin* mw, con
         image_list_sort_by_name( mw->img_list, GTK_SORT_DESCENDING );
         if (image_list_get_first(mw->img_list))
             main_win_open(mw, image_list_get_current_file_path(mw->img_list), zoom);
-        return;
+        return FALSE;
     }
 
 
