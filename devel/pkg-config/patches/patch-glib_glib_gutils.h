$NetBSD: patch-glib_glib_gutils.h,v 1.1 2013/04/13 11:10:05 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/gutils.h.orig	2012-10-13 14:35:36.000000000 +0000
+++ glib/glib/gutils.h
@@ -342,7 +342,7 @@ G_END_DECLS
  * On non-Windows platforms, expands to nothing.
  */
 
-#ifndef G_PLATFORM_WIN32
+#ifndef G_OS_WIN32
 # define G_WIN32_DLLMAIN_FOR_DLL_NAME(static, dll_name)
 #else
 # define G_WIN32_DLLMAIN_FOR_DLL_NAME(static, dll_name)			\
@@ -370,6 +370,6 @@ DllMain (HINSTANCE hinstDLL,						\
 
 #endif	/* !G_DISABLE_DEPRECATED */
 
-#endif /* G_PLATFORM_WIN32 */
+#endif /* G_OS_WIN32 */
 
 #endif /* __G_UTILS_H__ */
