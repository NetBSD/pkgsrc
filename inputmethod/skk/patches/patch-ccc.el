$NetBSD: patch-ccc.el,v 1.1 2022/07/04 14:40:40 ryoon Exp $

Support editors/emacs28 from upstream.

--- ccc.el.orig	2022-06-29 16:13:31.750892894 +0000
+++ ccc.el
@@ -3,10 +3,11 @@
 ;; Copyright (C) 2000 Masatake YAMATO <masata-y@is.aist-nara.ac.jp>
 ;; Copyright (C) 2001, 2002, 2004, 2005,
 ;;   2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014,
-;;   2015, SKK Development Team <skk@ring.gr.jp>
+;;   2015, SKK Development Team
 
 ;; Author: Masatake YAMATO <masata-y@is.aist-nara.ac.jp>
-;; Maintainer: SKK Development Team <skk@ring.gr.jp>
+;; Maintainer: SKK Development Team
+;; URL: https://github.com/skk-dev/ddskk
 ;; URL: https://github.com/skk-dev/ddskk/blob/master/READMEs/README.ccc.org
 ;; Keywords: cursor
 
@@ -34,6 +35,8 @@
 
 ;;; Code:
 
+(require 'faces)                        ; read-color, color-values
+
 (eval-when-compile
   (require 'advice))
 
@@ -111,10 +114,19 @@
 
 ;; Functions.
 (defsubst ccc-read-color (prompt)
-  (list (facemenu-read-color prompt)))
+  (list (read-color prompt)))
 
 (defsubst ccc-color-equal (a b)
-  (facemenu-color-equal a b))
+  "Return t if colors A and B are the same color.
+A and B should be strings naming colors.
+This function queries the display system to find out what the color
+names mean.  It returns nil if the colors differ or if it can't
+determine the correct answer.
+
+This function is the same as `facemenu-color-equal'"
+  (cond
+   ((equal a b) t)
+   ((equal (color-values a) (color-values b)))))
 
 (defun ccc-setup-new-frame (frame)
   (ccc-set-frame-cursor-color frame (or (ccc-default-cursor-color)
