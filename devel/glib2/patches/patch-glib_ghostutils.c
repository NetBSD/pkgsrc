$NetBSD: patch-glib_ghostutils.c,v 1.1 2021/03/31 09:59:43 jperkin Exp $

Test G_OS_UNIX after it has been defined.

--- glib/ghostutils.c.orig	2021-03-18 13:28:31.903625000 +0000
+++ glib/ghostutils.c
@@ -21,10 +21,6 @@
 
 #include <string.h>
 
-#ifdef G_OS_UNIX
-#include <unistd.h>
-#endif
-
 #include "ghostutils.h"
 
 #include "garray.h"
@@ -33,6 +29,10 @@
 #include "gstrfuncs.h"
 #include "glibintl.h"
 
+#ifdef G_OS_UNIX
+#include <unistd.h>
+#endif
+
 #ifdef G_PLATFORM_WIN32
 #include <windows.h>
 #endif
