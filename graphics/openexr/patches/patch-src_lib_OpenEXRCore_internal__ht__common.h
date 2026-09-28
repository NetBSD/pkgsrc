$NetBSD: patch-src_lib_OpenEXRCore_internal__ht__common.h,v 1.1 2026/09/28 14:39:29 wiz Exp $

Fix build on NetBSD.
https://github.com/AcademySoftwareFoundation/openexr/issues/2681

--- src/lib/OpenEXRCore/internal_ht_common.h.orig	2026-09-28 14:32:55.547276802 +0000
+++ src/lib/OpenEXRCore/internal_ht_common.h
@@ -10,7 +10,7 @@
 #include <float.h>
 #include <stdint.h>
 #include <stdlib.h>
-#include <math.h>
+#include <cmath>
 #include <string.h>
 #include <half.h>
 #include "openexr_coding.h"
@@ -232,7 +232,7 @@ static inline int32_t float_to_int32(float h)
  */
 static inline int32_t float_to_int32(float h)
 {
-    if (isnan (h)) return 0;
+    if (std::isnan (h)) return 0;
     double v = round (tf_from_linear ((double) h) * INT32_FLOAT_FACTOR);
     if (v > (double) INT32_MAX) return INT32_MAX;
     if (v < -(double) INT32_MAX) return -INT32_MAX;
