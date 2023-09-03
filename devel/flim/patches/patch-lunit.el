$NetBSD: patch-lunit.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/lunit.el	2005-07-06 11:09:04.000000000 +0900
+++ ./lunit.el	2023-08-31 08:29:38.593841638 +0900
@@ -1,4 +1,4 @@
-;;; lunit.el --- simple testing framework for luna
+;;; lunit.el --- simple testing framework for luna  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 2000 Daiki Ueno.
 
@@ -52,8 +52,6 @@
 
 (require 'luna)
 
-(eval-when-compile (require 'cl))
-
 ;;; @ test
 ;;;
 
@@ -175,14 +173,14 @@
 NAME is name of the method to be tested."
   (luna-make-entity class :name name))
 
-(luna-define-method lunit-test-number-of-tests ((case lunit-test-case))
+(luna-define-method lunit-test-number-of-tests ((_case lunit-test-case))
   1)
 
 (luna-define-method lunit-test-run ((case lunit-test-case) result)
   (lunit-test-result-run result case))
 
-(luna-define-method lunit-test-case-setup ((case lunit-test-case)))
-(luna-define-method lunit-test-case-teardown ((case lunit-test-case)))
+(luna-define-method lunit-test-case-setup ((_case lunit-test-case)))
+(luna-define-method lunit-test-case-teardown ((_case lunit-test-case)))
 
 (luna-define-method lunit-test-case-run ((case lunit-test-case))
   (lunit-test-case-setup case)
@@ -242,21 +240,22 @@
 
 (luna-define-class lunit-test-printer (lunit-test-listener))
 
-(luna-define-method lunit-test-listener-error ((printer lunit-test-printer)
-					       case error)
+(luna-define-method lunit-test-listener-error ((_printer lunit-test-printer)
+					       _case error)
   (princ (format " error: %S" error)))
 
-(luna-define-method lunit-test-listener-failure ((printer lunit-test-printer)
-						 case failure)
+(luna-define-method lunit-test-listener-failure ((_printer lunit-test-printer)
+						 _case failure)
   (princ (format " failure: %S" failure)))
 
-(luna-define-method lunit-test-listener-start ((printer lunit-test-printer)
+(luna-define-method lunit-test-listener-start ((_printer lunit-test-printer)
 					       case)
   (princ (format "Running `%S#%S'..."
 		 (luna-class-name case)
 		 (lunit-test-name-internal case))))
 
-(luna-define-method lunit-test-listener-end ((printer lunit-test-printer) case)
+(luna-define-method
+  lunit-test-listener-end ((_printer lunit-test-printer) _case)
   (princ "\n"))
 
 (defun lunit-make-test-suite-from-class (class)
@@ -301,8 +300,7 @@
 
 (defun lunit-generate-template (file)
   (interactive "fGenerate lunit template for: ")
-  (save-excursion
-    (set-buffer (find-file-noselect file))
+  (with-current-buffer (find-file-noselect file)
     (let ((index-alist 
 	   (lunit-create-index-function)))
       (with-output-to-temp-buffer "*Lunit template*"
