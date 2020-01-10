$NetBSD: patch-libbrasero-media_brasero-media.c,v 1.1 2020/01/10 21:18:21 joerg Exp $

Format string is prefixed.

--- libbrasero-media/brasero-media.c.orig	2020-01-08 23:19:00.665788197 +0000
+++ libbrasero-media/brasero-media.c
@@ -482,6 +482,9 @@ brasero_media_get_option_group (void)
 	return group;
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
+
 void
 brasero_media_message (const gchar *location,
 		       const gchar *format,
@@ -504,6 +507,8 @@ brasero_media_message (const gchar *loca
 	g_free (format_real);
 }
 
+#pragma GCC diagnostic pop
+
 #include <gtk/gtk.h>
 
 #include "brasero-medium-monitor.h"
