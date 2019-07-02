$NetBSD: patch-include_QF_mathlib.h,v 1.4 2019/07/02 13:37:34 nia Exp $

--- include/QF/mathlib.h.orig	2004-04-07 18:01:45.000000000 +0000
+++ include/QF/mathlib.h
@@ -255,12 +255,8 @@ void QuatMult (const quat_t v1, const qu
 	(PlaneDist (point, plane) - (plane)->dist)
 
 extern mplane_t * const frustum;
-extern inline qboolean R_CullBox (const vec3_t mins, const vec3_t maxs);
-extern inline qboolean R_CullSphere (const vec3_t origin, const float radius);
-extern inline float VectorNormalize (vec3_t v);	// returns vector length
-#ifndef IMPLEMENT_R_Cull
-extern inline
-#endif
+
+static inline
 qboolean
 R_CullBox (const vec3_t mins, const vec3_t maxs)
 {
@@ -272,9 +268,7 @@ R_CullBox (const vec3_t mins, const vec3
 	return false;
 }
 
-#ifndef IMPLEMENT_R_Cull
-extern inline
-#endif
+static inline
 qboolean
 R_CullSphere (const vec3_t origin, const float radius)
 {
@@ -290,9 +284,7 @@ R_CullSphere (const vec3_t origin, const
 	return false;
 }
 
-#ifndef IMPLEMENT_VectorNormalize
-extern inline
-#endif
+static inline
 float
 VectorNormalize (vec3_t v)
 {
