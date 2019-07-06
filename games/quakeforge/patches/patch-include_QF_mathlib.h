$NetBSD: patch-include_QF_mathlib.h,v 1.5 2019/07/06 22:53:24 nia Exp $

Fix inline usage for C99.

--- include/QF/mathlib.h.orig	2013-01-23 03:10:55.000000000 +0000
+++ include/QF/mathlib.h
@@ -174,11 +174,9 @@ void RotatePointAroundVector (vec3_t dst
 	} while (0)
 
 extern plane_t * const frustum;
-extern inline qboolean R_CullBox (const vec3_t mins, const vec3_t maxs);
-extern inline qboolean R_CullSphere (const vec3_t origin, const float radius);
 
 #ifndef IMPLEMENT_R_Cull
-extern inline
+static inline
 #else
 VISIBLE
 #endif
@@ -194,7 +192,7 @@ R_CullBox (const vec3_t mins, const vec3
 }
 
 #ifndef IMPLEMENT_R_Cull
-extern inline
+static inline
 #else
 VISIBLE
 #endif
