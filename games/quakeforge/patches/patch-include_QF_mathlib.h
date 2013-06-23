$NetBSD: patch-include_QF_mathlib.h,v 1.3 2013/06/23 19:54:42 dholland Exp $

--- include/QF/mathlib.h.orig	2013-03-28 15:01:01.000000000 +0000
+++ include/QF/mathlib.h
@@ -255,11 +255,12 @@ void QuatMult (const quat_t v1, const qu
 	(PlaneDist (point, plane) - (plane)->dist)
 
 extern mplane_t * const frustum;
-extern inline qboolean R_CullBox (const vec3_t mins, const vec3_t maxs);
-extern inline qboolean R_CullSphere (const vec3_t origin, const float radius);
-extern inline float VectorNormalize (vec3_t v);	// returns vector length
 #ifndef IMPLEMENT_R_Cull
+#if defined(__clang__) || !defined(__GNUC__) || defined(__GNC_STDC_INLINE__)
+inline
+#else
 extern inline
+#endif
 #endif
 qboolean
 R_CullBox (const vec3_t mins, const vec3_t maxs)
@@ -273,7 +274,11 @@ R_CullBox (const vec3_t mins, const vec3
 }
 
 #ifndef IMPLEMENT_R_Cull
+#if defined(__clang__) || !defined(__GNUC__) || defined(__GNC_STDC_INLINE__)
+inline
+#else
 extern inline
+#endif
 #endif
 qboolean
 R_CullSphere (const vec3_t origin, const float radius)
@@ -291,7 +296,11 @@ R_CullSphere (const vec3_t origin, const
 }
 
 #ifndef IMPLEMENT_VectorNormalize
+#if defined(__clang__) || !defined(__GNUC__) || defined(__GNC_STDC_INLINE__)
+inline
+#else
 extern inline
+#endif
 #endif
 float
 VectorNormalize (vec3_t v)
