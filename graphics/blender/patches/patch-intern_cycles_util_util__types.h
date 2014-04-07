$NetBSD: patch-intern_cycles_util_util__types.h,v 1.2 2014/04/07 12:21:25 ryoon Exp $

--- intern/cycles/util/util_types.h.orig	2014-03-19 22:27:02.000000000 +0000
+++ intern/cycles/util/util_types.h
@@ -32,6 +32,9 @@
 /* Qualifiers for kernel code shared by CPU and GPU */
 
 #ifndef __KERNEL_GPU__
+#ifdef __cplusplus
+#include <locale>
+#endif
 
 #define ccl_device static inline
 #define ccl_device_noinline static
