$NetBSD: patch-source_blender_blenlib_intern_math__vector__inline.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/blenlib/intern/math_vector_inline.cc.orig	2026-09-13 05:40:21.268526337 +0000
+++ source/blender/blenlib/intern/math_vector_inline.cc
@@ -966,17 +966,17 @@ MINLINE bool is_finite_v2(const float v[2])
 
 MINLINE bool is_finite_v2(const float v[2])
 {
-  return (isfinite(v[0]) && isfinite(v[1]));
+  return (std::isfinite(v[0]) && std::isfinite(v[1]));
 }
 
 MINLINE bool is_finite_v3(const float v[3])
 {
-  return (isfinite(v[0]) && isfinite(v[1]) && isfinite(v[2]));
+  return (std::isfinite(v[0]) && std::isfinite(v[1]) && std::isfinite(v[2]));
 }
 
 MINLINE bool is_finite_v4(const float v[4])
 {
-  return (isfinite(v[0]) && isfinite(v[1]) && isfinite(v[2]) && isfinite(v[3]));
+  return (std::isfinite(v[0]) && std::isfinite(v[1]) && std::isfinite(v[2]) && std::isfinite(v[3]));
 }
 
 MINLINE bool is_one_v3(const float v[3])
