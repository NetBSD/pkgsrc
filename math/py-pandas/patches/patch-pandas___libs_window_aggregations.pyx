$NetBSD: patch-pandas___libs_window_aggregations.pyx,v 1.1 2023/01/28 17:58:05 he Exp $

On NetBSD, signbit and sqrt cannot be imported from "libc", because
even though <math.h> is included, Python.h later includes
<cmath> which in turn #undef's all the relevant definitions
from <math.h>, forcing the use of the std:: variants of those
functions.  So ... re-do how we import signbit() and sqrt().

--- pandas/_libs/window/aggregations.pyx.orig   2023-01-19 03:22:10.000000000 +0000
+++ pandas/_libs/window/aggregations.pyx
@@ -1,11 +1,8 @@
 # cython: boundscheck=False, wraparound=False, cdivision=True
 
 cimport cython
-from libc.math cimport (
-    round,
-    signbit,
-    sqrt,
-)
+from libc.math cimport round
+
 from libcpp.deque cimport deque
 
 from pandas._libs.algos cimport TiebreakEnumType
@@ -20,6 +17,10 @@ from numpy cimport (
     ndarray,
 )
 
+cdef extern from "<cmath>" namespace "std":
+    int signbit(float64_t) nogil
+    float64_t sqrt(float64_t x) nogil
+
 cnp.import_array()
 
 from pandas._libs.algos import is_monotonic
