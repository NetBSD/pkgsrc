$NetBSD: patch-lisp_bbdb-mhe.el,v 1.2 2018/02/01 11:21:58 mef Exp $

Make bbdb build with emacs-24.
(emacs-27):Warning: !! The file uses old-style backquotes !!
This functionality has been obsolete for more than 10 years already

--- lisp/bbdb-mhe.el.orig	2007-01-31 07:08:33.000000000 +0900
+++ lisp/bbdb-mhe.el	2018-02-01 13:22:21.336378903 +0900
@@ -37,7 +37,7 @@
 
 (defmacro bbdb/mh-cache-key (message)
   "Return a (numeric) key for MESSAGE"
-  (`(let* ((attrs (file-attributes (, message)))
+   `(let* ((attrs (file-attributes (, message)))
            (status-time (nth 6 attrs))
            (status-time-2 (cdr status-time))
            (inode (nth 10 attrs)))
@@ -50,7 +50,7 @@
               ;; return it as list.
               (if (integerp status-time-2)
                   status-time-2
-                (car status-time-2))))))
+                (car status-time-2)))))
 
 ;;;###autoload
 (defun bbdb/mh-update-record (&optional offer-to-create)
