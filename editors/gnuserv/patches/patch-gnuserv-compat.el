$NetBSD: patch-gnuserv-compat.el,v 1.1 2023/09/09 22:58:51 mef Exp $

old-style-backquote

--- gnuserv-compat.el.orig	2003-05-09 10:26:42.000000000 +0900
+++ gnuserv-compat.el	2023-09-09 18:28:42.549473704 +0900
@@ -193,9 +193,9 @@ undefined.  On Unix it is obtained from 
     (defmacro defgroup (&rest args)
       nil)
     (defmacro defcustom (var value doc &rest args)
-      (` (defvar (, var) (, value) (, doc))))
+       ` (defvar  , var   , value   , doc ) )
     (defmacro defface (var value doc &rest args)
-      (` (make-face (, var))))
+       ` (make-face (, var)) )
     (defmacro define-widget (&rest args)
       nil)))
 
