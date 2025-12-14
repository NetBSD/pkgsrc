$NetBSD: patch-gnucash_report_test_test-commodity-utils.scm,v 1.1 2025/12/14 20:51:32 wiz Exp $

Guile 3.0.11 compatibility.
https://github.com/Gnucash/gnucash/pull/2158

--- gnucash/report/test/test-commodity-utils.scm.orig	2024-11-12 02:02:45.000000000 +0000
+++ gnucash/report/test/test-commodity-utils.scm
@@ -270,8 +270,8 @@
     (let* ((sumlist (list (list USD  (list (list AAPL  aapl-col)))
                           (list GBP (list (list RDSA rdsa-gbp-col)))))
            (return-alist  (gnc:resolve-unknown-comm sumlist USD)))
-      (test-equal "RDSA #f" #f ((caadr (assoc RDSA return-alist)) 'total #f))
-      (test-equal "RDSA #f" #f ((cdadr (assoc RDSA return-alist)) 'total #f)))
+      (test-error "RDSA #f" 'wrong-type-arg (((assoc RDSA return-alist)) 'total #f))
+      (test-error "RDSA #f" 'wrong-type-arg ((cdadr (assoc RDSA return-alist)) 'total #f)))
     (test-end "foreign-no-coll")
     (test-begin "foreign-no-amount")
     ;; There's a collector but it doesn't have a price in it so the returned
@@ -348,8 +348,8 @@
                           (list GBP (list (list DEM gbp-dem-col)
                                           (list RDSA rdsa-gbp-col)))))
            (return-alist  (gnc:resolve-unknown-comm sumlist USD)))
-      (test-equal "Shares fails" #f ((caadr (assoc RDSA return-alist)) 'total #f))
-      (test-equal "Value fails" #f ((cdadr (assoc RDSA return-alist)) 'total #f)))
+      (test-error "Shares fails" 'wrong-type-arg ((caadr (assoc RDSA return-alist)) 'total #f))
+      (test-error "Value fails" 'wrong-type-arg ((cdadr (assoc RDSA return-alist)) 'total #f)))
     (test-end "foreign-3way-gbp->dem->eur->usd")
     (test-begin "foreign-3way-DEM>GBP")
     ;; Three-way conversion, gbp->dem->eur->usd
@@ -359,8 +359,8 @@
                           (list DEM (list (list GBP dem-gbp-col)))
                           (list GBP (list (list RDSA rdsa-gbp-col)))))
            (return-alist  (gnc:resolve-unknown-comm sumlist USD)))
-      (test-equal "Shares fails" #f ((caadr (assoc RDSA return-alist)) 'total #f))
-      (test-equal "Value fails" #f ((cdadr (assoc RDSA return-alist)) 'total #f)))
+      (test-error "Shares fails" 'wrong-type-arg ((caadr (assoc RDSA return-alist)) 'total #f))
+      (test-error "Value fails" 'wrong-type-arg ((cdadr (assoc RDSA return-alist)) 'total #f)))
     (test-end "foreign-3way-DEM>GBP")
     (test-begin "foreign-DEM>EUR")
     ;; Three-way conversion, gbp->dem->eur
@@ -369,8 +369,8 @@
                           (list GBP (list (list DEM gbp-dem-col)
                                           (list RDSA rdsa-gbp-col)))))
            (return-alist  (gnc:resolve-unknown-comm sumlist EUR)))
-      (test-equal "Shares fails" #f ((caadr (assoc RDSA return-alist)) 'total #f))
-      (test-equal "Value fails" #f ((cdadr (assoc RDSA return-alist)) 'total #f)))
+      (test-error "Shares fails" 'wrong-type-arg ((caadr (assoc RDSA return-alist)) 'total #f))
+      (test-error "Value fails" 'wrong-type-arg ((cdadr (assoc RDSA return-alist)) 'total #f)))
     (test-end "foreign-DEM>EUR"))
 
   (teardown)))
@@ -753,9 +753,9 @@
            (exchange-fn
             (gnc:make-gnc-monetary AAPL 1)
             USD
-            (gnc-dmy2time64-neutral 20 02 2012)))))
+            (gnc-dmy2time64-neutral 20 02 2012))))))
 
-      (teardown))))
+      (teardown)))
 
 (define (test-get-match-commodity-splits-sorted)
   (test-group-with-cleanup "test-get-match-commodity-splits-sorted"
@@ -818,6 +818,6 @@
                       "2012-02-20" "2013-08-09" "2014-07-11" "2014-08-08"
                       "2014-08-08" "2014-12-05" "2014-12-05" "2015-04-02"
                       "2015-10-23" "2015-10-23" "2016-03-11" "2016-03-11")
-                    (map split->date all-splits)))
+                    (map split->date all-splits))))
 
-      (teardown))))
+      (teardown)))
