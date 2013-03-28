$NetBSD: patch-include_QF_mathlib.h,v 1.1 2013/03/28 21:25:52 joerg Exp $

--- include/QF/mathlib.h.orig	2013-03-28 15:01:01.000000000 +0000
+++ include/QF/mathlib.h
@@ -255,11 +255,8 @@ void QuatMult (const quat_t v1, const qu
 	(PlaneDist (point, plane) - (plane)->dist)
 
 extern mplane_t * const frustum;
-extern inline qboolean R_CullBox (const vec3_t mins, const vec3_t maxs);
-extern inline qboolean R_CullSphere (const vec3_t origin, const float radius);
-extern inline float VectorNormalize (vec3_t v);	// returns vector length
 #ifndef IMPLEMENT_R_Cull
-extern inline
+inline
 #endif
 qboolean
 R_CullBox (const vec3_t mins, const vec3_t maxs)
@@ -273,7 +270,7 @@ R_CullBox (const vec3_t mins, const vec3
 }
 
 #ifndef IMPLEMENT_R_Cull
-extern inline
+inline
 #endif
 qboolean
 R_CullSphere (const vec3_t origin, const float radius)
@@ -291,7 +288,7 @@ R_CullSphere (const vec3_t origin, const
 }
 
 #ifndef IMPLEMENT_VectorNormalize
-extern inline
+inline
 #endif
 float
 VectorNormalize (vec3_t v)
