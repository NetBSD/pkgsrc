$NetBSD: patch-lisp_bbdb-whois.el,v 1.1 2018/02/01 11:21:58 mef Exp $

:Warning: !! The file uses old-style backquotes !!
This functionality has been obsolete for more than 10 years already

--- lisp/bbdb-whois.el~	2007-01-31 07:08:33.000000000 +0900
+++ lisp/bbdb-whois.el	2018-02-01 12:58:26.952751936 +0900
@@ -25,10 +25,10 @@
 (defmacro bbdb-add-to-field (record field text)
   (let ((get (intern (concat "bbdb-record-" (symbol-name field))))
     (set (intern (concat "bbdb-record-set-" (symbol-name field)))))
-    (` (let ((old ((, get) (, record)))
+      `(let ((old ((, get) (, record)))
          (text (, text)))
      (or (member text old)
-         ((, set) (, record) (nconc old (list text))))))))
+         ((, set) (, record) (nconc old (list text)))))))
 
 (defcustom bbdb-whois-server (or (and (boundp 'whois-server) whois-server)
                                  "whois.geektools.com")
