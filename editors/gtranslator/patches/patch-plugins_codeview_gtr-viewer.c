$NetBSD: patch-plugins_codeview_gtr-viewer.c,v 1.1 2014/02/21 20:24:45 joerg Exp $

--- plugins/codeview/gtr-viewer.c.orig	2014-02-21 00:22:29.000000000 +0000
+++ plugins/codeview/gtr-viewer.c
@@ -143,7 +143,7 @@ gtr_viewer_class_init (GtrViewerClass * 
 
 /***************** File loading *****************/
 
-static void
+static G_GNUC_PRINTF(2, 3) void
 error_dialog (GtkWindow * parent, const gchar * msg, ...)
 {
   va_list ap;
