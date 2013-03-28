$NetBSD: patch-src_filebrowser.c,v 1.1 2013/03/28 21:39:32 joerg Exp $

--- src/filebrowser.c.orig	2013-03-28 20:32:19.000000000 +0000
+++ src/filebrowser.c
@@ -1193,13 +1193,13 @@ gboolean update_folder_view_visible_regi
   if( data->view_mode == FBVM_ICON_VIEW ) {
     if( !ptk_icon_view_get_visible_range ( PTK_ICON_VIEW(folder_view),
                                            &start_path, &end_path ) )
-        return;
+        return FALSE;
     model = ptk_icon_view_get_model( PTK_ICON_VIEW(folder_view) );
   }
   else if( data->view_mode == FBVM_LIST_VIEW ) {
     if( !gtk_tree_view_get_visible_range ( GTK_TREE_VIEW(folder_view),
                                            &start_path, &end_path ) )
-      return;
+      return FALSE;
     model = gtk_tree_view_get_model( GTK_TREE_VIEW(folder_view) );
   }
 
@@ -1216,7 +1216,7 @@ gboolean update_folder_view_visible_regi
       gtk_tree_path_free( start_path );
     if( end_path )
       gtk_tree_path_free( end_path );
-    return;
+    return FALSE;
   }
 
   model_sorter = PTK_TREE_MODEL_SORT( gtk_tree_model_filter_get_model(
