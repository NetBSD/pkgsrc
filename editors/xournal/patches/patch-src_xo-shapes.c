$NetBSD: patch-src_xo-shapes.c,v 1.1 2016/01/04 02:06:48 markd Exp $

gcc 5.3 didn't like the "inline"s

--- src/xo-shapes.c.orig	2014-06-15 20:21:05.000000000 +0000
+++ src/xo-shapes.c
@@ -72,42 +73,42 @@ void calc_inertia(double *pt, int start,
 
 /* compute normalized quantities */
 
-inline double center_x(struct Inertia s) 
+double center_x(struct Inertia s) 
 { 
   return s.sx/s.mass;
 }
 
-inline double center_y(struct Inertia s) 
+double center_y(struct Inertia s) 
 { 
   return s.sy/s.mass;
 }
 
-inline double I_xx(struct Inertia s)
+double I_xx(struct Inertia s)
 {
   if (s.mass <= 0.) return 0.;
   return (s.sxx - s.sx*s.sx/s.mass)/s.mass;
 }
 
-inline double I_xy(struct Inertia s)
+double I_xy(struct Inertia s)
 {
   if (s.mass <= 0.) return 0.;
   return (s.sxy - s.sx*s.sy/s.mass)/s.mass;
 }
 
-inline double I_yy(struct Inertia s)
+double I_yy(struct Inertia s)
 {
   if (s.mass <= 0.) return 0.;
   return (s.syy - s.sy*s.sy/s.mass)/s.mass;
 }
 
-inline double I_rad(struct Inertia s)
+double I_rad(struct Inertia s)
 {
   double ixx = I_xx(s), iyy = I_yy(s);
   if (ixx+iyy <= 0.) return 0.;
   return sqrt(ixx+iyy);
 }
 
-inline double I_det(struct Inertia s)
+double I_det(struct Inertia s)
 {
   double ixx = I_xx(s), iyy = I_yy(s), ixy = I_xy(s);
   if (s.mass <= 0.) return 0.;
