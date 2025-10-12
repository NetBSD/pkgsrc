$NetBSD: patch-src_sox_sample_test.h,v 1.1 2025/10/12 04:06:27 mrg Exp $

Include <math.h> for fabs(3) usage.

--- src/sox_sample_test.h.orig	2012-01-23 14:27:33.000000000 -0800
+++ src/sox_sample_test.h	2025-10-11 20:55:31.269901766 -0700
@@ -19,6 +19,7 @@
 #undef NDEBUG /* Must undef above assert.h or other that might include it. */
 #endif
 #include <assert.h>
+#include <math.h>
 #include "sox.h"
 
 #define TEST_UINT(bits) \
