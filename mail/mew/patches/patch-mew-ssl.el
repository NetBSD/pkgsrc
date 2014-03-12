$NetBSD: patch-mew-ssl.el,v 1.3 2014/03/12 12:43:43 ryoon Exp $

* Add stunnel 5 support

--- mew-ssl.el.orig	2012-04-16 03:18:13.000000000 +0000
+++ mew-ssl.el
@@ -264,7 +264,7 @@ A local port number can be obtained the 
       (call-process mew-prog-ssl nil t nil "-version")
       (goto-char (point-min))
       (re-search-forward "^stunnel " nil t 1)
-      (if (looking-at "4\\.\\([0-9]+\\)")
+      (if (looking-at "[45]\\.\\([0-9]+\\)")
 	  (progn
 	    (setq mew-ssl-ver 4)
 	    (setq mew-ssl-minor-ver (string-to-number (mew-match-string 1))))
