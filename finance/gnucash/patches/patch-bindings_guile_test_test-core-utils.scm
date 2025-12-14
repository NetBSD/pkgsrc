$NetBSD: patch-bindings_guile_test_test-core-utils.scm,v 1.1 2025/12/14 20:51:32 wiz Exp $

Guile 3.0.11 compatibility.
https://github.com/Gnucash/gnucash/pull/2158

--- bindings/guile/test/test-core-utils.scm.orig	2024-11-12 02:02:44.000000000 +0000
+++ bindings/guile/test/test-core-utils.scm
@@ -42,7 +42,7 @@
     "${symbol} does not exist"
     (gnc:format "${symbol} does not exist" 'existence "none"))
 
-  (test-error "gnc:format syntax error"
+  (test-error "gnc:format syntax error" #t
     (gnc:format "${symbol} does not exist" 'existence)))
 
 (define (run-test)
