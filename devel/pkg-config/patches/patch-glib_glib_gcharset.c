$NetBSD: patch-glib_glib_gcharset.c,v 1.1 2013/04/13 11:10:04 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/gcharset.c.orig	2012-10-02 05:49:07.000000000 +0000
+++ glib/glib/gcharset.c
@@ -496,7 +496,7 @@ guess_category_value (const gchar *categ
   if ((retval != NULL) && (retval[0] != '\0'))
     return retval;
 
-#ifdef G_PLATFORM_WIN32
+#ifdef G_OS_WIN32
   /* g_win32_getlocale() first checks for LC_ALL, LC_MESSAGES and
    * LANG, which we already did above. Oh well. The main point of
    * calling g_win32_getlocale() is to get the thread's locale as used
