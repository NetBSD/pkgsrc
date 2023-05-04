$NetBSD: patch-riece-shrink-buffer.el,v 1.2 2023/05/04 14:58:16 hauke Exp $

riece-shrink-buffer.el:70:29:Warning: Use `with-current-buffer' rather than
    save-excursion+set-buffer

From upstream's <http://git.savannah.nongnu.org/cgit/riece.git/commit/lisp/riece-shrink-buffer.el?id=b4088b67b9007699a2d59a4fa6fd334a60a1c84d>

--- lisp/riece-shrink-buffer.el~	2011-04-04 15:46:44.000000000 +0900
+++ lisp/riece-shrink-buffer.el	2014-06-15 22:01:10.000000000 +0900
@@ -68,8 +68,9 @@
       (setq buffers (cdr buffers)))))
 
 (defun riece-shrink-buffer (buffer)
-  (save-excursion
-    (set-buffer buffer)
+;  (save-excursion
+;    (set-buffer buffer)
+  (with-current-buffer buffer
     (goto-char (point-min))
     (while (> (buffer-size) riece-max-buffer-size)
       (let* ((inhibit-read-only t)
