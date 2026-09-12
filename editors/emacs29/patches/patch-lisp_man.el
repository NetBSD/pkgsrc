$NetBSD: patch-lisp_man.el,v 1.1 2026/09/12 14:34:57 wiz Exp $

Man-getpage-in-background runs the man command under sh -c, and passes
whatever Man-translate-references returns straight into it.  A reference
with no section part is returned unchanged, so "M-x man RET ;id RET" runs
id.  Fix from upstream commit 820f0793f0 ("Fix man.el shell injection
vulnerability"), debbugs 66390, landed only in 30.1; this package stays on
29.4.

--- lisp/man.el.orig
+++ lisp/man.el
@@ -684,7 +684,11 @@
       (setq name (match-string 2 ref)
 	    section (match-string 1 ref))))
     (if (string= name "")
-	ref				; Return the reference as is
+        ;; see Bug#66390
+	(mapconcat 'identity
+                   (mapcar #'shell-quote-argument
+                           (split-string ref "\\s-+"))
+                   " ")                 ; Return the reference as is
       (if Man-downcase-section-letters-flag
 	  (setq section (downcase section)))
       (while slist
