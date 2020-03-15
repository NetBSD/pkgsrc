$NetBSD: patch-absl_time_internal_cctz_src_time__zone__format.cc,v 1.1 2020/03/15 22:25:56 adam Exp $

Avoid _XOPEN_SOURCE.

--- absl/time/internal/cctz/src/time_zone_format.cc.orig	2020-03-15 11:19:38.157894380 +0000
+++ absl/time/internal/cctz/src/time_zone_format.cc
@@ -18,11 +18,6 @@
 #endif
 #endif
 
-#if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE)
-#define _XOPEN_SOURCE  // Definedness suffices for strptime.
-#endif
-#endif
 
 #include "absl/base/config.h"
 #include "absl/time/internal/cctz/include/cctz/time_zone.h"
