$NetBSD: patch-numpy_core_include_numpy_npy__endian.h,v 1.1 2016/07/24 15:25:22 kamil Exp $

Handle NetBSD specific <sys/endian.h>

--- numpy/core/include/numpy/npy_endian.h.orig	2016-06-25 15:38:34.000000000 +0000
+++ numpy/core/include/numpy/npy_endian.h
@@ -6,9 +6,14 @@
  * endian.h
  */
 
-#ifdef NPY_HAVE_ENDIAN_H
+#if defined(NPY_HAVE_ENDIAN_H) || defined(NPY_HAVE_SYS_ENDIAN_H)
     /* Use endian.h if available */
+
+    #if defined(NPY_HAVE_ENDIAN_H)
     #include <endian.h>
+    #elif defined(NPY_HAVE_SYS_ENDIAN_H)
+    #include <sys/endian.h>
+    #endif
 
     #if defined(BYTE_ORDER) && defined(BIG_ENDIAN) && defined(LITTLE_ENDIAN)
         #define NPY_BYTE_ORDER    BYTE_ORDER
