$NetBSD: patch-include_volk_volk__complex.h,v 1.1 2020/08/01 04:35:09 tnn Exp $

For some reason <tgmath.h> is only available in C++ mode ...

--- include/volk/volk_complex.h.orig	2020-05-09 10:58:32.000000000 +0000
+++ include/volk/volk_complex.h
@@ -58,7 +58,12 @@ inline T lv_conj(const T& x)
 #if __STDC_VERSION__ >= 199901L /* C99 check */
 /* this allows us to conj in lv_conj without the double detour for single-precision floats
  */
+#if defined(__NetBSD__) && !defined(__cplusplus)
+#include <math.h>
+#include <complex.h> 
+#else
 #include <tgmath.h>
+#endif
 #endif /* C99 check */
 
 #include <complex.h>
