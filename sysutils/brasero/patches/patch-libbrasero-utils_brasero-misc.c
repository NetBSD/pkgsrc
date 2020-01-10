$NetBSD: patch-libbrasero-utils_brasero-misc.c,v 1.1 2020/01/10 21:18:21 joerg Exp $

Format string is prefixed.

--- libbrasero-utils/brasero-misc.c.orig	2020-01-08 23:06:39.255722394 +0000
+++ libbrasero-utils/brasero-misc.c
@@ -96,6 +96,9 @@ brasero_utils_get_option_group (void)
 	return group;
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
+
 void
 brasero_utils_debug_message (const gchar *location,
 			     const gchar *format,
@@ -117,6 +120,7 @@ brasero_utils_debug_message (const gchar
 
 	g_free (format_real);
 }
+#pragma GCC diagnostic pop
 
 static gboolean
 brasero_utils_clear_strings_cb (gchar *string,
