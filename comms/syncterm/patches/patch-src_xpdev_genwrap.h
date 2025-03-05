$NetBSD: patch-src_xpdev_genwrap.h,v 1.2 2025/03/05 18:21:22 vins Exp $

* Recognize __powerpc__ as well.
* ARCHITECTURE_DESC is unused, no need to error out for that.

--- src/xpdev/genwrap.h.orig	2025-02-11 18:23:24.000000000 +0000
+++ src/xpdev/genwrap.h
@@ -218,7 +218,7 @@ extern "C" {
 	#define ARCHITECTURE_DESC "arm64"
 #elif defined(__arm__)
 	#define ARCHITECTURE_DESC "arm"
-#elif defined(_M_PPC) || defined(__ppc__)
+#elif defined(_M_PPC) || defined(__ppc__) || defined(__powerpc__)
 	#define ARCHITECTURE_DESC "ppc"
 #elif defined(_M_IA64) || defined(__ia64__)
 	#define ARCHITECTURE_DESC "ia64"
@@ -228,7 +228,7 @@ extern "C" {
 	#ifdef UNAME_ARCHITECTURE_DESC
 		#define ARCHITECTURE_DESC UNAME_ARCHITECTURE_DESC
 	#else
-		#error "Need to describe target architecture"
+		#define ARCHITECTURE_DESC "unknown"
 	#endif
 #endif
 
