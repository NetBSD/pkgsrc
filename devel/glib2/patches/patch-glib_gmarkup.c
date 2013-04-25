$NetBSD: patch-glib_gmarkup.c,v 1.1 2013/04/25 12:10:48 joerg Exp $

--- glib/gmarkup.c.orig	2013-04-23 20:29:01.000000000 +0000
+++ glib/gmarkup.c
@@ -2366,6 +2366,9 @@ find_conversion (const char  *format,
  *
  * Since: 2.4
  */
+
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 gchar *
 g_markup_vprintf_escaped (const gchar *format,
                           va_list      args)
@@ -2437,6 +2440,7 @@ g_markup_vprintf_escaped (const gchar *f
     }
 
   output2 = g_strdup_vprintf (format2->str, args2);
+
   va_end (args2);
   if (!output2)
     goto cleanup;
@@ -2491,6 +2495,7 @@ g_markup_vprintf_escaped (const gchar *f
   else
     return NULL;
 }
+#pragma GCC diagnostic pop
 
 /**
  * g_markup_printf_escaped:
