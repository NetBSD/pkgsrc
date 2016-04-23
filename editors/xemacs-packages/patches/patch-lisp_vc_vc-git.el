$NetBSD: patch-lisp_vc_vc-git.el,v 1.2 2016/04/23 09:24:07 hauke Exp $

Instead of blindly assuming a utf-8 capable XEmacs, look at the
current buffer for the encoding to use.

--- lisp/vc/vc-git.el.orig	2007-08-23 21:27:53.000000000 +0000
+++ lisp/vc/vc-git.el
@@ -35,7 +35,19 @@
 
 (eval-when-compile (require 'cl))
 
-(defvar git-commits-coding-system 'utf-8
+(defun vc-git-determine-coding-system ()
+
+  "Return utf-8 on 21.5, or the current buffer's encoding on 21.4"
+
+  (if (and (featurep 'xemacs)
+	   (<= emacs-major-version 21)
+	   (<  emacs-minor-version 5))
+      (if (boundp 'buffer-file-coding-system)
+	  buffer-file-coding-system
+	'undecided)
+    'utf-8))
+
+(defvar git-commits-coding-system (vc-git-determine-coding-system)
   "Default coding system for git commits.")
 
 (defun vc-git--run-command-string (file &rest args)
