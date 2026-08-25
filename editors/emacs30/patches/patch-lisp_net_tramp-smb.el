$NetBSD: patch-lisp_net_tramp-smb.el,v 1.1 2026/08/25 17:44:23 wiz Exp $

CVE-2026-79992: Fix local command execution vulnerability in tramp
https://gitweb.gentoo.org/proj/emacs-patches.git/commit/emacs/30.2/05_all_tramp.patch?id=2a6292f81affedcc468c594c60808e652ae87118

--- lisp/net/tramp-smb.el.orig	2025-04-05 11:01:10.000000000 +0000
+++ lisp/net/tramp-smb.el
@@ -1550,7 +1550,7 @@ VEC or USER, or if there is no home directory, return 
   "Return the share name of LOCALNAME."
   (save-match-data
     (let ((localname (tramp-file-name-unquote-localname vec)))
-      (when (string-match (rx bol (? "/") (group (+ (not "/"))) "/") localname)
+      (when (string-match (rx bos (? "/") (group (+ (not "/"))) "/") localname)
 	(match-string 1 localname)))))
 
 (defun tramp-smb-get-localname (vec)
@@ -1561,7 +1561,7 @@ If VEC has no cifs capabilities, exchange \"/\" by \"\
       (setq
        localname
        (if (string-match
-	    (rx bol (? "/") (+ (not "/")) (group "/" (* nonl))) localname)
+	    (rx bos (? "/") (+ (not "/")) (group "/" (* nonl))) localname)
 	   ;; There is a share, separated by "/".
 	   (if (not (tramp-smb-get-cifs-capabilities vec))
 	       (mapconcat
@@ -1569,7 +1569,7 @@ If VEC has no cifs capabilities, exchange \"/\" by \"\
 		(match-string 1 localname) "")
 	     (match-string 1 localname))
 	 ;; There is just a share.
-	 (if (string-match (rx bol (? "/") (group (+ (not "/"))) eol) localname)
+	 (if (string-match (rx bos (? "/") (group (+ (not "/"))) eos) localname)
 	     (match-string 1 localname)
 	   "")))
 
