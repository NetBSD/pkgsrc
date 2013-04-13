$NetBSD: patch-glib_glib_gconvert.c,v 1.1 2013/04/13 11:10:04 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/gconvert.c.orig	2012-10-02 05:49:07.000000000 +0000
+++ glib/glib/gconvert.c
@@ -33,9 +33,6 @@
 
 #ifdef G_OS_WIN32
 #include "win_iconv.c"
-#endif
-
-#ifdef G_PLATFORM_WIN32
 #define STRICT
 #include <windows.h>
 #undef STRICT
@@ -1262,7 +1259,7 @@ g_locale_from_utf8 (const gchar *utf8str
 		      charset, "UTF-8", bytes_read, bytes_written, error);
 }
 
-#ifndef G_PLATFORM_WIN32
+#ifndef G_OS_WIN32
 
 typedef struct _GFilenameCharsetCache GFilenameCharsetCache;
 
@@ -1378,7 +1375,7 @@ g_get_filename_charsets (const gchar ***
   return cache->is_utf8;
 }
 
-#else /* G_PLATFORM_WIN32 */
+#else /* G_OS_WIN32 */
 
 gboolean
 g_get_filename_charsets (const gchar ***filename_charsets) 
@@ -1407,7 +1404,7 @@ g_get_filename_charsets (const gchar ***
 #endif
 }
 
-#endif /* G_PLATFORM_WIN32 */
+#endif /* G_OS_WIN32 */
 
 static gboolean
 get_filename_charset (const gchar **filename_charset)
