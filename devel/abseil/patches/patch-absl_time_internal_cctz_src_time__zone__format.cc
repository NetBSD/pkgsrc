$NetBSD: patch-absl_time_internal_cctz_src_time__zone__format.cc,v 1.3 2023/08/21 14:52:26 adam Exp $

Avoid _XOPEN_SOURCE.

--- absl/time/internal/cctz/src/time_zone_format.cc.orig	2023-08-07 18:40:00.000000000 +0000
+++ absl/time/internal/cctz/src/time_zone_format.cc
@@ -19,7 +19,7 @@
 #endif
 
 #if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
