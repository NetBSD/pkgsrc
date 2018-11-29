$NetBSD: patch-lisp_vm-pcrisis.el,v 1.1 2018/11/29 00:36:23 markd Exp $

remove  spurious &optional

--- lisp/vm-pcrisis.el.orig	2011-12-27 22:19:28.000000000 +0000
+++ lisp/vm-pcrisis.el
@@ -1214,7 +1214,7 @@ PROMPT argument and call this function i
 ;; Functions for vmpc-conditions:
 ;; -------------------------------------------------------------------
 
-(defun vmpc-none-true-yet (&optional &rest exceptions)
+(defun vmpc-none-true-yet (&rest exceptions)
   "True if none of the previous evaluated conditions was true.
 This is a condition that can appear in `vmpc-conditions'.  If EXCEPTIONS are
 specified, it means none were true except those.  For example, if you wanted
