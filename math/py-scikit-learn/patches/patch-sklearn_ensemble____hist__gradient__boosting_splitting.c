$NetBSD: patch-sklearn_ensemble____hist__gradient__boosting_splitting.c,v 1.1 2019/06/17 15:01:45 adam Exp $

Fix building without OpenMP.

--- sklearn/ensemble/_hist_gradient_boosting/splitting.c.orig	2019-05-24 03:32:38.000000000 +0000
+++ sklearn/ensemble/_hist_gradient_boosting/splitting.c
@@ -611,7 +611,6 @@ static CYTHON_INLINE float __PYX_NAN() {
 #include <stdio.h>
 #include "numpy/arrayobject.h"
 #include "numpy/ufuncobject.h"
-#include <omp.h>
 #include <stdlib.h>
 #include "pythread.h"
 #include "pystate.h"
@@ -3810,7 +3809,9 @@ __pyx_v_X_binned = __pyx_t_4;
  *             ELSE:
  *                 int n_threads = 1
  */
+#ifdef _OPENMP
   __pyx_v_n_threads = omp_get_max_threads();
+#endif
 
   /* "sklearn/ensemble/_hist_gradient_boosting/splitting.pyx":249
  *                 int n_threads = 1
