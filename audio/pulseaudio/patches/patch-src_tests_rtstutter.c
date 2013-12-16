$NetBSD: patch-src_tests_rtstutter.c,v 1.1 2013/12/16 19:00:03 asau Exp $

--- src/tests/rtstutter.c.orig	2011-09-26 15:51:42.000000000 +0000
+++ src/tests/rtstutter.c	2013-09-26 00:28:11.949504937 +0000
@@ -32,6 +32,11 @@
 #include <pthread.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/cpuset.h>
+#endif
+
 #include <pulse/util.h>
 #include <pulse/timeval.h>
 #include <pulse/gccmacro.h>
@@ -54,7 +59,11 @@
 
 #ifdef HAVE_PTHREAD_SETAFFINITY_NP
 {
+#if defined(__FreeBSD__)
+    cpuset_t mask;
+#else
     cpu_set_t mask;
+#endif
 
     CPU_ZERO(&mask);
     CPU_SET((size_t) PA_PTR_TO_UINT(p), &mask);
