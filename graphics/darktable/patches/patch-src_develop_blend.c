$NetBSD: patch-src_develop_blend.c,v 1.5 2016/12/23 03:53:16 ryoon Exp $

--- src/develop/blend.c.orig	2016-10-23 15:18:57.000000000 +0000
+++ src/develop/blend.c
@@ -2695,7 +2695,7 @@ void dt_develop_blend_process(struct dt_
        && (piece->pipe == self->dev->pipe) && (mask_mode & DEVELOP_MASK_BOTH))
     {
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__WIN32__)
+#if !defined(__SUNOS__) && !defined(__WIN32__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) shared(roi_out, mask, stderr)
 #else
 #pragma omp parallel for shared(roi_out, mask)
@@ -2710,7 +2710,7 @@ void dt_develop_blend_process(struct dt_
 
 /* now apply blending with per-pixel opacity value as defined in mask */
 #ifdef _OPENMP
-#if !defined(__SUNOS__) && !defined(__WIN32__)
+#if !defined(__SUNOS__) && !defined(__WIN32__) && !defined(__NetBSD__)
 #pragma omp parallel for default(none) shared(i, roi_out, o, mask, blend, stderr)
 #else
 #pragma omp parallel for shared(i, roi_out, o, mask, blend)
