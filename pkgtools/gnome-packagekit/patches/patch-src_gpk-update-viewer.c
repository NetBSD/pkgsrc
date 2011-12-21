$NetBSD: patch-src_gpk-update-viewer.c,v 1.1 2011/12/21 12:12:53 wiz Exp $

Fix type, error with gcc-4.5.

--- src/gpk-update-viewer.c.orig	2008-11-24 16:34:22.000000000 +0000
+++ src/gpk-update-viewer.c
@@ -1517,7 +1517,7 @@ gpk_update_viewer_detail_popup_menu_sele
 	gboolean valid;
 	GtkTreeIter iter;
 	GtkTreeModel *model;
-	PkStatusEnum info;
+	PkInfoEnum info;
 
 	/* get the first iter in the list */
 	model = gtk_tree_view_get_model (treeview);
