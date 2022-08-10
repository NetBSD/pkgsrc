$NetBSD: patch-src_xpdev_genwrap.h,v 1.1 2022/08/10 18:49:39 he Exp $

Recognize __powerpc__ as well.

--- ./src/xpdev/genwrap.h.orig	2020-06-26 23:40:21.000000000 +0000
+++ ./src/xpdev/genwrap.h
@@ -203,7 +203,7 @@ extern "C" {
 	#define ARCHITECTURE_DESC "mips"
 #elif defined(__arm__)
 	#define ARCHITECTURE_DESC "arm"
-#elif defined(_M_PPC) || defined(__ppc__)
+#elif defined(_M_PPC) || defined(__ppc__) || defined(__powerpc__)
 	#define ARCHITECTURE_DESC "ppc"
 #elif defined(_M_IA64) || defined(__ia64__)
 	#define ARCHITECTURE_DESC "ia64"
