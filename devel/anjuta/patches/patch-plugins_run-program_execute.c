$NetBSD: patch-plugins_run-program_execute.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/run-program/execute.c.orig	2013-08-09 00:30:18.000000000 +0000
+++ plugins/run-program/execute.c
@@ -58,6 +58,8 @@ struct _RunProgramChild
 /* Helper functions
  *---------------------------------------------------------------------------*/
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static gchar *
 get_local_executable (GtkWindow *parent, const gchar *uri)
 {
@@ -94,7 +96,10 @@ get_local_executable (GtkWindow *parent,
 
 	return local;
 }
+#pragma GCC diagnostic pop
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static gchar *
 get_local_directory (GtkWindow *parent, const gchar *uri)
 {
@@ -118,6 +123,7 @@ get_local_directory (GtkWindow *parent, 
 
 	return local;
 }
+#pragma GCC diagnostic pop
 
 /* Private functions
  *---------------------------------------------------------------------------*/
