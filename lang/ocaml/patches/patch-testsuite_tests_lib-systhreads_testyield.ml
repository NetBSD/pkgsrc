$NetBSD: patch-testsuite_tests_lib-systhreads_testyield.ml,v 1.1 2020/12/08 08:53:16 he Exp $

Reduce the number of threads to 2, so that we don't loop forever
on NetBSD, where the scheduler appears to only alternate between
two threads instead of doing round-robin scheduling.

Ref. https://github.com/ocaml/ocaml/issues/10067

--- testsuite/tests/lib-systhreads/testyield.ml.orig	2020-03-18 15:02:03.000000000 +0000
+++ testsuite/tests/lib-systhreads/testyield.ml
@@ -7,7 +7,7 @@
    ** native
 *)
 
-let threads = 4
+let threads = 2
 
 let are_ready = ref 0
 
