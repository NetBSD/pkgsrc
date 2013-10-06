$NetBSD: patch-plugins_project-manager_dialogs.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/project-manager/dialogs.c.orig	2013-08-09 00:30:18.000000000 +0000
+++ plugins/project-manager/dialogs.c
@@ -119,7 +119,7 @@ load_interface (const gchar *top_widget)
 }
 
 static void
-error_dialog (GtkWindow *parent, const gchar *summary, const gchar *msg, ...)
+error_dialog (GtkWindow *parent, const gchar *summary, const gchar *msg, ...) G_GNUC_PRINTF(3,4)
 {
     va_list ap;
     gchar *tmp;
