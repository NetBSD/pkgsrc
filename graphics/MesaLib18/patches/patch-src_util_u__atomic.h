$NetBSD: patch-src_util_u__atomic.h,v 1.2 2018/10/16 15:21:20 jperkin Exp $

Fix SunOS atomic macros.

--- src/util/u_atomic.h.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/util/u_atomic.h
@@ -20,7 +20,7 @@
  * locally coded assembly, compiler intrinsic or ultimately a
  * mutex-based implementation.
  */
-#if defined(__sun)
+#if defined(__sun) && !defined(__GNUC__)
 #define PIPE_ATOMIC_OS_SOLARIS
 #elif defined(_MSC_VER)
 #define PIPE_ATOMIC_MSVC_INTRINSIC
