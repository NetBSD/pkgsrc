$NetBSD: patch-src_afl-cc.c,v 1.1 2025/10/25 13:57:41 kikadf Exp $

* On NetBSD link with libexecinfo on runtime

--- src/afl-cc.c.orig	2025-10-19 13:59:11.282415885 +0000
+++ src/afl-cc.c
@@ -2564,6 +2564,11 @@ void add_runtime(aflcc_state_t *aflcc) {
   insert_param(aflcc, "-Wl,-lrt");
 #endif
 
+#if defined(__NetBSD__)
+  // Required for backtrace used in afl-compiler-rt.o
+  insert_param(aflcc, "-lexecinfo");
+#endif
+
 }
 
 /** Linking behaviors -----END----- **/
