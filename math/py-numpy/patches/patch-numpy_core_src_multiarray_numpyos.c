$NetBSD: patch-numpy_core_src_multiarray_numpyos.c,v 1.1 2016/07/24 15:25:22 kamil Exp $

Don't include <xlocale.h> for NetBSD.

--- numpy/core/src/multiarray/numpyos.c.orig	2016-06-25 15:38:34.000000000 +0000
+++ numpy/core/src/multiarray/numpyos.c
@@ -15,8 +15,10 @@
 
 #ifdef HAVE_STRTOLD_L
 #include <stdlib.h>
+#if !defined(__NetBSD__)
 #include <xlocale.h>
 #endif
+#endif
 
 
 
