$NetBSD: patch-include_volk_volk__complex.h,v 1.2 2021/12/11 14:03:21 tnn Exp $

For some reason <tgmath.h> is only available in C++ mode ...

--- include/volk/volk_complex.h.orig	2021-06-05 11:01:46.000000000 +0000
+++ include/volk/volk_complex.h
@@ -56,7 +56,11 @@ inline T lv_conj(const T& x)
 #else /* __cplusplus */
 
 #include <complex.h>
+#if defined(__NetBSD__)
+#include <math.h>
+#else
 #include <tgmath.h>
+#endif
 
 typedef char complex lv_8sc_t;
 typedef short complex lv_16sc_t;
