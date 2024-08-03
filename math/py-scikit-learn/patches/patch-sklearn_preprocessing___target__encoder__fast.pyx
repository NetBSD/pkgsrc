$NetBSD: patch-sklearn_preprocessing___target__encoder__fast.pyx,v 1.2 2024/08/03 07:21:06 adam Exp $

Fix build on NetBSD.

--- sklearn/preprocessing/_target_encoder_fast.pyx.orig	2024-07-02 17:14:07.000000000 +0000
+++ sklearn/preprocessing/_target_encoder_fast.pyx
@@ -1,4 +1,4 @@
-from libc.math cimport isnan
+from libcpp.cmath cimport isnan
 from libcpp.vector cimport vector
 
 from ..utils._typedefs cimport float32_t, float64_t, int32_t, int64_t
