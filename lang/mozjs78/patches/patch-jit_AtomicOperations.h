$NetBSD: patch-jit_AtomicOperations.h,v 1.1 2020/11/28 10:54:55 nia Exp $

C++ on NetBSD/powerpc doesn't predefine __ppc__, only __powerpc__.  Compensate.

--- jit/AtomicOperations.h.orig	2020-11-04 10:51:58.000000000 +0000
+++ jit/AtomicOperations.h
@@ -391,7 +391,8 @@ inline bool AtomicOperations::isLockfree
 #elif defined(__ppc__) || defined(__PPC__) || defined(__sparc__) ||     \
     defined(__ppc64__) || defined(__PPC64__) || defined(__ppc64le__) || \
     defined(__PPC64LE__) || defined(__alpha__) || defined(__hppa__) ||  \
-    defined(__sh__) || defined(__s390__) || defined(__s390x__)
+    defined(__sh__) || defined(__s390__) || defined(__s390x__) ||       \
+    defined(__powerpc__)
 #  include "jit/shared/AtomicOperations-feeling-lucky.h"
 #else
 #  error "No AtomicOperations support provided for this platform"
