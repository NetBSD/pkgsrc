$NetBSD: patch-mime-parse.el,v 1.1 2021/05/11 02:05:07 mef Exp $

sting-to-int is obsolete function since emacs-26

--- mime-parse.el.orig	2005-07-06 11:09:04.000000000 +0900
+++ mime-parse.el	2021-05-11 10:55:39.987654397 +0900
@@ -97,7 +97,7 @@ be the result."
     (insert text)
     (goto-char (point-min))
     (while (re-search-forward "%[0-9A-Fa-f][0-9A-Fa-f]" nil t)
-      (insert (prog1 (string-to-int
+      (insert (prog1 (string-to-number
 		      (buffer-substring (point)(- (point) 2))
 		      16)
                 (delete-region (point)(- (point) 3)))))
@@ -147,7 +147,7 @@ property of the decoded-value."
           (let* ((attribute (downcase
 			     (substring (car params) 0 (match-end 1))))
                  (section (if (match-beginning 2)
-			      (string-to-int
+			      (string-to-number
 			       (substring (car params)
 					  (1+ (match-beginning 2))
 					  (match-end 2)))
