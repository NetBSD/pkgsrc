$NetBSD: patch-js_src_jit_AtomicOperations.h,v 1.1.2.2 2020/08/28 15:44:32 bsiegert Exp $

Oddly, C++ on NetBSD/powerpc doesn't predefine __ppc__, only __powerpc__.

--- jit/AtomicOperations.h.orig	2019-07-01 09:07:41.000000000 +0000
+++ jit/AtomicOperations.h
@@ -378,7 +378,7 @@ inline bool AtomicOperations::isLockfree
 #else
 #error "No AtomicOperations support for this platform+compiler combination"
 #endif
-#elif defined(__ppc__) || defined(__PPC__)
+#elif defined(__ppc__) || defined(__PPC__) || defined(__powerpc__)
 #include "jit/none/AtomicOperations-feeling-lucky.h"
 #elif defined(__sparc__)
 #include "jit/none/AtomicOperations-feeling-lucky.h"
