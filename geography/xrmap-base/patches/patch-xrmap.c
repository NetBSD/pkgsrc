$NetBSD: patch-xrmap.c,v 1.1 2012/05/04 16:16:42 joerg Exp $

Don't use nested functions.

--- xrmap.c.orig	2012-04-27 12:12:57.000000000 +0000
+++ xrmap.c
@@ -5517,90 +5517,87 @@ void arcinfo_lines(ImageLayout *scene) {
     Pixel pix;
     double cotan_lat0, conv_lat0;
 
-void next_segment(double x, double y)
-{
-    double u, v, w, t;
-    int i, j, dx, dy, dxp, dyp, epsx, epsy;
-    if (arc_lambert) {
-       /* Inverse Lambert projection */
-       u = x * arc_scale;
-       v = y * arc_scale - arc_transl;
-       w = atan(u/(-v));
-       t = v/cos(w);
-       x = arc_lon0 + conv_lat0 * w;
-       y = atan(cotan_lat0 + t)/CONV + arc_lat0;
-    }
-    sp.sph[LONGITUDE] = x;
-    sp.sph[LATITUDE]  = y;
-
-    if (arc_start==1 && fabs(x-arc_x)+fabs(y-arc_y)<0.05) {
-       arc_start = 2;
-    }
-    if (arc_start==3)
-       printf("%.6f %.6f\n", x, y);
-    pt2 = project(scene, spher2cart(scene, sp));
- 
- split_arc:
-    if (new_arc) {
-       if (dump_file && num_mod!= -1) {
-	  i = (++arc_numseg[num_mod]);
-          arc_index[num_mod] = (char **)
-             realloc(arc_index[num_mod], i * sizeof(char *));
-	  nstrokes = 0;
-	  seg = (char **)&arc_index[num_mod][i-1];
-	  *seg = (char *) malloc(10);
-	  spr4(*seg, nstrokes);
-	  xi = round2int(3600.0 * x);
-          yi = round2int(3600.0 * y);
-	  spr3(*seg+4, xi);
-	  spr3(*seg+7, yi);
-       } else
-	  seg = NULL;
-       path_start = 1;
-       pt1 = pt2;
-       new_arc = 0;
-    } else {
-       draw_segment(scene, pt1, pt2, pix);
-       if (path_start) {
-	  new_arc = 1;
-	  goto split_arc;
-       }
-       pt1 = pt2;
-       if (seg) {
-	  dx = xi;
-	  dy = yi;
-	  xi = round2int(3600.0 * x);
-          yi = round2int(3600.0 * y);
-	  dx = xi - dx;
-	  dy = yi - dy;
-	  if (dx || dy) {
-             if (dx<0) {
-	        epsx = -1;
-	        dx = -dx;
-	     } else
-	        epsx = 1;
-             if (dy<0) {
-	        epsy = -1;
-	        dy = -dy;
-	     } else
-	        epsy = 1;
-	     dxp = (dx+126)/127;
-	     dyp = (dy+126)/127;
-	     if (dxp>dyp) n = dxp; else n = dyp;
-	     nstrokes += n;
-             *seg = (char *)realloc(*seg, 10+2*nstrokes);
-             spr4(*seg, nstrokes);
-	     for (j=0; j<n; j++) {
-                dxp = epsx * ((dx*(j+1))/n - (dx*j)/n);
-		dyp = epsy * ((dy*(j+1))/n - (dy*j)/n);
-		i = 10 + 2 * (nstrokes-n+j);
-		(*seg)[i] =  (char)(dxp&255);
-		(*seg)[i+1] =  (char)(dyp&255);
-	     }
-	  }
-       }
-    }
-}
+#define next_segment(ARG1, ARG2, COUNT) do { \
+    double x = ARG1, y = ARG2, u, v, w, t; \
+    int i, j, dx, dy, dxp, dyp, epsx, epsy; \
+    if (arc_lambert) { \
+       /* Inverse Lambert projection */ \
+       u = x * arc_scale; \
+       v = y * arc_scale - arc_transl; \
+       w = atan(u/(-v)); \
+       t = v/cos(w); \
+       x = arc_lon0 + conv_lat0 * w; \
+       y = atan(cotan_lat0 + t)/CONV + arc_lat0; \
+    } \
+    sp.sph[LONGITUDE] = x; \
+    sp.sph[LATITUDE]  = y; \
+    if (arc_start==1 && fabs(x-arc_x)+fabs(y-arc_y)<0.05) { \
+       arc_start = 2; \
+    } \
+    if (arc_start==3) \
+       printf("%.6f %.6f\n", x, y); \
+    pt2 = project(scene, spher2cart(scene, sp)); \
+ split_arc ## COUNT: \
+    if (new_arc) { \
+       if (dump_file && num_mod!= -1) { \
+	  i = (++arc_numseg[num_mod]); \
+          arc_index[num_mod] = (char **) \
+             realloc(arc_index[num_mod], i * sizeof(char *)); \
+	  nstrokes = 0; \
+	  seg = (char **)&arc_index[num_mod][i-1]; \
+	  *seg = (char *) malloc(10); \
+	  spr4(*seg, nstrokes); \
+	  xi = round2int(3600.0 * x); \
+          yi = round2int(3600.0 * y); \
+	  spr3(*seg+4, xi); \
+	  spr3(*seg+7, yi); \
+       } else \
+	  seg = NULL; \
+       path_start = 1; \
+       pt1 = pt2; \
+       new_arc = 0; \
+    } else { \
+       draw_segment(scene, pt1, pt2, pix); \
+       if (path_start) { \
+	  new_arc = 1; \
+	  goto split_arc ## COUNT; \
+       } \
+       pt1 = pt2; \
+       if (seg) { \
+	  dx = xi; \
+	  dy = yi; \
+	  xi = round2int(3600.0 * x); \
+          yi = round2int(3600.0 * y); \
+	  dx = xi - dx; \
+	  dy = yi - dy; \
+	  if (dx || dy) { \
+             if (dx<0) { \
+	        epsx = -1; \
+	        dx = -dx; \
+	     } else \
+	        epsx = 1; \
+             if (dy<0) { \
+	        epsy = -1; \
+	        dy = -dy; \
+	     } else \
+	        epsy = 1; \
+	     dxp = (dx+126)/127; \
+	     dyp = (dy+126)/127; \
+	     if (dxp>dyp) n = dxp; else n = dyp; \
+	     nstrokes += n; \
+             *seg = (char *)realloc(*seg, 10+2*nstrokes); \
+             spr4(*seg, nstrokes); \
+	     for (j=0; j<n; j++) { \
+                dxp = epsx * ((dx*(j+1))/n - (dx*j)/n); \
+		dyp = epsy * ((dy*(j+1))/n - (dy*j)/n); \
+		i = 10 + 2 * (nstrokes-n+j); \
+		(*seg)[i] =  (char)(dxp&255); \
+		(*seg)[i+1] =  (char)(dyp&255); \
+	     } \
+	  } \
+       } \
+    } \
+} while(0)
 
     if (!arc_file) return; 
     pix = scene->color[C_FG_TICKS].pix;
@@ -5664,14 +5661,14 @@ void next_segment(double x, double y)
           ptr[28] = '\0';
           n = sscanf(ptr, "%lg %lg", &a, &b);
 	  if (n<2) continue;
-          next_segment(a, b);
+          next_segment(a, b, 1);
           ptr[28] = sep;
           p = sscanf(ptr+28, "%lg %lg", &c, &d);
-          if (p>=2) next_segment(c, d);
+          if (p>=2) next_segment(c, d, 2);
        } else {
           n = sscanf(ptr, "%lg %lg", &a, &b);
 	  if (n<2) continue;
-	  next_segment(a, b);
+	  next_segment(a, b, 3);
        }
     }
     gzclose(fd);
