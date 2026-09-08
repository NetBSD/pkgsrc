$NetBSD: patch-src_zenicb-history.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding
declare external variable
replace delete-backward-char with delete-region

--- src/zenicb-history.el.orig	1998-03-28 01:20:55.000000000 +0000
+++ src/zenicb-history.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-history.el --- keep a history of commands in ZenICB
 
 ;; Copyright (C) 1997 Faried Nawaz
@@ -38,6 +40,7 @@
   "*A list of commands run by the user.")
 (make-variable-buffer-local 'zenicb-history-list)
 
+(defvar zenicb-process) ; defined in zenicb.el
 ;; hairy variables to keep track of command
 (defvar zenicb-history-list-backward nil)
 (make-variable-buffer-local 'zenicb-history-list-backward)
@@ -66,7 +69,7 @@
     ; remove contents of line
     (beginning-of-line)
     (if (not (= (point) (point-max)))
-	(delete-backward-char (- (point) (point-max))))
+	(delete-region (point) (point-max)))
     ; insert previous command
     (insert (car zenicb-history-list-backward))
     ; update hairy variables
@@ -87,7 +90,7 @@
       ; remove contents of line
       (beginning-of-line)
       (if (not (= (point) (point-max)))
-	  (delete-backward-char (- (point) (point-max))))
+	  (delete-region (point) (point-max)))
       ; insert next command
       (insert (car zenicb-history-list-forward))
      ; update hairy variables
