$NetBSD: patch-pandas___libs_window_aggregations.pyx,v 1.4 2026/06/05 10:41:53 adam Exp $

On NetBSD, isnan, signbit and sqrt cannot be imported from "libc", because even
though <math.h> is included, Python.h later includes <cmath> which in turn
#undef's all the relevant definitions from <math.h>, forcing the use of the
std:: variants of those functions.

Submitted upstream:
https://github.com/pandas-dev/pandas/pull/51049

--- pandas/_libs/window/aggregations.pyx.orig	2026-05-11 16:18:35.000000000 +0000
+++ pandas/_libs/window/aggregations.pyx
@@ -1,10 +1,6 @@
 # cython: boundscheck=False, wraparound=False, cdivision=True
 
-from libc.math cimport (
-    fabs,
-    signbit,
-    sqrt,
-)
+from libc.math cimport fabs;
 from libcpp.deque cimport deque
 from libcpp.stack cimport stack
 from libcpp.unordered_map cimport unordered_map
@@ -21,6 +17,11 @@ from numpy cimport (
     ndarray,
 )
 
+cdef extern from "<cmath>" namespace "std":
+    int isnan(float64_t) nogil
+    int signbit(float64_t) nogil
+    float64_t sqrt(float64_t x) nogil
+
 cnp.import_array()
 
 import cython
@@ -995,7 +996,6 @@ cdef int64_t bisect_left(
             hi = mid
     return lo
 
-from libc.math cimport isnan
 
 # Prior version of moving maximum / minimum code taken from Bottleneck
 # Licence at LICENSES/BOTTLENECK_LICENCE
