$NetBSD: patch-src_zenicb-example.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding
string-to-int has been replaced by string-to-number

--- src/zenicb-example.el.orig	1998-07-19 22:12:55.000000000 +0000
+++ src/zenicb-example.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-example.el --- Example customizations for zenicb.el
 
 ;;; Copyright (C) 1997, 1998 Faried Nawaz
@@ -90,11 +92,11 @@
 (load-library "zenicb-stamp")
 
 ;;; fsf emacs doesn't have read-passwd
-(cond ((= (string-to-int emacs-version) 18)
+(cond ((= (string-to-number emacs-version) 18)
        (fset 'read-passwd 'read-from-minibuffer))
       ((not (string-match "XEmacs" emacs-version))
        (require 'ange-ftp)
        (fset 'read-passwd 'ange-ftp-read-passwd)))
 
 ;; this is the second last line of the file, the next line is the last one
-(load-library "zenicb")
\ No newline at end of file
+(load-library "zenicb")
