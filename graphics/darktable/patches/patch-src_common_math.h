$NetBSD: patch-src_common_math.h,v 1.1 2025/01/01 14:06:17 ryoon Exp $

--- src/common/math.h.orig	2024-12-15 21:38:01.000000000 +0000
+++ src/common/math.h
@@ -19,7 +19,12 @@
 #pragma once
 
 #include <stddef.h>
+#if defined(__cplusplus)
+#include <cmath>
+using std::isnan, std::isinf, std::isfinite, std::isnormal;
+#else
 #include <math.h>
+#endif
 #include <stdint.h>
 #include "common/sse.h"		// also includes darktable.h
 
