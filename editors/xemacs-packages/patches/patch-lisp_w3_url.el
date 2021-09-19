$NetBSD: patch-lisp_w3_url.el,v 1.2 2021/09/19 14:53:15 hauke Exp $

Provide buffer-local-value for the sake of XEmacs 21.4

--- lisp/w3/url.el.orig	2015-12-14 21:38:21.000000000 +0000
+++ lisp/w3/url.el
@@ -57,6 +57,17 @@
   :type 'directory
   :group 'url)
 
+(if (not (fboundp 'buffer-local-value))
+    (defun url-buffer-local-value (sym buffer)
+      "Get the buffer-local value of variable SYM in BUFFER. If there
+is no buffer-local value in BUFFER then the global value of SYM is
+used."
+      (buffer-local-value sym buffer)
+      (or (cdr (assoc sym (buffer-local-variables buffer)))
+	  (save-excursion
+	    (set-buffer buffer)
+	    (symbol-value sym)))))
+
 (defun url-do-setup ()
   "Setup the URL package.
 This is to avoid conflict with user settings if URL is dumped with
