$NetBSD: patch-lib_src____libc.h,v 1.1 2021/08/16 01:47:25 dholland Exp $

Avoid parse errors when memcpy is already supplied as a macro.

--- lib/src/__libc.h~	2003-01-08 11:44:57.000000000 +0000
+++ lib/src/__libc.h
@@ -21,6 +21,9 @@
 
 extern double floor(double x);
 extern long int lrint(double x);
+/* quick hack to avoid failing with ssp et al. */
+#ifndef memcpy
 extern void* memcpy(void* dest, const void* src, __typeof__(sizeof(int)) n);
+#endif
 
 #endif /* __oo2c_libc__ */
