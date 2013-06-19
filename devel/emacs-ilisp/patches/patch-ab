$NetBSD: patch-ab,v 1.3 2013/06/19 13:12:01 mef Exp $

Update to include new versions of Emacsen

--- ilcompat.el.orig	2002-10-25 21:13:49.000000000 +0900
+++ ilcompat.el	2013-06-19 15:07:53.000000000 +0900
@@ -27,6 +27,12 @@
 	 'fsf-20)
 	((string-match "^21" emacs-version)
 	 'fsf-21)
+	((string-match "^22" emacs-version)
+	 'fsf-22)
+	((string-match "^23" emacs-version)
+	 'fsf-23)
+	((string-match "^24" emacs-version)
+	 'fsf-24)
 	(t 'fsf-18))
   "The major version of (X)Emacs ILISP is running in.
 Declared as '(member fsf-19 fsf-19 fsf-20 fsf-21 lucid-19 lucid-19-new xemacs).
@@ -55,6 +61,9 @@ Set in ilcompat.el.")
       ((eq +ilisp-emacs-version-id+ 'fsf-19) (load "ilfsf19"))
       ((eq +ilisp-emacs-version-id+ 'fsf-20) (load "ilfsf20"))
       ((eq +ilisp-emacs-version-id+ 'fsf-21) (load "ilfsf21"))
+      ((eq +ilisp-emacs-version-id+ 'fsf-22) (load "ilfsf21"))
+      ((eq +ilisp-emacs-version-id+ 'fsf-23) (load "ilfsf21"))
+      ((eq +ilisp-emacs-version-id+ 'fsf-24) (load "ilfsf21"))
       )
 
 
