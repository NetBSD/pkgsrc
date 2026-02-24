$NetBSD: patch-driver_others_blas__server__callback.c,v 1.1 2026/02/24 23:09:02 thor Exp $

Un-break non-SMP build (linktest) by provding the dummy callback setter.

--- driver/others/blas_server_callback.c.orig	2026-01-15 22:57:26.000000000 +0000
+++ driver/others/blas_server_callback.c
@@ -1,12 +1,17 @@
 #include "common.h"
 
+#ifdef SMP_SERVER
 /* global variable to change threading backend from openblas-managed to caller-managed */
 openblas_threads_callback openblas_threads_callback_ = 0;
+#endif
 
 /* non-threadsafe function should be called before any other
    openblas function to change how threads are managed */
    
 void openblas_set_threads_callback_function(openblas_threads_callback callback)
 {
-  openblas_threads_callback_ = callback;
-}
\ Kein Zeilenumbruch am Dateiende.
+/* Dummy for single-threaded build, just like the other thread API functions. */
+#ifdef SMP_SERVER
+      	openblas_threads_callback_ = callback;
+#endif
+}
