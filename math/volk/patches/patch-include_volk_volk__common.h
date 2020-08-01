$NetBSD: patch-include_volk_volk__common.h,v 1.1 2020/08/01 04:35:09 tnn Exp $

Something is wrong with NetBSD's headers; GCC says isinf is out of scope.

--- include/volk/volk_common.h.orig	2020-05-09 10:58:32.000000000 +0000
+++ include/volk/volk_common.h
@@ -150,7 +150,11 @@ union bit256 {
 static inline float log2f_non_ieee(float f)
 {
     float const result = log2f(f);
+#ifdef __NetBSD__
+    return __builtin_isinf(result) ? copysignf(127.0f, result) : result;
+#else
     return isinf(result) ? copysignf(127.0f, result) : result;
+#endif
 }
 
 ////////////////////////////////////////////////////////////////////////
