$NetBSD: patch-riece-twitter.el,v 1.1 2014/11/23 06:13:37 mef Exp $

riece-twitter.el:79:25:Warning: `interactive-p' is an obsolete function (as of
    23.2); use `called-interactively-p' instead.

--- lisp/riece-twitter.el~	2011-04-04 15:47:41.000000000 +0900
+++ lisp/riece-twitter.el	2014-06-15 22:02:07.000000000 +0900
@@ -77,7 +77,7 @@
 	 (process
 	  (apply #'start-process
 		 "curl" nil "curl"
-		 (if (interactive-p)
+		 (if (called-interactively-p)
 		     args
 		   (append args
 			   (list "-H" "X-Twitter-Client: Riece"
