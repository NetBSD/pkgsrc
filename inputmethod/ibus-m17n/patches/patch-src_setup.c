$NetBSD: patch-src_setup.c,v 1.1 2012/11/19 23:19:30 joerg Exp $

--- src/setup.c.orig	2012-11-19 16:31:43.000000000 +0000
+++ src/setup.c
@@ -428,7 +428,7 @@ save_m17n_options (SetupDialog *dialog)
     gboolean retval = TRUE;
 
     if (!gtk_tree_model_get_iter_first (model, &iter))
-        return;
+        return FALSE;
 
     do {
         gtk_tree_model_get (model, &iter,
