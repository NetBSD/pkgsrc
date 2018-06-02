$NetBSD: patch-src_lj__arch.h,v 1.1 2018/06/02 20:01:21 he Exp $

Fix the test for endianness so that NetBSD/powerpc isn't
mis-categorized as little-endian only because _LITTLE_ENDIAN
is defined -- what matters on NetBSD is the value of _BYTE_ORDER.

--- src/lj_arch.h.orig	2017-05-01 18:11:00.000000000 +0000
+++ src/lj_arch.h
@@ -339,12 +339,21 @@
 #if defined(_SOFT_FLOAT) || defined(_SOFT_DOUBLE)
 #error "No support for PowerPC CPUs without double-precision FPU"
 #endif
-#if defined(_LITTLE_ENDIAN)
-#error "No support for little-endian PowerPC"
+
+#if defined(_BYTE_ORDER) && defined(_LITTLE_ENDIAN)
+# if (_BYTE_ORDER == _LITTLE_ENDIAN)
+#  error "No support for little-endian PowerPC"
+# endif
+#else
+# if defined(_LITTLE_ENDIAN)
+#  error "No support for little-endian PowerPC"
+# endif
 #endif
+
 #if defined(_LP64)
 #error "No support for PowerPC 64 bit mode"
 #endif
+
 #elif LJ_TARGET_MIPS
 #if defined(__mips_soft_float)
 #error "No support for MIPS CPUs without FPU"
