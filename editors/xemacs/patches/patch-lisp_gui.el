$NetBSD: patch-lisp_gui.el,v 1.1 2017/01/24 20:31:14 hauke Exp $

Do not call xemacs-package functions from standalone xemacs
without checking they are aveilable.

--- lisp/gui.el.orig	2015-03-25 11:25:33.000000000 +0000
+++ lisp/gui.el
@@ -117,7 +117,11 @@ When ACTION is called, the buffer contai
 (defun insert-gui-button (button &optional pos buffer)
   "Insert GUI button BUTTON at POS in BUFFER."
   (check-argument-type 'gui-button-p button)
-  (make-annotation (make-glyph button)
-			       pos 'text buffer nil))
+  ;; make-annotation is from xemacs-packages lisp/xemacs-base/annotations.el
+  ;; so not available for standalone, package-less XEmacs
+  (if (fboundp 'make-annotation) 
+      (make-annotation (make-glyph button)
+		       pos 'text buffer nil)
+    (make-glyph button)))
 
 ;;; gui.el ends here
