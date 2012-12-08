$NetBSD: patch-src_develop_blend.c,v 1.3 2012/12/08 00:15:26 jakllsch Exp $

--- src/develop/blend.c.orig	2012-11-23 23:23:21.000000000 +0000
+++ src/develop/blend.c
@@ -1718,7 +1718,7 @@ void dt_develop_blend_process (struct dt
     if(self->suppress_mask && self->dev->gui_attached && self == self->dev->gui_module && piece->pipe == self->dev->pipe && (d->blendif & (1<<31)))
     {
 #ifdef _OPENMP
-#if !defined(__SUNOS__)
+#if !defined(__SUNOS__) && !defined(__NetBSD__)
     #pragma omp parallel for default(none) shared(roi_out,mask,stderr)
 #else
     #pragma omp parallel for shared(roi_out,mask)
@@ -1733,7 +1733,7 @@ void dt_develop_blend_process (struct dt
 
 
 #ifdef _OPENMP
-#if !defined(__SUNOS__)
+#if !defined(__SUNOS__) && !defined(__NetBSD__)
     #pragma omp parallel for default(none) shared(i,roi_out,o,mask,blend,stderr,ch)
 #else
     #pragma omp parallel for shared(i,roi_out,o,mask,blend,ch)
