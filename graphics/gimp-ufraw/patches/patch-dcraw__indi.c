$NetBSD: patch-dcraw__indi.c,v 1.2 2020/06/01 00:14:21 gdt Exp $

Drop default(none), because the OPENMP specification is unstable;
some versions prohibit declaring constants as shared and some require it.

--- dcraw_indi.c.orig	2015-06-16 03:58:38.000000000 +0000
+++ dcraw_indi.c
@@ -142,7 +142,6 @@ void CLASS wavelet_denoise_INDI(ushort(*
     private(c,i,hpass,lev,lpass,row,col,thold,fimg,temp)
 #else
     #pragma omp parallel for				\
-    default(none)					\
     shared(nc,image,size)				\
     private(c,i,hpass,lev,lpass,row,col,thold,fimg,temp)
 #endif
@@ -413,7 +412,6 @@ void CLASS vng_interpolate_INDI(ushort(*
     progress(PROGRESS_INTERPOLATE, -height);
 #ifdef _OPENMP
     #pragma omp parallel				\
-    default(none)					\
     shared(image,code,prow,pcol,h)			\
     private(row,col,g,brow,rowtmp,pix,ip,gval,diff,gmin,gmax,thold,sum,color,num,c,t)
 #endif
@@ -496,7 +494,6 @@ void CLASS ppg_interpolate_INDI(ushort(*
 
 #ifdef _OPENMP
     #pragma omp parallel				\
-    default(none)					\
     shared(image,dir,diff)				\
     private(row,col,i,d,c,pix,guess)
 #endif
