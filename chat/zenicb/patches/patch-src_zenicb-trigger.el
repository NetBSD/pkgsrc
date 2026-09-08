$NetBSD: patch-src_zenicb-trigger.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding
stop using old backquote syntax
fix arguments to function calls
use nick directly, there is no zenicb-extract-nick function

--- src/zenicb-trigger.el.orig	1998-03-28 00:47:30.000000000 +0000
+++ src/zenicb-trigger.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-trigger.el
 
 ;; Copyright (C) 1997 Noah S. Friedman
@@ -81,8 +83,8 @@ deactivating the trigger via /trigger subcommands."
          (cmdhook (intern (concat symname "-hook"))))
     (zenicb-add-hook cmdhook cmdsym)
     (fset cmdsym
-          (` (lambda (proc victim)
-               (zenicb-trigger-send-fn-result proc victim '(, response)))))))
+          `(lambda (proc victim)
+               (zenicb-trigger-send-fn-result proc victim '(, response))))))
 
 (defun zenicb-trigger-set-trigger (name regexp response &optional pass-string)
   (and (stringp name)
@@ -147,14 +149,15 @@ deactivating the trigger via /trigger subcommands."
                     (string-match regexp (aref parsedmsg 3))
                     (let ((victim (zenicb-trigger-parse-sender parsedmsg))
                           (msg (zenicb-trigger-response
-                                (nth 3 (car trigger-table)))))
+                                (nth 3 (car trigger-table))
+                                (aref parsedmsg 3))))
                       (zenicb-trigger-send-response proc victim msg)))))
         (setq trigger-table (cdr trigger-table))))))
 
 (defun zenicb-trigger-parse-sender (parsedmsg)
   (let ((from (aref parsedmsg 2)))
-    (cond ((zenicb-names-equal-p from zenicb-nick)
-           (zenicb-extract-nick (aref parsedmsg 1)))
+    (cond ((string= from zenicb-nick)
+           (aref parsedmsg 1))
           (t from))))
 
 (defun zenicb-trigger-response (fn msg)
@@ -178,7 +181,7 @@ deactivating the trigger via /trigger subcommands."
         (t
          (while msg
            (zenicb-message proc (format "[trigger] Sent to %s: %s\n" victim (car msg)))
-	   (zenicb-send-public proc ?b (car msg))
+	   (zenicb-send-public (car msg) proc)
            (setq msg (cdr msg))))))
 
 
@@ -295,4 +298,4 @@ deactivating the trigger via /trigger subcommands."
         (setq posn (match-end 0))))
     (nreverse list)))
 
-;;; zenicb-trigger.el ends here
\ No newline at end of file
+;;; zenicb-trigger.el ends here
