$NetBSD: patch-gnucash_report_test_test-html-chart.scm,v 1.1 2025/12/14 20:51:32 wiz Exp $

Guile 3.0.11 compatibility.
https://github.com/Gnucash/gnucash/pull/2158

--- gnucash/report/test/test-html-chart.scm.orig	2024-11-12 02:02:45.000000000 +0000
+++ gnucash/report/test/test-html-chart.scm
@@ -60,8 +60,8 @@
       'abc
       (gnc:html-chart-get chart '(options maintainAspectRatio)))
 
-    (test-equal "path doesn't exist"
-      #f
+    (test-error "path doesn't exist"
+      #t
       (gnc:html-chart-get chart '(options scales xAxes (0) time)))
 
     (gnc:html-chart-set! chart '(options scales xAxes (0) time) a-list-of-pairs)
@@ -77,11 +77,11 @@
 
     (test-error
      "1st level option fails - cannot traverse through existing path"
-     'invalid-path
+     'wrong-type-arg
      (gnc:html-chart-set! chart '(options legend position invalid) 'de))
 
-    (test-equal "deep nested new path - inexistent"
-      #f
+    (test-error "deep nested new path - nonexistent"
+      'invalid-path
       (gnc:html-chart-get chart '(create new nested path)))
 
     (gnc:html-chart-set! chart '(create new nested path) 'newpath)
@@ -115,6 +115,6 @@
 
     (test-error
      "deep nested new path - cannot set 6th index"
-     'error
+     'index-too-high
      (gnc:html-chart-set! chart '(create list-kth (6) nested path) 'k4th))
     ))
