$NetBSD: patch-absl_time_internal_cctz_src_time__zone__format.cc,v 1.5 2026/01/14 12:56:47 wiz Exp $

Avoid _XOPEN_SOURCE.

--- absl/time/internal/cctz/src/time_zone_format.cc.orig	2026-01-07 19:26:27.000000000 +0000
+++ absl/time/internal/cctz/src/time_zone_format.cc
@@ -21,7 +21,7 @@
 #endif
 
 #if HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
