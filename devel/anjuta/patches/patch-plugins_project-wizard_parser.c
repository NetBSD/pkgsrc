$NetBSD: patch-plugins_project-wizard_parser.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/project-wizard/parser.c.orig	2013-08-09 00:30:18.000000000 +0000
+++ plugins/project-wizard/parser.c
@@ -254,8 +254,10 @@ parser_error_quark (void)
 	return error_quark;
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static void
-parser_warning (GMarkupParseContext* ctx, const gchar* format,...)
+G_GNUC_PRINTF(2,3) parser_warning (GMarkupParseContext* ctx, const gchar* format,...)
 {
 	va_list args;
 	gchar* msg;
@@ -268,8 +270,11 @@ parser_warning (GMarkupParseContext* ctx
 	va_end (args);
 	g_free (msg);
 }
+#pragma GCC diagnostic pop
 
-static void
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
+static G_GNUC_PRINTF(2,3) void
 parser_critical (GMarkupParseContext* ctx, const gchar* format,...)
 {
 	va_list args;
@@ -283,6 +288,7 @@ parser_critical (GMarkupParseContext* ct
 	va_end (args);
 	g_free (msg);
 }
+#pragma GCC diagnostic pop
 
 /* Represent a language as an integer:
  * < 0 for a not applicable language
