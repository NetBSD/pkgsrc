$NetBSD: patch-bindings_guile_test_test-gnc-optiondb.scm,v 1.1 2025/12/14 20:51:32 wiz Exp $

Guile 3.0.11 compatibility.
https://github.com/Gnucash/gnucash/pull/2158

--- bindings/guile/test/test-gnc-optiondb.scm.orig	2024-11-12 02:02:44.000000000 +0000
+++ bindings/guile/test/test-gnc-optiondb.scm
@@ -115,7 +115,7 @@
        option-db "waldo" "pepper" "baz"
        "Phony Option" acctlist (list ACCT-TYPE-BANK))
       (let ((acct-list (gnc-option-value option-db "waldo" "pepper")))
-        (test-equal #f (length acct-list))))))
+        (test-error 'wrong-type-arg (length acct-list))))))
 
   (define (test-make-account-sel-limited-option book)
     (test-group "test-make-account-list-option"
