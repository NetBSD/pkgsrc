$NetBSD: patch-sha1.el,v 1.1 2023/09/03 14:58:39 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/sha1.el	2005-07-06 11:09:05.000000000 +0900
+++ ./sha1.el	2023-08-31 08:29:38.620927012 +0900
@@ -1,4 +1,4 @@
-;;; sha1.el --- SHA1 Secure Hash Algorithm.
+;;; sha1.el --- SHA1 Secure Hash Algorithm.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1999, 2001  Free Software Foundation, Inc.
 
@@ -38,26 +38,7 @@
 
 ;;; Code:
 
-(defvar sha1-dl-module
-  (cond
-   ((and (fboundp 'sha1)
-	 (subrp (symbol-function 'sha1)))
-    nil)
-   ((fboundp 'dynamic-link)
-    ;; Should we take care of `dynamic-link-path'?
-    (let ((path (expand-file-name "sha1.so" exec-directory)))
-      (if (file-exists-p path)
-	  path
-	nil)))
-   (t
-    nil)))
-
-(cond
- ((and (stringp sha1-dl-module)
-       (file-exists-p sha1-dl-module))
-  (require 'sha1-dl))
- (t
-  (require 'sha1-el)))
+(defvar sha1-dl-module nil)
 
 (provide 'sha1)
 
