$NetBSD: patch-gnuradio-runtime_lib_thread_thread.cc,v 1.1 2023/07/07 12:20:59 jperkin Exp $

Fix SunOS build.

--- gnuradio-runtime/lib/thread/thread.cc.orig	2023-04-01 10:49:26.000000000 +0000
+++ gnuradio-runtime/lib/thread/thread.cc
@@ -135,7 +135,7 @@ void set_thread_name(gr_thread_t thread,
 
 #elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) ||     \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || \
-    defined(__NetBSD__)
+    defined(__NetBSD__) || defined(__sun)
 
 namespace gr {
 namespace thread {
