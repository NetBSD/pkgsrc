$NetBSD: patch-hmac-md5.el,v 1.1 2023/09/03 14:58:38 mef Exp $

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./hmac-md5.el	2005-07-06 11:09:04.000000000 +0900
+++ ././hmac-md5.el	2020-09-05 16:02:39.899197296 +0900
@@ -1,4 +1,4 @@
-;;; hmac-md5.el --- Compute HMAC-MD5.
+;;; hmac-md5.el --- Compute HMAC-MD5.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1999, 2001  Free Software Foundation, Inc.
 
@@ -64,26 +64,13 @@
 ;;; Code:
 
 (eval-when-compile (require 'hmac-def))
-(require 'hex-util)			; (decode-hex-string STRING)
 (require 'md5)				; expects (md5 STRING)
 
 ;; To share *.elc files between Emacs w/ and w/o DL patch,
 ;; this check must be done at load-time.
-(cond
- ((fboundp 'md5-binary)
-  ;; do nothing.
-  )
- ((condition-case nil
-       ;; `md5' of v21 takes 4th arg CODING (and 5th arg NOERROR).
-       (md5 "" nil nil 'binary)		; => "d41d8cd98f00b204e9800998ecf8427e"
-     (wrong-number-of-arguments nil))
-  (defun md5-binary (string)
-    "Return the MD5 of STRING in binary form."
-   (decode-hex-string (md5 string nil nil 'binary))))
- (t
-  (defun md5-binary (string)
-    "Return the MD5 of STRING in binary form."
-   (decode-hex-string (md5 string)))))
+(defun md5-binary (string)
+  "Return the MD5 of STRING in binary form."
+  (secure-hash 'md5 string nil nil t))
 
 (define-hmac-function hmac-md5 md5-binary 64 16) ; => (hmac-md5 TEXT KEY)
 (define-hmac-function hmac-md5-96 md5-binary 64 16 96)
