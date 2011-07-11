$NetBSD: patch-mew-ssl.el,v 1.1 2011/07/11 14:54:38 ryoon Exp $

* Support "stunnel -version" output of stunnel-4.39.

--- mew-ssl.el.orig	2009-01-21 05:54:58.000000000 +0000
+++ mew-ssl.el
@@ -260,7 +260,8 @@ A local port number can be obtained the 
     (with-temp-buffer
       (call-process mew-prog-ssl nil t nil "-version")
       (goto-char (point-min))
-      (if (looking-at "stunnel 4\\.\\([0-9]+\\)")
+      (re-search-forward "^stunnel " nil t 1)
+      (if (looking-at "4\\.\\([0-9]+\\)")
 	  (progn
 	    (setq mew-ssl-ver 4)
 	    (setq mew-ssl-minor-ver (string-to-number (mew-match-string 1))))
