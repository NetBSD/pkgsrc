$NetBSD: patch-glib_gfileutils.c,v 1.1 2013/06/15 19:18:26 adam Exp $

--- glib/gfileutils.c.orig	2013-06-15 18:55:06.000000000 +0000
+++ glib/gfileutils.c
@@ -1019,8 +1019,11 @@ format_error_message (GError      **erro
 
   display_name = g_filename_display_name (filename);
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
   g_set_error (error, G_FILE_ERROR, g_file_error_from_errno (saved_errno),
                format_string, display_name, g_strerror (saved_errno));
+#pragma GCC diagnostic pop
 
   g_free (display_name);
 }
