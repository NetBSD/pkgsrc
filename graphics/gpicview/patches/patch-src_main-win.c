$NetBSD: patch-src_main-win.c,v 1.1 2014/11/17 19:03:10 joerg Exp $

--- src/main-win.c.orig	2014-11-16 15:22:49.000000000 +0000
+++ src/main-win.c
@@ -378,7 +378,7 @@ gboolean main_win_open( MainWin* mw, con
         image_list_sort_by_name( mw->img_list, GTK_SORT_DESCENDING );
         if (image_list_get_first(mw->img_list))
             main_win_open(mw, image_list_get_current_file_path(mw->img_list), zoom);
-        return;
+        return FALSE;
     }
 
 
