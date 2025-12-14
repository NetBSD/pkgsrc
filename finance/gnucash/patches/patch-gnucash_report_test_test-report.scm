$NetBSD: patch-gnucash_report_test_test-report.scm,v 1.1 2025/12/14 20:51:32 wiz Exp $

Guile 3.0.11 compatibility.
https://github.com/Gnucash/gnucash/pull/2158

--- gnucash/report/test/test-report.scm.orig	2025-08-03 21:16:36.000000000 +0000
+++ gnucash/report/test/test-report.scm
@@ -195,8 +195,8 @@
     (test-equal "gnc:report-name"
       "basic report"
       (gnc:report-name report))
-    (test-equal "gnc:report-stylesheet"
-      #f
+    (test-error "gnc:report-stylesheet"
+      'wrong-type-arg
       (gnc:report-stylesheet report))
     (test-equal "(gnc:all-report-template-guids)"
       4
