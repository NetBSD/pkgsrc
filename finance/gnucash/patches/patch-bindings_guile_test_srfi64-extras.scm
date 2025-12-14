$NetBSD: patch-bindings_guile_test_srfi64-extras.scm,v 1.1 2025/12/14 20:51:32 wiz Exp $

Guile 3.0.11 compatibility.
https://github.com/Gnucash/gnucash/pull/2158

--- bindings/guile/test/srfi64-extras.scm.orig	2024-11-12 02:02:44.000000000 +0000
+++ bindings/guile/test/srfi64-extras.scm
@@ -34,11 +34,12 @@
         (case (test-result-kind runner)
           ((pass xpass) (set! num-passed (1+ num-passed)))
           ((fail xfail)
-           (if (test-result-ref runner 'expected-value)
+           (if (not (equal? 'no (test-result-ref runner 'expected-value 'no)))
                (format #t "~a\n -> expected: ~s\n -> obtained: ~s\n"
                        (string-join (test-runner-group-path runner) "/")
                        (test-result-ref runner 'expected-value)
-                       (test-result-ref runner 'actual-value)))
+                       (test-result-ref runner 'actual-value))
+               (format #t "~%~a~%" (test-result-alist runner)))
            (set! num-failed (1+ num-failed)))
           (else #t))))
     (test-runner-on-final! runner
