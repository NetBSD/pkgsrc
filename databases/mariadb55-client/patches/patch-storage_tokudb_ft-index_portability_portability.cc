$NetBSD: patch-storage_tokudb_ft-index_portability_portability.cc,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- storage/tokudb/ft-index/portability/portability.cc.orig	2015-02-13 12:07:05.000000000 +0000
+++ storage/tokudb/ft-index/portability/portability.cc
@@ -130,6 +130,9 @@ PATENT RIGHTS GRANT:
 #include "memory.h"
 #include <portability/toku_atomic.h>
 #include <util/partitioned_counter.h>
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
 
 int
 toku_portability_init(void) {
@@ -160,6 +163,8 @@ toku_os_gettid(void) {
     return syscall(SYS_gettid);
 #elif defined(HAVE_PTHREAD_GETTHREADID_NP)
     return pthread_getthreadid_np();
+#elif defined(__NetBSD__)
+    return (int)_lwp_self();
 #else
 # error "no implementation of gettid available"
 #endif
