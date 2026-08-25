$NetBSD: patch-lisp_net_tramp.el,v 1.1 2026/08/25 17:44:23 wiz Exp $

CVE-2026-79992: Fix local command execution vulnerability in tramp
https://gitweb.gentoo.org/proj/emacs-patches.git/commit/emacs/30.2/05_all_tramp.patch?id=2a6292f81affedcc468c594c60808e652ae87118

--- lisp/net/tramp.el.orig	2025-05-10 11:38:42.000000000 +0000
+++ lisp/net/tramp.el
@@ -973,11 +973,11 @@ Used in `tramp-make-tramp-file-name'.")
 
 (defun tramp-build-prefix-regexp ()
   "Return `tramp-prefix-regexp'."
-  (rx bol (literal (tramp-build-prefix-format))))
+  (rx bos (literal (tramp-build-prefix-format))))
 
 (defvar tramp-prefix-regexp nil ; Initialized when defining `tramp-syntax'!
   "Regexp matching the very beginning of Tramp file names.
-Should always start with \"^\".  Derived from `tramp-prefix-format'.")
+Should always start with \"\\\\=`\".  Derived from `tramp-prefix-format'.")
 
 (defconst tramp-method-regexp-alist
   `((default . ,(rx (| (literal tramp-default-method-marker) (>= 2 alnum))))
@@ -1019,7 +1019,10 @@ Derived from `tramp-postfix-method-format'.")
   "Regexp matching delimiter between method and user or host names.
 Derived from `tramp-postfix-method-format'.")
 
-(defconst tramp-user-regexp (rx (+ (not (any "/:|" blank))))
+(defconst tramp-user-regexp
+  (rx (| (+ (not (any "/\\^$?*:;|[]{}()<>`'\"" blank)))
+	 ;; Environment variable.
+	 (: "$" (+ (any "_" alnum)))))
   "Regexp matching user names.")
 
 (defconst tramp-prefix-domain-format "%"
@@ -1801,6 +1804,8 @@ default values are used."
 	    (hop       (match-string (nth 5 tramp-file-name-structure) name))
 	    domain port v)
 	(when user
+	  (while (string-match (rx bos "$" (group (+ (any "_" alnum))) eos) user)
+	    (setq user (getenv (match-string 1 user))))
 	  (when (string-match tramp-user-with-domain-regexp user)
 	    (setq domain (match-string 2 user)
 		  user (match-string 1 user))))
@@ -2491,9 +2496,9 @@ Fall back to normal file name handler if no Tramp file
 	;; `file-remote-p' is called for everything, even for symbolic
 	;; links which look remote.  We don't want to get an error.
 	(non-essential (or non-essential (eq operation 'file-remote-p))))
+    (setq filename (tramp-replace-environment-variables filename))
     (if (tramp-tramp-file-p filename)
 	(save-match-data
-          (setq filename (tramp-replace-environment-variables filename))
           (with-parsed-tramp-file-name filename nil
             (let ((current-connection tramp-current-connection)
 		  (foreign
@@ -6537,6 +6542,9 @@ to cache the result.  Return the modified ATTR."
 			       (caar attr))
 			      (decode-coding-string
 			       (match-string 1 (caar attr)) 'utf-8))))
+	       ;; Quote remote-like symlink.
+	       (when (and (stringp (car attr)) (tramp-tramp-file-p (car attr)))
+		 (setcar attr (file-name-quote (car attr) 'top)))
 	       ;; Set file's gid change bit.
 	       (setcar
 		(nthcdr 9 attr)
