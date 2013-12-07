$NetBSD: patch-plugins_tools_fileop.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/tools/fileop.c.orig	2013-08-09 00:30:18.000000000 +0000
+++ plugins/tools/fileop.c
@@ -158,6 +158,8 @@ parse_integer_string (const gchar* value
 	return atoi(value);
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static void
 parser_warning (GMarkupParseContext* ctx, const gchar* format,...)
 {
@@ -172,6 +174,7 @@ parser_warning (GMarkupParseContext* ctx
 	va_end (args);
 	g_free (msg);
 }
+#pragma GCC diagnostic pop
 
 /* Load anjuta-tools
  *---------------------------------------------------------------------------*/
