$NetBSD: patch-lisp_net_tramp-rclone.el,v 1.1 2026/08/25 17:44:23 wiz Exp $

CVE-2026-79992: Fix local command execution vulnerability in tramp
https://gitweb.gentoo.org/proj/emacs-patches.git/commit/emacs/30.2/05_all_tramp.patch?id=2a6292f81affedcc468c594c60808e652ae87118

--- lisp/net/tramp-rclone.el.orig	2025-04-05 11:01:10.000000000 +0000
+++ lisp/net/tramp-rclone.el
@@ -191,7 +191,7 @@ arguments to pass to the OPERATION."
   (with-tramp-connection-property nil "rclone-device-names"
     (tramp-compat-seq-keep
      (lambda (line)
-       (when (string-match (rx bol (group (+ (not blank))) ":" eol) line)
+       (when (string-match (rx bos (group (+ (not blank))) ":" eos) line)
 	 `(nil ,(match-string 1 line))))
      (tramp-process-lines nil tramp-rclone-program "listremotes"))))
 
@@ -365,7 +365,7 @@ file names."
 	  (tramp-rclone-maybe-open-connection v)
 	  ;; TODO: This shall be handled by `expand-file-name'.
 	  (setq localname
-		(replace-regexp-in-string (rx bol ".") "" (or localname "")))
+		(replace-regexp-in-string (rx bos ".") "" (or localname "")))
 	  (format "%s%s" (tramp-fuse-mounted-p v) localname)))
     ;; It is a local file name.
     filename))
