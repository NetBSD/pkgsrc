$NetBSD: patch-testsuite_tests_lib-systhreads_testyield.ml,v 1.2 2020/12/09 10:33:04 jaapb Exp $

On NetBSD, the "thread scheduler" appears to just schedule two
threads out of 4 when all they in essence to is "yield", and not
do round-robin scheduling, causing the test to loop.  Reduce the
number of threads in the test to 2.

--- testsuite/tests/lib-systhreads/testyield.ml.orig	2020-09-01 12:47:58.000000000 +0000
+++ testsuite/tests/lib-systhreads/testyield.ml
@@ -8,7 +8,7 @@
    *** native
 *)
 
-let threads = 4
+let threads = 2
 
 let are_ready = ref 0
 
