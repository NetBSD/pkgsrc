$NetBSD: patch-src_xo-paint.c,v 1.1 2019/10/02 18:55:34 yhardy Exp $

On NetBSD, absolute coordinate changes are reported as an X value
followed by a Y value, which (when moving quickly) leads to a
"stepping" effect. Using a Bezier curve fitting for the points
yields a smooth curve in most cases, and does not seem to adversely
affect the user experience (even with a conventional mouse).

--- src/xo-paint.c.orig	2015-08-11 03:47:11.000000000 +0000
+++ src/xo-paint.c
@@ -249,6 +249,9 @@ void continue_stroke(GdkEvent *event)
 {
   GnomeCanvasPoints seg;
   double *pt, current_width, pressure;
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+  double d, dp, t;
+#endif
 
   if (ui.cur_brush->ruler) {
     pt = ui.cur_path.coords;
@@ -280,7 +283,25 @@ void continue_stroke(GdkEvent *event)
     ui.cur_path.num_points++;
   }
 
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+  if(ui.cur_path.num_points < 3)
+    return;
+
+  // treat this point as an end point
+  // treat the previous point as a control point and recalculate the "actual" point
+  dp = hypot(pt[0] - pt[-2], pt[1] - pt[-1]);
+  d = dp + hypot(pt[0] - pt[2], pt[1] - pt[3]);
+  if(d != 0) {
+    t = dp/d;
+    // Bezier curve fitting
+    pt[0] = (1-t)*(1-t)*pt[-2] + 2*t*(1-t)*pt[0] + t*t*pt[2];
+    pt[1] = (1-t)*(1-t)*pt[-1] + 2*t*(1-t)*pt[1] + t*t*pt[3];
+  }
+
+  seg.coords = pt-2; 
+#else
   seg.coords = pt; 
+#endif
   seg.num_points = 2;
   seg.ref_count = 1;
   
