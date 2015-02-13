$NetBSD: patch-src_lib_platform_posix_os-types.h,v 1.1 2015/02/13 11:12:23 jmcneill Exp $

--- src/lib/platform/posix/os-types.h.orig	2014-10-31 19:11:22.000000000 +0000
+++ src/lib/platform/posix/os-types.h
@@ -36,7 +36,7 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/time.h>
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/prctl.h>
 #endif
 #include <pthread.h>
