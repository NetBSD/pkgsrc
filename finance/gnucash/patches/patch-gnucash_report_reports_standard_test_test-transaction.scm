$NetBSD: patch-gnucash_report_reports_standard_test_test-transaction.scm,v 1.1 2025/12/14 20:51:32 wiz Exp $

Guile 3.0.11 compatibility.
https://github.com/Gnucash/gnucash/pull/2158

--- gnucash/report/reports/standard/test/test-transaction.scm.orig	2025-09-27 21:44:20.000000000 +0000
+++ gnucash/report/reports/standard/test/test-transaction.scm
@@ -1067,7 +1067,7 @@
      '(("from" "01/01/2010")
        ("to" "31/12/2010")
        ("total" 23500 30000 25/7 sym))))
-  (test-error "gnc:lists->csv improper list"
+  (test-error "gnc:lists->csv improper list" #t
     (gnc:lists->csv
      '(("from" "01/01/2010")
        ("to" "31/12/2010")
