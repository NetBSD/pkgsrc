$NetBSD: patch-src_interp_patches.lisp,v 1.1 2012/04/01 20:48:39 asau Exp $

Silence warnings to make it build with CLISP on NetBSD/amd64
(perhaps on other amd64 systems too).

--- src/interp/patches.lisp.orig	2011-07-07 19:04:13.000000000 +0000
+++ src/interp/patches.lisp
@@ -33,11 +33,12 @@
 
 (import-module "macros")
 (import-module "g-timer")
+#+clisp (eval-when (:compile-toplevel :load-toplevel) (setf custom:*suppress-check-redefinition* t))
 (import-module "sys-driver")
 (in-package "BOOT")
 ;;patches for now
 
-(defun CATCHALL (a &rest b) a) ;; not correct but ok for now
+(defun CATCHALL (a &rest b) (declare (ignore b)) a) ;; not correct but ok for now
 (defvar |$demoFlag| nil)
 
 (define-function '|construct| #'list) ;; NEEDED , SPAD-COMPILER generated Lisp code
@@ -58,7 +59,7 @@
 ;; call lisp::unwind whereas it is defined (in this file) to be
 ;; interned in the boot package. We've returned toplevel to its
 ;; previous definition.
-(defun toplevel (&rest foo) (throw '|top_level| '|restart|))
+(defun toplevel (&rest foo) (declare (ignore foo)) (throw '|top_level| '|restart|))
 ;;(defun toplevel (&rest foo) (lisp::unwind))
 
 (define-function 'top-level #'toplevel)
@@ -69,15 +70,15 @@
 #+(and :GCL :IEEE-FLOATING-POINT )
  (setq system:*print-nans* T)
 
-(defun /RF (&rest foo &aux (|$Echo| 'T))
+(defun /RF (&rest foo &aux (|$Echo| 'T)) (declare (ignore foo))
   (declare (special |$Echo|))
   (/RF-1 nil))
 
-(defun /RQ (&rest foo &aux (|$Echo| nil))
+(defun /RQ (&rest foo &aux (|$Echo| nil)) (declare (ignore foo))
   (declare (special |$Echo|))
   (/RF-1 nil))
 
-(defun |/RQ,LIB| (&rest foo &aux (|$Echo| nil) ($LISPLIB T))
+(defun |/RQ,LIB| (&rest foo &aux (|$Echo| nil) ($LISPLIB T)) (declare (ignore foo))
   (declare (special |$Echo| $LISPLIB))
   (/RF-1 nil))
 
@@ -99,10 +100,10 @@
       (|ncINTERPFILE| input-file |$Echo|))
      (t (spad input-file)))))
 
-(defun /EF (&rest foo)
+(defun /EF (&rest foo) (declare (ignore foo))
   (|runCommand| (concat "vi " (namestring (make-input-filename /EDITFILE)))))
 
-(defun SHAREDITEMS (x) T) ;;checked in history code
+(defun SHAREDITEMS (x) (declare (ignore x)) T) ;;checked in history code
 
 (defun GETZEROVEC (n) (MAKE-ARRAY n :initial-element 0))
 
@@ -116,11 +117,11 @@
 
 ;; following are defined in spadtest.boot and stantest.boot
 (defun |installStandardTestPackages| () ())
-(defun |spadtestValueHook| (val type) ())
-(defun |testError| (errotype erroValue) ())
+(defun |spadtestValueHook| (val type) (declare (ignore val type)) ())
+(defun |testError| (errotype erroValue) (declare (ignore errotype erroValue)) ())
 (defvar |$TestOptions| ())
 ;; following in defined in word.boot
-(defun |bootFind| (word) ())
+(defun |bootFind| (word) (declare (ignore word)) ())
 
 (defvar *msghash* nil "hash table keyed by msg number")
 
