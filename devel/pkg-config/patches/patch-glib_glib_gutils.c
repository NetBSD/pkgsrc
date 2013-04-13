$NetBSD: patch-glib_glib_gutils.c,v 1.1 2013/04/13 11:10:05 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/gutils.c.orig	2012-10-13 14:35:36.000000000 +0000
+++ glib/glib/gutils.c
@@ -71,7 +71,7 @@
 #include "garray.h"
 #include "glibintl.h"
 
-#ifdef G_PLATFORM_WIN32
+#ifdef G_OS_WIN32
 #include "gconvert.h"
 #include "gwin32.h"
 #endif
@@ -85,16 +85,13 @@
  * These are portable utility functions.
  */
 
-#ifdef G_PLATFORM_WIN32
+#ifdef G_OS_WIN32
 #  include <windows.h>
 #  ifndef GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
 #    define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT 2
 #    define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS 4
 #  endif
 #  include <lmcons.h>		/* For UNLEN */
-#endif /* G_PLATFORM_WIN32 */
-
-#ifdef G_OS_WIN32
 #  include <direct.h>
 #  include <shlobj.h>
    /* older SDK (e.g. msvc 5.0) does not have these*/
@@ -130,7 +127,7 @@
 #include <langinfo.h>
 #endif
 
-#ifdef G_PLATFORM_WIN32
+#ifdef G_OS_WIN32
 
 gchar *
 _glib_get_dll_directory (void)
