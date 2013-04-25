$NetBSD: patch-glib_gstrfuncs.c,v 1.1 2013/04/25 12:10:48 joerg Exp $

--- glib/gstrfuncs.c.orig	2013-04-23 20:34:39.000000000 +0000
+++ glib/gstrfuncs.c
@@ -892,6 +892,8 @@ g_ascii_dtostr (gchar       *buffer,
  *
  * Return value: The pointer to the buffer with the converted string.
  */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 gchar *
 g_ascii_formatd (gchar       *buffer,
                  gint         buf_len,
@@ -974,6 +976,7 @@ g_ascii_formatd (gchar       *buffer,
   return buffer;
 #endif
 }
+#pragma GCC diagnostic pop
 
 #define ISSPACE(c)              ((c) == ' ' || (c) == '\f' || (c) == '\n' || \
                                  (c) == '\r' || (c) == '\t' || (c) == '\v')
