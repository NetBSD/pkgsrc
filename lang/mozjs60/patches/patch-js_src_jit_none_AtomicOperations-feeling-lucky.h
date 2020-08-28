$NetBSD: patch-js_src_jit_none_AtomicOperations-feeling-lucky.h,v 1.1.2.2 2020/08/28 15:44:32 bsiegert Exp $

C++ on NetBSD/powerpc doesn't predefine __ppc__, only __powerpc__.  Compensate.

--- jit/none/AtomicOperations-feeling-lucky.h.orig	2019-07-01 09:07:41.000000000 +0000
+++ jit/none/AtomicOperations-feeling-lucky.h
@@ -39,7 +39,7 @@
 // want WebAssembly support you can always just lie about the lock-freedom.
 // After all, you're already feeling lucky.
 
-#if defined(__ppc__) || defined(__PPC__)
+#if defined(__ppc__) || defined(__PPC__) || defined(__powerpc__)
 #define GNUC_COMPATIBLE
 #endif
 
