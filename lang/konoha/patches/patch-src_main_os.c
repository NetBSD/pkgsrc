$NetBSD: patch-src_main_os.c,v 1.1 2012/08/07 16:06:06 ryoon Exp $

* Fix include order

--- src/main/os.c.orig	2012-03-07 06:52:15.000000000 +0000
+++ src/main/os.c
@@ -27,6 +27,11 @@
 
 /* ************************************************************************ */
 
+#ifdef K_USING_POSIX_
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif/*K_USING_POSIX_*/
+
 #include"commons.h"
 
 #ifdef K_USING_POSIX_
@@ -35,8 +40,6 @@
 #include <dlfcn.h>
 #include <time.h>
 #include <sys/time.h>
-#include <sys/param.h>
-#include <sys/sysctl.h>
 #ifdef K_USING_MACOSX_
 #include <mach-o/dyld.h>
 #endif
