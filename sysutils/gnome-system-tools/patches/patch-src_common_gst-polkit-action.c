$NetBSD: patch-src_common_gst-polkit-action.c,v 1.1 2012/01/20 17:01:07 joerg Exp $

--- src/common/gst-polkit-action.c.orig	2012-01-18 23:58:45.000000000 +0000
+++ src/common/gst-polkit-action.c
@@ -378,7 +378,7 @@ gst_polkit_action_authenticate (GstPolKi
 	GtkWidget *toplevel;
 	guint32 xid;
 
-	g_return_if_fail (GST_IS_POLKIT_ACTION (action));
+	g_return_val_if_fail (GST_IS_POLKIT_ACTION (action), FALSE);
 
 	priv = GST_POLKIT_ACTION_GET_PRIVATE (action);
 	xid = 0;
