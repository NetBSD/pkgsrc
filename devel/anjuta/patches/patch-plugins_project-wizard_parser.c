$NetBSD: patch-plugins_project-wizard_parser.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/project-wizard/parser.c.orig	2013-08-09 00:30:18.000000000 +0000
+++ plugins/project-wizard/parser.c
@@ -255,7 +255,7 @@ parser_error_quark (void)
 }
 
 static void
-parser_warning (GMarkupParseContext* ctx, const gchar* format,...)
+parser_warning (GMarkupParseContext* ctx, const gchar* format,...) G_GNUC_PRINTF(2,3)
 {
 	va_list args;
 	gchar* msg;
@@ -264,13 +264,16 @@ parser_warning (GMarkupParseContext* ctx
 	g_markup_parse_context_get_position (ctx, &line, NULL);
 	msg = g_strdup_printf ("line %d: %s", line, format);
 	va_start (args, format);
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 	g_logv (G_LOG_DOMAIN, G_LOG_LEVEL_WARNING, msg, args);
+#pragma GCC diagnostic pop
 	va_end (args);
 	g_free (msg);
 }
 
 static void
-parser_critical (GMarkupParseContext* ctx, const gchar* format,...)
+parser_critical (GMarkupParseContext* ctx, const gchar* format,...) G_GNUC_PRINTF(2,3)
 {
 	va_list args;
 	gchar* msg;
@@ -279,7 +282,10 @@ parser_critical (GMarkupParseContext* ct
 	g_markup_parse_context_get_position (ctx, &line, NULL);
 	msg = g_strdup_printf ("line %d: %s", line, format);
 	va_start (args, format);
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 	g_logv (G_LOG_DOMAIN, G_LOG_LEVEL_CRITICAL, msg, args);
+#pragma GCC diagnostic pop
 	va_end (args);
 	g_free (msg);
 }
