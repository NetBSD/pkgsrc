$NetBSD: patch-source_blender_blenlib_intern_math__vector__inline.cc,v 1.1 2026/11/27 13:46:28 adam Exp $

--- source/blender/blenlib/intern/math_vector_inline.cc.orig	2025-07-31 05:34:36.000000000 +0000
+++ source/blender/blenlib/intern/math_vector_inline.cc
@@ -9,6 +9,10 @@
 #ifndef __MATH_VECTOR_INLINE_C__
 #define __MATH_VECTOR_INLINE_C__
 
+#ifdef __cplusplus
+#include <cmath>
+#endif
+
 #include "BLI_math_base.h"
 #include "BLI_utildefines.h"
 
@@ -951,17 +955,29 @@ MINLINE bool is_finite_v2(const float v[2])
 
 MINLINE bool is_finite_v2(const float v[2])
 {
+#ifdef __cplusplus
+  return (std::isfinite(v[0]) && std::isfinite(v[1]));
+#else
   return (isfinite(v[0]) && isfinite(v[1]));
+#endif
 }
 
 MINLINE bool is_finite_v3(const float v[3])
 {
+#ifdef __cplusplus
+  return (std::isfinite(v[0]) && std::isfinite(v[1]) && std::isfinite(v[2]));
+#else
   return (isfinite(v[0]) && isfinite(v[1]) && isfinite(v[2]));
+#endif
 }
 
 MINLINE bool is_finite_v4(const float v[4])
 {
+#ifdef __cplusplus
+  return (std::isfinite(v[0]) && std::isfinite(v[1]) && std::isfinite(v[2]) && std::isfinite(v[3]));
+#else
   return (isfinite(v[0]) && isfinite(v[1]) && isfinite(v[2]) && isfinite(v[3]));
+#endif
 }
 
 MINLINE bool is_one_v3(const float v[3])
