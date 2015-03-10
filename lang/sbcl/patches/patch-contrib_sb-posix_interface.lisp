$NetBSD: patch-contrib_sb-posix_interface.lisp,v 1.1 2015/03/10 20:50:37 asau Exp $

--- contrib/sb-posix/interface.lisp.orig	2015-02-27 10:49:46.000000000 +0000
+++ contrib/sb-posix/interface.lisp
@@ -100,8 +100,8 @@
 ;;; variable.
 (eval-when (:compile-toplevel :load-toplevel)
   (setf *c-functions-in-runtime*
-        '`(#+netbsd ,@("stat" "lstat" "fstat" "readdir" "opendir"))))
-
+        #+netbsd '("stat" "lstat" "fstat" "readdir" "opendir")
+        #-netbsd '()))
 
 ;;; filesystem access
 (defmacro define-call* (name &rest arguments)
