$NetBSD: patch-dcraw__indi.c,v 1.1 2020/04/20 00:38:36 joerg Exp $

--- dcraw_indi.c.orig	2020-04-19 19:58:30.067650344 +0000
+++ dcraw_indi.c
@@ -143,7 +143,7 @@ void CLASS wavelet_denoise_INDI(ushort(*
 #else
     #pragma omp parallel for				\
     default(none)					\
-    shared(nc,image,size)				\
+    shared(nc,image,size,iwidth,iheight,threshold,noise) \
     private(c,i,hpass,lev,lpass,row,col,thold,fimg,temp)
 #endif
 #endif
@@ -414,7 +414,7 @@ void CLASS vng_interpolate_INDI(ushort(*
 #ifdef _OPENMP
     #pragma omp parallel				\
     default(none)					\
-    shared(image,code,prow,pcol,h)			\
+    shared(image,code,prow,pcol,h,colors,width,filters,height)		\
     private(row,col,g,brow,rowtmp,pix,ip,gval,diff,gmin,gmax,thold,sum,color,num,c,t)
 #endif
     {
@@ -497,7 +497,7 @@ void CLASS ppg_interpolate_INDI(ushort(*
 #ifdef _OPENMP
     #pragma omp parallel				\
     default(none)					\
-    shared(image,dir,diff)				\
+    shared(image,dir,diff,height,width,filters)		\
     private(row,col,i,d,c,pix,guess)
 #endif
     {
