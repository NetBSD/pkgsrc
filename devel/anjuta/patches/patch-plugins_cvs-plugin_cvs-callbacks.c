$NetBSD: patch-plugins_cvs-plugin_cvs-callbacks.c,v 1.1.2.2 2016/05/11 15:33:29 bsiegert Exp $

--- plugins/cvs-plugin/cvs-callbacks.c.orig	2016-05-06 12:59:32.000000000 +0000
+++ plugins/cvs-plugin/cvs-callbacks.c
@@ -149,7 +149,7 @@ on_cvs_remove_response(GtkDialog* dialog
 		if (!g_file_delete(file, NULL, NULL))
 		{
 			anjuta_util_dialog_error
-				(GTK_WINDOW(dialog),_("Unable to delete file"), NULL);
+				(GTK_WINDOW(dialog),_("Unable to delete file"));
 			gtk_widget_destroy(GTK_WIDGET(dialog));
 			cvs_data_free(data);
 			break;
