$NetBSD: patch-gtk-im_gtkimcontextgcin.c,v 1.1 2013/02/26 11:09:46 joerg Exp $

--- gtk-im/gtkimcontextgcin.c.orig	2013-02-25 18:00:04.000000000 +0000
+++ gtk-im/gtkimcontextgcin.c
@@ -321,7 +321,7 @@ gtk_im_context_xim_new (void)
 static gboolean update_cursor_position(gpointer data)
 {
   if (!context_xim_queued)
-    return;
+    return FALSE;
 
   g_signal_emit_by_name(context_xim_queued, "preedit_changed");
   context_xim_queued = NULL;
