$NetBSD: patch-gnuradio-core_src_tests_benchmark__vco.cc,v 1.1 2013/02/26 19:25:02 jperkin Exp $

Avoid 'error: call of overloaded <x> is ambiguous' failures.

--- gnuradio-core/src/tests/benchmark_vco.cc.orig	2010-06-02 00:57:53.000000000 +0000
+++ gnuradio-core/src/tests/benchmark_vco.cc
@@ -63,7 +63,7 @@ benchmark (void test (float *x, const fl
   // touch memory
   memset(output, 0, BLOCK_SIZE*sizeof(float));
   for (int i = 0; i<BLOCK_SIZE; i++)
-    input[i] = sin(i);
+    input[i] = sin((float)i);
 
   // get starting CPU usage
 #ifdef HAVE_SYS_RESOURCE_H
