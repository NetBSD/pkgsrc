$NetBSD: patch-include_volk_volk__common.h,v 1.3 2026/02/09 18:42:13 gdt Exp $

This header is used in both C and C++.  Using C99-style bare
isinf/isnan is UB in C++, but works in some environments and thus
persists upstream

Reported upstream by gdt via email 2026-02.  Upstream is going to
prepare a patch for me to test, perhaps detangling C/C++.

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
