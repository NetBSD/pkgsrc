$NetBSD: patch-pan_gui_e-cte-dialog.c,v 1.1 2012/04/09 23:00:49 wiz Exp $

Non-void function needs return value.

--- pan/gui/e-cte-dialog.c.orig	2012-04-08 15:30:36.000000000 +0000
+++ pan/gui/e-cte-dialog.c
@@ -128,7 +128,7 @@ e_cte_dialog (const char *title, const c
     GMimeContentEncoding value;
 
     if (!gtk_combo_box_get_active_iter (GTK_COMBO_BOX(picker), &iter))
-      return;
+      return GMIME_CONTENT_ENCODING_DEFAULT;
 
     model = gtk_combo_box_get_model (GTK_COMBO_BOX(picker));
     gtk_tree_model_get (model, &iter, 1, &value, -1);
