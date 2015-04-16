$NetBSD: patch-storage_tokudb_ft-index_portability_toku__pthread.cc,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- storage/tokudb/ft-index/portability/toku_pthread.cc.orig	2015-02-13 12:07:05.000000000 +0000
+++ storage/tokudb/ft-index/portability/toku_pthread.cc
@@ -91,6 +91,9 @@ PATENT RIGHTS GRANT:
 #define _GNU_SOURCE 1
 #include <portability/toku_config.h>
 #include <toku_pthread.h>
+#if defined(__NetBSD__)
+#include <sched.h>
+#endif
 
 int toku_pthread_yield(void) {
 #if defined(HAVE_PTHREAD_YIELD)
@@ -102,6 +105,8 @@ int toku_pthread_yield(void) {
 # else
 #  error "don't know what pthread_yield() returns"
 # endif
+#elif defined(__NetBSD__)
+    return sched_yield();
 #elif defined(HAVE_PTHREAD_YIELD_NP)
     pthread_yield_np();
     return 0;
