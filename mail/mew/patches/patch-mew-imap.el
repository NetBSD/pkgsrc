$NetBSD: patch-mew-imap.el,v 1.1 2021/03/21 13:48:09 taca Exp $

* Prevent inserting an extra line in header.

--- mew-imap.el.orig	2018-06-07 05:48:29.000000000 +0000
+++ mew-imap.el
@@ -1449,7 +1449,7 @@
 			(mew-imap-secure-p pnm))
        (goto-char (point-min))
        (when (and (null bytes)
-		  (looking-at "^\\*[^{]*{\\([0-9]+\\)}"))
+		  (looking-at "^\\*[^{]*{\\([0-9]+\\)}.*\n"))
 	 (setq bytes (string-to-number (mew-match-string 1)))
 	 (mew-imap-set-bytes pnm bytes))
        (when (looking-at "^\\* .*X-GM-THRID +\\([0-9]+\\)")
