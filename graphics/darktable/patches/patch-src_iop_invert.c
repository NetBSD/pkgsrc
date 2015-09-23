$NetBSD: patch-src_iop_invert.c,v 1.1 2015/09/23 11:52:15 joerg Exp $

--- src/iop/invert.c.orig	2015-09-22 13:04:15.000000000 +0000
+++ src/iop/invert.c
@@ -199,7 +199,7 @@ void process (struct dt_iop_module_t *se
     const float *const m = piece->pipe->processed_maximum;
     const int32_t film_rgb_i[3] = {m[0]*film_rgb[0]*65535, m[1]*film_rgb[1]*65535, m[2]*film_rgb[2]*65535};
 #ifdef _OPENMP
-    #pragma omp parallel for default(none) shared(roi_out, ivoid, ovoid, /*film_rgb_i, min, max, res*/) schedule(static)
+    #pragma omp parallel for default(none) shared(roi_out, ivoid, ovoid/*, film_rgb_i, min, max, res*/) schedule(static)
 #endif
     for(int j=0; j<roi_out->height; j++)
     {
