$NetBSD: patch-gnucash_report_test_test-report-utilities.scm,v 1.1 2025/12/14 20:51:32 wiz Exp $

Guile 3.0.11 compatibility.
https://github.com/Gnucash/gnucash/pull/2158

--- gnucash/report/test/test-report-utilities.scm.orig	2025-08-03 21:16:36.000000000 +0000
+++ gnucash/report/test/test-report-utilities.scm
@@ -483,8 +483,8 @@
           (collector->list
            (gnc:select-assoc-account-balance account-balances bank)))
 
-        (test-equal "gnc:select-assoc-account-balance - miss"
-          #f
+        (test-error "gnc:select-assoc-account-balance - miss"
+          'wrong-type-arg
           (collector->list
            (gnc:select-assoc-account-balance account-balances expense)))
 
