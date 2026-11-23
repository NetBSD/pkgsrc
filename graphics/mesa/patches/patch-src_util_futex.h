$NetBSD: patch-src_util_futex.h,v 1.1 2026/11/23 10:29:52 adam Exp $

* Support futex_wake() for NetBSD.

--- src/util/futex.h.orig	2026-10-23 06:40:10.243611849 +0000
+++ src/util/futex.h
@@ -35,6 +35,8 @@
 #define UTIL_FUTEX_SUPPORTED 1
 #elif defined(_WIN32) && !defined(WINDOWS_NO_FUTEX)
 #define UTIL_FUTEX_SUPPORTED 1
+#elif defined(__NetBSD__)
+#define UTIL_FUTEX_SUPPORTED 1
 #else
 #define UTIL_FUTEX_SUPPORTED 0
 #endif
