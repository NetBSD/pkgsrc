$NetBSD: patch-numpy_core_src_npymath_npy__math__private.h,v 1.1 2022/04/10 13:15:47 tnn Exp $

don't include <complex.h> (C99 complex) when compiling C++.
It breaks due to conflict with std::complex.

INFO: c++: numpy/core/src/umath/clip.cpp
In file included from numpy/core/src/npymath/npy_math_private.h:176,
                 from numpy/core/src/npymath/npy_math_internal.h.src:56,
                 from numpy/core/include/numpy/npy_math.h:596,
                 from numpy/core/include/numpy/halffloat.h:5,
                 from numpy/core/src/umath/clip.cpp:11:
numpy/core/src/npymath/npy_math_private.h:517:14: error: expected unqualified-id before '_Complex'
  517 |         std::complex<double> c99z;

--- numpy/core/src/npymath/npy_math_private.h.orig	2022-02-22 11:30:42.000000000 +0000
+++ numpy/core/src/npymath/npy_math_private.h
@@ -173,8 +173,12 @@ do {                                    
 } while (0)
 
 #ifdef NPY_USE_C99_COMPLEX
+#ifdef __cplusplus
+#include <complex>
+#else
 #include <complex.h>
 #endif
+#endif
 
 /*
  * Long double support
