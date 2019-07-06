$NetBSD: patch-include_QF_math_vector.h,v 1.1 2019/07/06 22:53:24 nia Exp $

Fix inline usage for C99.

--- include/QF/math/vector.h.orig	2013-01-23 03:10:55.000000000 +0000
+++ include/QF/math/vector.h
@@ -183,10 +183,8 @@ void _VectorSubtract (const vec3_t veca,
 void CrossProduct (const vec3_t v1, const vec3_t v2, vec3_t cross);
 vec_t _VectorNormalize (vec3_t v);			// returns vector length
 
-extern inline float VectorNormalize (vec3_t v);	// returns vector length
-
 #ifndef IMPLEMENT_VectorNormalize
-extern inline
+static inline
 #else
 VISIBLE
 #endif
