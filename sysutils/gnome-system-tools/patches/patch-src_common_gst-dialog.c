$NetBSD: patch-src_common_gst-dialog.c,v 1.1 2012/01/20 17:01:07 joerg Exp $

--- src/common/gst-dialog.c.orig	2012-01-18 23:57:08.000000000 +0000
+++ src/common/gst-dialog.c
@@ -449,7 +449,7 @@ gst_dialog_get_freeze_level (GstDialog *
 {
 	GstDialogPrivate *priv;
 
-	g_return_if_fail (GST_IS_DIALOG (dialog));
+	g_return_val_if_fail (GST_IS_DIALOG (dialog), 0);
 
 	priv = GST_DIALOG_GET_PRIVATE (dialog);
 	return priv->frozen;
