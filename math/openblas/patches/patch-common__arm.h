$NetBSD: patch-common__arm.h,v 1.1 2020/11/05 16:31:45 bacon Exp $

Add clang support

--- common_arm.h.orig	2016-09-01 03:58:42 UTC
+++ common_arm.h
@@ -93,6 +93,13 @@ static inline int blas_quickdivide(blasi
 
 #endif
 
+/* Translate pre-UAL asm to UAL equivalents */
+#if defined(__clang__)
+#define fnmacs vmls.f32
+#define fnmacd vmls.f64
+#define fnmuls vnmul.f32
+#define fnmuld vnmul.f64
+#endif
 
 #ifndef F_INTERFACE
 #define REALNAME ASMNAME
