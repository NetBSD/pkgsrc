$NetBSD: patch-modules_fdlibm_src_math__private.h,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- modules/fdlibm/src/math_private.h.orig	2018-04-28 01:04:05.000000000 +0000
+++ modules/fdlibm/src/math_private.h
@@ -38,7 +38,7 @@
  * endianness at run time.
  */
 
-#ifdef WIN32
+#if defined(WIN32) || defined(__sun)
 #define u_int32_t uint32_t
 #define u_int64_t uint64_t
 #endif
