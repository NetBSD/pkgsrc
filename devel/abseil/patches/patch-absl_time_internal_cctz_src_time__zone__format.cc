$NetBSD: patch-absl_time_internal_cctz_src_time__zone__format.cc,v 1.4 2024/01/30 18:22:53 adam Exp $

Avoid _XOPEN_SOURCE.

--- absl/time/internal/cctz/src/time_zone_format.cc.orig	2024-01-22 17:59:25.000000000 +0000
+++ absl/time/internal/cctz/src/time_zone_format.cc
@@ -19,7 +19,7 @@
 #endif
 
 #if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
