$NetBSD: patch-lisp_net_browse-url.el,v 1.1 2015/02/23 14:03:25 ryoon Exp $

* Support firefox 36.0 or later.
  https://debbugs.gnu.org/cgi/bugreport.cgi?bug=19921

--- lisp/net/browse-url.el.orig	2015-02-22 06:52:03.000000000 +0000
+++ lisp/net/browse-url.el
@@ -1137,15 +1137,12 @@ URL in a new window."
 		 (append
 		  browse-url-firefox-arguments
 		  (if use-remote
-		      (list "-remote"
-			    (concat
-			     "openURL("
-			     url
-			     (if (browse-url-maybe-new-window new-window)
-				 (if browse-url-firefox-new-window-is-tab
-				     ",new-tab"
-				   ",new-window"))
-			     ")"))
+		      (list
+		       (if (browse-url-maybe-new-window new-window)
+			   (if browse-url-firefox-new-window-is-tab
+			       "--new-tab"
+			     "--new-window"))
+		       url)
 		    (list url))))))
     ;; If we use -remote, the process exits with status code 2 if
     ;; Firefox is not already running.  The sentinel runs firefox
