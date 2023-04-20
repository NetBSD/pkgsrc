$NetBSD: patch-include_qore_macros.h,v 1.1 2023/04/20 12:48:28 nros Exp $

* Fix build on NetBSD PowerPC

--- include/qore/macros.h.orig	2023-04-16 08:58:47.680354714 +0000
+++ include/qore/macros.h
@@ -40,7 +40,7 @@
 #include <qore/macros-sparc.h>
 #elif defined(__ppc64) || defined(__ppc64__) || defined(__powerpc64__) || defined(_ARCH_PPC64) || defined(__PPC64__)
 #include <qore/macros-ppc64.h>
-#elif defined(__ppc) || defined(__ppc__)
+#elif defined(__ppc) || defined(__ppc__) || defined(__powerpc__) || defined(_ARCH_PPC) || defined(__PPC__)
 #include <qore/macros-powerpc.h>
 #elif defined(__hppa)
 #include <qore/macros-parisc.h>
