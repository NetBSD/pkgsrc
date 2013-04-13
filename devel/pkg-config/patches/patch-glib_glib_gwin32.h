$NetBSD: patch-glib_glib_gwin32.h,v 1.1 2013/04/13 11:10:05 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/gwin32.h.orig	2012-10-02 05:49:07.000000000 +0000
+++ glib/glib/gwin32.h
@@ -33,7 +33,7 @@
 
 #include <glib/gtypes.h>
 
-#ifdef G_PLATFORM_WIN32
+#ifdef G_OS_WIN32
 
 G_BEGIN_DECLS
 
@@ -41,8 +41,6 @@ G_BEGIN_DECLS
 #define MAXPATHLEN 1024
 #endif
 
-#ifdef G_OS_WIN32
-
 /*
  * To get prototypes for the following POSIXish functions, you have to
  * include the indicated non-POSIX headers. The functions are defined
@@ -67,7 +65,6 @@ G_BEGIN_DECLS
  */
 gint		g_win32_ftruncate	(gint		 f,
 					 guint		 size);
-#endif /* G_OS_WIN32 */
 
 /* The MS setlocale uses locale names of the form "English_United
  * States.1252" etc. We want the Unixish standard form "en", "zh_TW"
@@ -113,6 +110,6 @@ gchar*          g_win32_locale_filename_
 
 G_END_DECLS
 
-#endif	 /* G_PLATFORM_WIN32 */
+#endif	 /* G_OS_WIN32 */
 
 #endif /* __G_WIN32_H__ */
