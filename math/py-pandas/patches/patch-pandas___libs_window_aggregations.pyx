$NetBSD: patch-pandas___libs_window_aggregations.pyx,v 1.3 2023/08/28 10:34:02 adam Exp $

On NetBSD, signbit and sqrt cannot be imported from "libc", because
even though <math.h> is included, Python.h later includes
<cmath> which in turn #undef's all the relevant definitions
from <math.h>, forcing the use of the std:: variants of those
functions.  So ... re-do how we import signbit() and sqrt().

Submitted upstream:
https://github.com/pandas-dev/pandas/pull/51049

--- pandas/_libs/window/aggregations.pyx.orig	2023-03-16 14:52:19.000000000 +0000
+++ pandas/_libs/window/aggregations.pyx
@@ -1,10 +1,6 @@
 # cython: boundscheck=False, wraparound=False, cdivision=True
 
-from libc.math cimport (
-    round,
-    signbit,
-    sqrt,
-)
+from libc.math cimport round
 from libcpp.deque cimport deque
 
 from pandas._libs.algos cimport TiebreakEnumType
@@ -19,6 +15,10 @@ from numpy cimport (
     ndarray,
 )
 
+cdef extern from "<cmath>" namespace "std":
+    int signbit(float64_t) nogil
+    float64_t sqrt(float64_t x) nogil
+
 cnp.import_array()
 
 import cython
