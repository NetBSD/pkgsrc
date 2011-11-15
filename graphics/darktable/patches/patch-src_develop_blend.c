$NetBSD: patch-src_develop_blend.c,v 1.1 2011/11/15 21:19:02 jakllsch Exp $

--- src/develop/blend.c.orig	2011-11-07 06:46:13.000000000 +0000
+++ src/develop/blend.c
@@ -1230,8 +1230,12 @@ void dt_develop_blend_process (struct dt
       ch = 1;
     
 #ifdef _OPENMP
+#if defined(__NetBSD__)
+    #pragma omp parallel for default(none) shared(in,roi_out,out,blend,d,__sF,ch)
+#else
     #pragma omp parallel for default(none) shared(in,roi_out,out,blend,d,stderr,ch)
 #endif
+#endif
     for (int y=0; y<roi_out->height; y++) {
         int index = (ch*y*roi_out->width);
         blend(cst, opacity, in+index, out+index, roi_out->width*ch, blendflag);
