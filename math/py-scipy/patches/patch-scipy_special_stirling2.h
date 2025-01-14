$NetBSD: patch-scipy_special_stirling2.h,v 1.4 2025/01/14 18:18:06 gdt Exp $

On NetBSD 10, scipy fails to build with many errors like:

  FAILED: scipy/special/_ufuncs_cxx.so.p/meson-generated__ufuncs_cxx.cpp.o 
c++ -Iscipy/special/_ufuncs_cxx.so.p -Iscipy/special -I../scipy/special -I../scipy/_lib/boost_math/include -Iscipy/_lib -I../scipy/_lib -I../scipy/_build_utils/src -I../../../../../../../usr/pkg/lib/python3.11/site-packages/numpy/_core/include -I/usr/pkg/include/python3.11 -I/usr/pkg/include -I/usr/include -fvisibility=hidden -fvisibility-inlines-hidden -fdiagnostics-color=always -DNDEBUG -D_FILE_OFFSET_BITS=64 -Wall -Winvalid-pch -std=c++17 -O3 -O2 -D__STDC_FORMAT_MACROS -fPIC -DSP_SPECFUN_ERROR -DNPY_NO_DEPRECATED_API=NPY_1_9_API_VERSION -DCYTHON_CCOMPLEX=0 -DBOOST_MATH_STANDALONE=1 '-DCYTHON_EXTERN_C=extern "C"' -MD -MQ scipy/special/_ufuncs_cxx.so.p/meson-generated__ufuncs_cxx.cpp.o -MF scipy/special/_ufuncs_cxx.so.p/meson-generated__ufuncs_cxx.cpp.o.d -o scipy/special/_ufuncs_cxx.so.p/meson-generated__ufuncs_cxx.cpp.o -c scipy/special/_ufuncs_cxx.so.p/_ufuncs_cxx.cpp
In file included from ../scipy/special/stirling2.h:9,
                 from scipy/special/_ufuncs_cxx_defs.h:112,
                 from scipy/special/_ufuncs_cxx.so.p/_ufuncs_cxx.cpp:1246:
../scipy/special/xsf/evalpoly.h:26:29: error: expected unqualified-id before '_Complex'
   26 | XSF_HOST_DEVICE inline std::complex<double> cevalpoly(const double *coeffs, int degree, std::complex<double> z) {
      |                             ^~~~~~~


C++ documentation implies that one should use <complex>, and therefore
that <complex.h> is only appropriate in C mode.  Using C++ headers in
C++ mode resolves the build failure.  Therefore, switch to that
approach.

Not yet sent upstream.

--- scipy/special/stirling2.h.orig	2025-01-13 23:39:01.039575715 +0000
+++ scipy/special/stirling2.h
@@ -3,11 +3,13 @@
 
 #if defined(__cplusplus)
 #include <cmath>
+#include <complex>
 using std::isinf;
-#endif
-
-#include <complex.h>
+#else	/* __cplusplus */
 #include <math.h>
+#include <complex.h>
+#endif	/* __cplusplus */
+
 #include <stdio.h>
 #include <stdint.h>
 #include <stdlib.h>
