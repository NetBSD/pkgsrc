$NetBSD: patch-src_celmath_intersect.h,v 1.1 2013/11/08 21:15:47 joerg Exp $

--- src/celmath/intersect.h.orig	2013-11-07 14:03:35.000000000 +0000
+++ src/celmath/intersect.h
@@ -12,6 +12,7 @@
 #ifndef _CELMATH_INTERSECT_H_
 #define _CELMATH_INTERSECT_H_
 
+#include "mathlib.h"
 #include "ray.h"
 #include "sphere.h"
 #include "ellipsoid.h"
