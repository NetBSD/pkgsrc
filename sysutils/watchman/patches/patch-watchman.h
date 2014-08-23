$NetBSD: patch-watchman.h,v 1.1 2014/08/23 20:13:59 wiz Exp $
* NetBSD bfore 6.99 uses BSD-style subsecond timespec
https://github.com/facebook/watchman/pull/54
--- watchman.h.orig	2014-05-20 21:14:24.000000000 +0000
+++ watchman.h	2014-08-22 11:54:55.000000000 +0000
@@ -62,6 +62,9 @@
 #include <sysexits.h>
 #include <spawn.h>
 #include <stddef.h>
+#ifdef HAVE_SYS_PARAM_H
+# include <sys/param.h>
+#endif
 // Not explicitly exported on Darwin, so we get to define it.
 extern char **environ;
 
@@ -575,7 +578,7 @@
 #define WATCHMAN_NSEC_IN_SEC (1000 * 1000 * 1000)
 #define WATCHMAN_NSEC_IN_MSEC 1000000
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || (defined(__NetBSD__) && (__NetBSD_Version__ < 6099000000))
 /* BSD-style subsecond timespec */
 #define WATCHMAN_ST_TIMESPEC(type) st_##type##timespec
 #else
