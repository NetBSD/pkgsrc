$NetBSD: patch-sklearn_preprocessing___target__encoder__fast.pyx,v 1.3 2026/01/11 10:28:55 adam Exp $

Fix build on NetBSD.

--- sklearn/preprocessing/_target_encoder_fast.pyx.orig	2025-12-09 16:13:35.000000000 +0000
+++ sklearn/preprocessing/_target_encoder_fast.pyx
@@ -1,4 +1,4 @@
-from libc.math cimport isnan
+from libcpp.cmath cimport isnan
 from libcpp.vector cimport vector
 
 from sklearn.utils._typedefs cimport float32_t, float64_t, int32_t, int64_t
