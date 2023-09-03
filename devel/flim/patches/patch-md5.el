$NetBSD: patch-md5.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/md5.el	2005-07-06 11:09:04.000000000 +0900
+++ ./md5.el	2023-08-31 08:29:38.594519992 +0900
@@ -1,4 +1,4 @@
-;;; md5.el --- MD5 Message Digest Algorithm.
+;;; md5.el --- MD5 Message Digest Algorithm.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1999, 2001  Free Software Foundation, Inc.
 
@@ -49,30 +49,7 @@
 
 ;;; Code:
 
-(defvar md5-dl-module
-  (cond
-   ((and (fboundp 'md5)
-	 (subrp (symbol-function 'md5)))
-    nil)
-   ((fboundp 'dynamic-link)
-    ;; Should we take care of `dynamic-link-path'?
-    (let ((path (expand-file-name "md5.so" exec-directory)))
-      (if (file-exists-p path)
-	  path
-	nil)))
-   (t
-    nil)))
-
-(cond
- ((and (fboundp 'md5)
-       (subrp (symbol-function 'md5)))
-  ;; do nothing.
-  )
- ((and (stringp md5-dl-module)
-       (file-exists-p md5-dl-module))
-  (require 'md5-dl))
- (t
-  (require 'md5-el)))
+(defvar md5-dl-module nil)
 
 (provide 'md5)
 
