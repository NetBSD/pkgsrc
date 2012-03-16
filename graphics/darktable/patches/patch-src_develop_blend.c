$NetBSD: patch-src_develop_blend.c,v 1.2 2012/03/16 00:35:01 jakllsch Exp $

--- src/develop/blend.c.orig	2012-03-13 21:29:39.000000000 +0000
+++ src/develop/blend.c
@@ -1230,7 +1230,7 @@ void dt_develop_blend_process (struct dt
       ch = 1;
     
 #ifdef _OPENMP
-#if !defined(__SUNOS__)
+#if !defined(__SUNOS__) && !defined(__NetBSD__)
     #pragma omp parallel for default(none) shared(in,roi_out,out,blend,d,stderr,ch)
 #else
     #pragma omp parallel for shared(in,roi_out,out,blend,d,ch)
