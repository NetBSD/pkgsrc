$NetBSD: patch-plugins_am-project_projectparser.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/am-project/projectparser.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/am-project/projectparser.c
@@ -57,7 +57,7 @@ close_output (void)
 	output_stream = NULL;
 }
 
-static void
+static G_GNUC_PRINTF(1,2) void
 print (const gchar *message, ...)
 {
 	va_list args;
@@ -70,7 +70,7 @@ print (const gchar *message, ...)
 	fputc('\n', output_stream);
 }
 
-static void
+static G_GNUC_PRINTF(1,2) void
 print_error (const gchar *message, ...)
 {
 	va_list args;
