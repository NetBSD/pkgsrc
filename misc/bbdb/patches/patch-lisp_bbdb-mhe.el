$NetBSD: patch-lisp_bbdb-mhe.el,v 1.1 2011/10/11 19:30:40 minskim Exp $

Make bbdb build with emacs-24.

--- lisp/bbdb-mhe.el.orig	2001-08-31 15:07:47.000000000 +0000
+++ lisp/bbdb-mhe.el
@@ -37,7 +37,7 @@
 
 (defmacro bbdb/mh-cache-key (message)
   "Return a (numeric) key for MESSAGE"
-  (`(let* ((attrs (file-attributes (, message)))
+  ( ` (let* ((attrs (file-attributes (, message)))
            (status-time (nth 6 attrs))
            (status-time-2 (cdr status-time))
            (inode (nth 10 attrs)))
