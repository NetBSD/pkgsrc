$NetBSD: patch-plugins_project-manager_dialogs.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/project-manager/dialogs.c.orig	2013-08-09 00:30:18.000000000 +0000
+++ plugins/project-manager/dialogs.c
@@ -118,7 +118,7 @@ load_interface (const gchar *top_widget)
     return xml;
 }
 
-static void
+static G_GNUC_PRINTF(3,4) void
 error_dialog (GtkWindow *parent, const gchar *summary, const gchar *msg, ...)
 {
     va_list ap;
