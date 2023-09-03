$NetBSD: patch-luna.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/luna.el	2005-07-06 11:09:04.000000000 +0900
+++ ./luna.el	2023-08-31 08:29:38.593059572 +0900
@@ -1,4 +1,4 @@
-;;; luna.el --- tiny OOP system kernel
+;;; luna.el --- tiny OOP system kernel  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1999,2000,2002 Free Software Foundation, Inc.
 
@@ -24,9 +24,6 @@
 
 ;;; Code:
 
-(eval-when-compile (require 'cl))
-
-
 ;;; @ class
 ;;;
 
@@ -68,13 +65,11 @@
 
 (defun luna-define-class-function (class &optional parents slots)
   (let ((oa (make-vector 31 0))
-	(rest parents)
-	parent name
+	name
 	(i 2)
 	b j)
-    (while rest
-      (setq parent (pop rest)
-	    b (- i 2))
+    (dolist (parent parents)
+      (setq b (- i 2))
       (mapatoms (lambda (sym)
 		  (when (setq j (get sym 'luna-slot-index))
 		    (setq name (symbol-name sym))
@@ -82,9 +77,8 @@
 		      (put (intern name oa) 'luna-slot-index (+ j b))
 		      (setq i (1+ i)))))
 		(luna-class-obarray (luna-find-class parent))))
-    (setq rest slots)
-    (while rest
-      (setq name (symbol-name (pop rest)))
+    (dolist (slot slots)
+      (setq name (symbol-name slot))
       (unless (intern-soft name oa)
 	(put (intern name oa) 'luna-slot-index i)
 	(setq i (1+ i))))
@@ -95,9 +89,11 @@
 ;; MEMBER-NAME.
 
 (defun luna-class-find-member (class member-name)
-  (or (stringp member-name)
-      (setq member-name (symbol-name member-name)))
-  (intern-soft member-name (luna-class-obarray class)))
+  (intern-soft
+   (if (stringp member-name)
+       member-name
+     (symbol-name member-name))
+   (luna-class-obarray class)))
 
 
 ;; Return a member (slot or method) of CLASS that has name
@@ -105,9 +101,11 @@
 ;; CLASS.
 
 (defsubst luna-class-find-or-make-member (class member-name)
-  (or (stringp member-name)
-      (setq member-name (symbol-name member-name)))
-  (intern member-name (luna-class-obarray class)))
+  (intern
+   (if (stringp member-name)
+       member-name
+     (symbol-name member-name))
+   (luna-class-obarray class)))
 
 
 ;; Return the index number of SLOT-NAME in CLASS.
@@ -220,6 +218,9 @@
 ;;; @ instance (entity)
 ;;;
 
+(defvar luna-next-methods nil)
+(defvar luna-current-method-arguments nil)
+
 (defmacro luna-class-name (entity)
   "Return class-name of the ENTITY."
   `(aref ,entity 0))
@@ -230,8 +231,8 @@
 (defmacro luna-get-obarray (entity)
   `(aref ,entity 1))
 
-(defmacro luna-set-obarray (entity obarray)
-  `(aset ,entity 1 ,obarray))
+(defmacro luna-set-obarray (entity array)
+  `(aset ,entity 1 ,array))
 
 (defmacro luna-slot-index (entity slot-name)
   `(luna-class-slot-index (luna-find-class (luna-class-name ,entity))
@@ -249,12 +250,13 @@
   `(luna-class-find-functions (luna-find-class (luna-class-name ,entity))
 			      ,service))
 
-(defsubst luna-send (entity message &rest luna-current-method-arguments)
+(defsubst luna-send (entity message &rest arguments)
   "Send MESSAGE to ENTITY, and return the result.
 ENTITY is an instance of a luna class, and MESSAGE is a method name of
 the luna class.
-LUNA-CURRENT-METHOD-ARGUMENTS is arguments of the MESSAGE."
-  (let ((luna-next-methods (luna-find-functions entity message))
+ARGUMENTS is arguments of the MESSAGE."
+  (let ((luna-current-method-arguments arguments)
+	(luna-next-methods (luna-find-functions entity message))
 	luna-current-method
 	luna-previous-return-value)
     (while (and luna-next-methods
@@ -269,10 +271,6 @@
 		    t))))
     luna-previous-return-value))
 
-(eval-when-compile
-  (defvar luna-next-methods nil)
-  (defvar luna-current-method-arguments nil))
-
 (defun luna-call-next-method ()
   "Call the next method in the current method function.
 A method function that has :around qualifier should call this function
@@ -307,10 +305,11 @@
 ;;;
 
 ;; Find a method of ENTITY that handles MESSAGE, and call it with
-;; arguments LUNA-CURRENT-METHOD-ARGUMENTS.
+;; arguments ARGUMENTS.
 
-(defun luna-apply-generic (entity message &rest luna-current-method-arguments)
-  (let* ((class (luna-class-name entity))
+(defun luna-apply-generic (entity message &rest arguments)
+  (let* ((luna-current-method-arguments arguments)
+	 (class (luna-class-name entity))
 	 (cache (get message 'luna-method-cache))
 	 (sym (intern-soft (symbol-name class) cache))
 	 luna-next-methods)
