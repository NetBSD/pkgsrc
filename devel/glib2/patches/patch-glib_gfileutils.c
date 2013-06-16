$NetBSD: patch-glib_gfileutils.c,v 1.3 2013/06/16 20:37:07 joerg Exp $

--- glib/gfileutils.c.orig	2013-06-09 22:15:54.000000000 +0000
+++ glib/gfileutils.c
@@ -1009,6 +1009,8 @@ rename_file (const char  *old_name,
  *   - the place for the filename
  *   - the place for the strerror
  */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static void
 format_error_message (GError      **error,
                       const gchar  *filename,
@@ -1024,6 +1026,7 @@ format_error_message (GError      **erro
 
   g_free (display_name);
 }
+#pragma GCC diagnostic pop
 
 static gchar *
 write_to_temp_file (const gchar  *contents,
