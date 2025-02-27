$NetBSD: patch-gnuradio-runtime_lib_thread_thread.cc,v 1.2 2025/02/27 13:49:51 adam Exp $

Fix SunOS build.

--- gnuradio-runtime/lib/thread/thread.cc.orig	2025-02-20 01:23:56.000000000 +0000
+++ gnuradio-runtime/lib/thread/thread.cc
@@ -19,7 +19,7 @@
 #include <windows.h>
 #elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) ||     \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || \
-    defined(__NetBSD__) || defined(__OpenBSD__)
+    defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
 #define __GR_TARGET_BSD__
 #include <pthread.h>
 #ifdef __OpenBSD__
