$NetBSD: patch-absl_time_internal_cctz_src_time__zone__format.cc,v 1.6 2026/08/26 10:09:07 adam Exp $

Avoid _XOPEN_SOURCE.

--- absl/time/internal/cctz/src/time_zone_format.cc.orig	2026-08-18 12:53:30.000000000 +0000
+++ absl/time/internal/cctz/src/time_zone_format.cc
@@ -22,7 +22,7 @@
 
 #if HAS_STRPTIME
 #if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && \
-    !defined(__OpenBSD__) && !defined(__APPLE__)
+    !defined(__OpenBSD__) && !defined(__APPLE__) && !defined(__NetBSD__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
