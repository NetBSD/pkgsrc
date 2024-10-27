$NetBSD: patch-src_include_thirdparty_sgi__arcbios.h,v 1.1 2024/10/27 20:01:43 jakllsch Exp $

--- src/include/thirdparty/sgi_arcbios.h.orig	2024-10-27 19:49:27.530179015 +0000
+++ src/include/thirdparty/sgi_arcbios.h
@@ -8,12 +8,2 @@
 
-#ifdef __attribute__
-#undef __attribute__
-#endif
-
-#ifdef __noreturn__
-#undef __noreturn__
-#endif
-
-#define	__attribute__(x)  /*  */
-#define	__noreturn__  /*  */
 
