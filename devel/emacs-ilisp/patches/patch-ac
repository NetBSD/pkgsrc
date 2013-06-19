$NetBSD: patch-ac,v 1.3 2013/06/19 13:12:01 mef Exp $

Add Version specific module to byte-compile

--- ilisp-mak.el.orig	2002-05-31 20:47:57.000000000 +0900
+++ ilisp-mak.el	2013-06-19 15:13:05.000000000 +0900
@@ -48,6 +48,12 @@
            (byte-compile-file "illuc19.el"))
           ((eq +ilisp-emacs-version-id+ 'xemacs)
            (byte-compile-file "ilxemacs.el"))
+          ((eq +ilisp-emacs-version-id+ 'fsf-24)
+           (byte-compile-file "ilfsf21.el"))
+          ((eq +ilisp-emacs-version-id+ 'fsf-23)
+           (byte-compile-file "ilfsf21.el"))
+          ((eq +ilisp-emacs-version-id+ 'fsf-22)
+           (byte-compile-file "ilfsf21.el"))
           ((eq +ilisp-emacs-version-id+ 'fsf-21)
            (byte-compile-file "ilfsf21.el"))
           ((eq +ilisp-emacs-version-id+ 'fsf-20)
