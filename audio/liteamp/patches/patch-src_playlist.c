$NetBSD: patch-src_playlist.c,v 1.1 2012/07/03 18:20:29 joerg Exp $

--- src/playlist.c.orig	2012-07-03 15:28:01.000000000 +0000
+++ src/playlist.c
@@ -507,7 +507,7 @@ gboolean playlist_show_dialog(Playlist* 
     GtkTreeIter iter;
     GtkTreePath* path;
 
-    g_return_if_fail(IS_PLAYLIST(pl));
+    g_return_val_if_fail(IS_PLAYLIST(pl), FALSE);
 
     // get the focused row to show properties
     gtk_tree_view_get_cursor(GTK_TREE_VIEW(pl), &path, NULL);
@@ -727,6 +727,7 @@ gboolean playlist_show_dialog(Playlist* 
     }
 
     gtk_widget_destroy(dlg);
+    return FALSE;
 }
 
 /*-----------------------------------------------------------------*/
@@ -1189,7 +1190,7 @@ gchar* playlist_get_current_file(Playlis
     GtkTreeIter iter;
     gchar* filename;
 
-    g_return_if_fail(IS_PLAYLIST(pl));
+    g_return_val_if_fail(IS_PLAYLIST(pl), NULL);
 
     if(!playlist_get_current_row(pl, &iter)) return NULL;
 
