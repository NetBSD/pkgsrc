$NetBSD: patch-its.el,v 1.1 2025/12/27 12:44:02 mef Exp $

--- egg/wnn.elc ---
egg/wnn.el:34:11: Error: Wrong type argument: obarrayp, [nil nil nil ...

Fix from FreeBSD ports

--- its.el
+++ its.el
@@ -695,7 +695,7 @@ This variable override `its-delete-by-keystroke'."
 
 (defun its-map-compaction (map)
   (if its-compaction-enable
-      (let ((its-compaction-hash-table (make-vector 1000 nil))
+      (let ((its-compaction-hash-table (obarray-make 1000))
 	    (its-compaction-integer-table (make-vector 138 nil))
 	    (its-compaction-counter-1 1)
 	    (its-compaction-counter-2 0)
@@ -1357,8 +1357,8 @@ Return last state."
   (interactive)
   (its-convert (lambda (str lang) (japanese-katakana str))))
 
-(defconst its-full-half-table (make-vector 100 nil))
-(defconst its-half-full-table (make-vector 100 nil))
+(defconst its-full-half-table (obarray-make 100))
+(defconst its-half-full-table (obarray-make 100))
 
 (let ((table '((Japanese
 		(?　 . ?\ ) (?， . ?,)  (?． . ?.)  (?、 . ?,)  (?。 . ?.)
@@ -1468,7 +1468,6 @@ Return last state."
 		(?ｐ . ?p)  (?ｑ . ?q)  (?ｒ . ?r)  (?ｓ . ?s)  (?ｔ . ?t)
 		(?ｕ . ?u)  (?ｖ . ?v)  (?ｗ . ?w)  (?ｘ . ?x)  (?ｙ . ?y)
 		(?ｚ . ?z))))
-      (hash (make-vector 100 nil))
       lang pair)
   (while table
     (setq lang (caar table)
@@ -1480,8 +1479,7 @@ Return last state."
       (set (intern (concat (symbol-name lang) (char-to-string (cdar pair)))
 		   its-half-full-table)
 	   (caar pair))
-      (setq pair (cdr pair)))
-    hash))
+      (setq pair (cdr pair)))))
 
 ;;; its-half-width : half-width-region for input-buffer
 (defun its-half-width ()
