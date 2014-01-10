$NetBSD: patch-intern_cycles_util_util__types.h,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/cycles/util/util_types.h.orig	2013-11-20 21:10:53.000000000 +0000
+++ intern/cycles/util/util_types.h
@@ -26,6 +26,9 @@
 /* Qualifiers for kernel code shared by CPU and GPU */
 
 #ifndef __KERNEL_GPU__
+#ifdef __cplusplus
+#include <locale>
+#endif
 
 #define __device static inline
 #define __device_noinline static
