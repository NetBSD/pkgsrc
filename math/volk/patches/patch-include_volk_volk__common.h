$NetBSD: patch-include_volk_volk__common.h,v 1.2 2026/02/09 12:55:14 adam Exp $

Something is wrong with NetBSD's headers; GCC says isinf is out of scope.

--- include/volk/volk_common.h.orig	2026-02-09 12:27:43.544508041 +0000
+++ include/volk/volk_common.h
@@ -150,7 +150,12 @@ union bit256 {
 ////////////////////////////////////////////////////////////////////////
 // log2f
 ////////////////////////////////////////////////////////////////////////
+#ifdef __cplusplus
+#include <cmath>
+using std::isinf, std::isnan;
+#else
 #include <math.h>
+#endif
 // +-Inf -> +-127.0f in order to match the behaviour of the SIMD kernels
 // NaN -> NaN (preserved for consistency)
 static inline float log2f_non_ieee(float f)
