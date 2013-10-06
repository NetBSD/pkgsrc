$NetBSD: patch-plugins_run-program_execute.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/run-program/execute.c.orig	2013-09-29 15:13:14.000000000 +0000
+++ plugins/run-program/execute.c
@@ -87,7 +87,10 @@ get_local_executable (GtkWindow *parent,
 
 	if (err_msg)
 	{
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 		anjuta_util_dialog_error (parent, err_msg, local == NULL ? uri : local);
+#pragma GCC diagnostic pop
 		g_free (local);
 		local = NULL;
 	}
@@ -113,7 +116,10 @@ get_local_directory (GtkWindow *parent, 
 
 	if (err_msg)
 	{
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 		anjuta_util_dialog_error (parent, err_msg, uri);
+#pragma GCC diagnostic pop
 	}
 
 	return local;
