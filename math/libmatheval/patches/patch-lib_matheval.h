$NetBSD: patch-lib_matheval.h,v 1.1 2026/11/10 15:43:51 wiz Exp $

From upstream:
To avoid xmalloc from the test suite polluting the name space.

--- lib/matheval.h.orig	2026-11-10 09:52:12.000000000 +0000
+++ lib/matheval.h
@@ -24,6 +24,11 @@ extern "C" {
 extern "C" {
 #endif
 
+/* Library interface is visible, other symbols of library are hidden.  */
+#if defined __GNUC__ && __GNUC__ >= 4
+#pragma GCC visibility push(default)
+#endif
+
 /* Create evaluator from string representing function.  Function
    returns pointer that should be passed as first argument to all
    other library functions.  If an error occurs, function will
@@ -82,6 +87,10 @@ extern "C" {
 	extern void *evaluator_derivative_x(void *evaluator);
 	extern void *evaluator_derivative_y(void *evaluator);
 	extern void *evaluator_derivative_z(void *evaluator);
+
+#if defined __GNUC__ && __GNUC__ >= 4
+#pragma GCC visibility pop
+#endif
 
 #ifdef __cplusplus
 }
