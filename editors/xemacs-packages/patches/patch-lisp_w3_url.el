$NetBSD: patch-lisp_w3_url.el,v 1.1 2019/07/31 14:04:40 hauke Exp $

Provide buffer-local-value for the sake of XEmacs 21.4

--- lisp/w3/url.el.orig	2015-12-14 21:38:21.000000000 +0000
+++ lisp/w3/url.el
@@ -57,6 +57,16 @@
   :type 'directory
   :group 'url)
 
+(defun url-buffer-local-value (sym buffer)
+  "Get the buffer-local value of variable SYM in BUFFER. If there is no
+buffer-local value in BUFFER then the global value of SYM is used."
+  (if (fboundp 'buffer-local-value)
+      (buffer-local-value sym buffer)
+    (or (cdr (assoc sym (buffer-local-variables buffer)))
+        (save-excursion
+          (set-buffer buffer)
+          (symbol-value sym)))))
+
 (defun url-do-setup ()
   "Setup the URL package.
 This is to avoid conflict with user settings if URL is dumped with
@@ -256,10 +266,10 @@ no further processing).  URL is either a
 	  (url-debug 'retrieval
 		     "Spinning in url-retrieve-synchronously: %S (%S)"
 		     retrieval-done asynch-buffer)
-          (if (buffer-local-value 'url-redirect-buffer asynch-buffer)
+          (if (url-buffer-local-value 'url-redirect-buffer asynch-buffer)
               (setq proc (get-buffer-process
                           (setq asynch-buffer
-                                (buffer-local-value 'url-redirect-buffer
+                                (url-buffer-local-value 'url-redirect-buffer
                                                     asynch-buffer))))
             (if (and proc (memq (process-status proc)
                                 '(closed exit signal failed))
