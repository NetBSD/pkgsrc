$NetBSD: patch-lib_g77__interface.c,v 1.1 2026/11/10 15:43:51 wiz Exp $

From upstream:
To avoid xmalloc from the test suite polluting the name space.

--- lib/g77_interface.c.orig	2026-11-10 09:52:12.000000000 +0000
+++ lib/g77_interface.c
@@ -30,6 +30,11 @@
 #include "common.h"
 #include "matheval.h"
 
+/* Fortran 77 interface is visible, like library interface.  */
+#if defined __GNUC__ && __GNUC__ >= 4
+#pragma GCC visibility push(default)
+#endif
+
 /* Wrapper for evaluator_create() function.  Evaluator objects will be
    passed between Fortran and C as 64-bit integers instead of void
    pointers, thus size of void* is assumed to be less or equal of 64 bits
@@ -259,3 +264,7 @@ evaluator_derivative_z__(int64_t *evaluator)
 {
 	return (int64_t) evaluator_derivative_z((void *) *evaluator);
 }
+
+#if defined __GNUC__ && __GNUC__ >= 4
+#pragma GCC visibility pop
+#endif
