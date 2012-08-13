$NetBSD: patch-lisp_files.el,v 1.1 2012/08/13 06:39:06 wiz Exp $

CVE-2012-3479:
When the Emacs user option `enable-local-variables' is set to `:safe'
(the default value is t), Emacs should automatically refuse to evaluate
`eval' forms in file-local variable sections.  Due to the bug, Emacs
instead automatically evaluates such `eval' forms.  Thus, if the user
changes the value of `enable-local-variables' to `:safe', visiting a
malicious file can cause automatic execution of arbitrary Emacs Lisp
code with the permissions of the user.

Bug tracker ref: http://debbugs.gnu.org/cgi/bugreport.cgi?bug=12155

--- lisp/files.el.orig	2012-05-14 12:00:02.000000000 +0000
+++ lisp/files.el
@@ -3107,11 +3107,16 @@ DIR-NAME is the name of the associated d
 	      ;; Obey `enable-local-eval'.
 	      ((eq var 'eval)
 	       (when enable-local-eval
-		 (push elt all-vars)
-		 (or (eq enable-local-eval t)
-		     (hack-one-local-variable-eval-safep (eval (quote val)))
-		     (safe-local-variable-p var val)
-		     (push elt unsafe-vars))))
+		 (let ((safe (or (hack-one-local-variable-eval-safep
+				  (eval (quote val)))
+				 ;; In case previously marked safe (bug#5636).
+				 (safe-local-variable-p var val))))
+		   ;; If not safe and e-l-v = :safe, ignore totally.
+		   (when (or safe (not (eq enable-local-variables :safe)))
+		     (push elt all-vars)
+		     (or (eq enable-local-eval t)
+			 safe
+			 (push elt unsafe-vars))))))
 	      ;; Ignore duplicates (except `mode') in the present list.
 	      ((and (assq var all-vars) (not (eq var 'mode))) nil)
 	      ;; Accept known-safe variables.
