$NetBSD: patch-lisp_bbdb-com.el,v 1.1 2018/02/01 11:21:58 mef Exp $

:Warning: !! The file uses old-style backquotes !!
This functionality has been obsolete for more than 10 years already

--- lisp/bbdb-com.el~	2007-01-31 07:09:25.000000000 +0900
+++ lisp/bbdb-com.el	2018-02-01 12:57:45.799555302 +0900
@@ -124,7 +124,7 @@ If you want to reverse the search, bind 
     (if phone
         (setq clauses
               (cons
-               (` (let ((rest-of-phones (bbdb-record-phones record))
+                `(let ((rest-of-phones (bbdb-record-phones record))
                         (done nil))
                     (if rest-of-phones
                         (while (and rest-of-phones (not done))
@@ -136,7 +136,7 @@ If you want to reverse the search, bind 
                       ;; so that "^$" can be used to find entries that
                       ;; have no phones
                       (setq done (string-match (, phone) "")))
-                    done))
+                    done)
                clauses)))
     (if notes
         (setq clauses
