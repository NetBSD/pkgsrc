$NetBSD: patch-style_subfigure.el,v 1.1 2016/12/18 07:26:10 mef Exp $

(with emacs26)
In toplevel form:
style/subfigure.el:44:5:Error: missing value for `TeX-complete-list' at end of setq

--- style/subfigure.el.orig	2016-12-18 15:39:04.373535991 +0900
+++ style/subfigure.el	2016-12-18 15:37:18.100484994 +0900
@@ -48,8 +48,8 @@
    ;; Install completion for labels:
    (setq TeX-complete-list
 	 (append
-	  '(("\\\\[Ss]ubref{\\([^{}\n\r\\%,]*\\)" 1 LaTeX-label-list "}")))
-	  TeX-complete-list)
+	  '(("\\\\[Ss]ubref{\\([^{}\n\r\\%,]*\\)" 1 LaTeX-label-list "}"))
+	  TeX-complete-list))
 
    ;; Fontification
    (when (and (featurep 'font-latex)
