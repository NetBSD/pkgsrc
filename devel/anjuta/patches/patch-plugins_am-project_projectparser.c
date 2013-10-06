$NetBSD: patch-plugins_am-project_projectparser.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/am-project/projectparser.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/am-project/projectparser.c
@@ -58,7 +58,7 @@ close_output (void)
 }
 
 static void
-print (const gchar *message, ...)
+print (const gchar *message, ...) G_GNUC_PRINTF(1,2)
 {
 	va_list args;
 
@@ -71,7 +71,7 @@ print (const gchar *message, ...)
 }
 
 static void
-print_error (const gchar *message, ...)
+print_error (const gchar *message, ...) G_GNUC_PRINTF(1,2)
 {
 	va_list args;
 
