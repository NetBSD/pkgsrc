$NetBSD: patch-plugins_tools_fileop.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/tools/fileop.c.orig	2013-09-29 15:21:52.000000000 +0000
+++ plugins/tools/fileop.c
@@ -168,7 +168,10 @@ parser_warning (GMarkupParseContext* ctx
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
