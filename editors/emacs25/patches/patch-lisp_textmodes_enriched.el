$NetBSD: patch-lisp_textmodes_enriched.el,v 1.1 2017/09/11 11:33:33 wiz Exp $

GNU Emacs is an extensible, customizable, free/libre text editor and software
environment.  When Emacs renders MIME text/enriched data (Internet RFC 1896),
it is vulnerable to arbitrary code execution. Since Emacs-based mail clients
decode "Content-Type: text/enriched", this code is exploitable remotely. This
bug affects GNU Emacs versions 19.29 through 25.2.

== Details ==

https://bugs.gnu.org/28350

== Patch ==

https://git.savannah.gnu.org/cgit/emacs.git/commit/?h=emacs-25&id=9ad0fcc54442a9a01d41be19880250783426db70

--- lisp/textmodes/enriched.el.orig	2017-02-03 10:25:44.000000000 +0000
+++ lisp/textmodes/enriched.el
@@ -117,12 +117,7 @@ expression, which is evaluated to get th
 		   (full        "flushboth")
 		   (center      "center"))
     (PARAMETER     (t           "param")) ; Argument of preceding annotation
-    ;; The following are not part of the standard:
-    (FUNCTION      (enriched-decode-foreground "x-color")
-		   (enriched-decode-background "x-bg-color")
-		   (enriched-decode-display-prop "x-display"))
     (read-only     (t           "x-read-only"))
-    (display	   (nil		enriched-handle-display-prop))
     (unknown       (nil         format-annotate-value))
 ;   (font-size     (2           "bigger")       ; unimplemented
 ;		   (-2          "smaller"))
@@ -477,32 +472,5 @@ Return value is \(begin end name positiv
     (message "Warning: no color specified for <x-bg-color>")
     nil))
 
-;;; Handling the `display' property.
-
-
-(defun enriched-handle-display-prop (old new)
-  "Return a list of annotations for a change in the `display' property.
-OLD is the old value of the property, NEW is the new value.  Value
-is a list `(CLOSE OPEN)', where CLOSE is a list of annotations to
-close and OPEN a list of annotations to open.  Each of these lists
-has the form `(ANNOTATION PARAM ...)'."
-  (let ((annotation "x-display")
-	(param (prin1-to-string (or old new))))
-    (if (null old)
-        (cons nil (list (list annotation param)))
-      (cons (list (list annotation param)) nil))))
-
-(defun enriched-decode-display-prop (start end &optional param)
-  "Decode a `display' property for text between START and END.
-PARAM is a `<param>' found for the property.
-Value is a list `(START END SYMBOL VALUE)' with START and END denoting
-the range of text to assign text property SYMBOL with value VALUE."
-  (let ((prop (when (stringp param)
-		(condition-case ()
-		    (car (read-from-string param))
-		  (error nil)))))
-    (unless prop
-      (message "Warning: invalid <x-display> parameter %s" param))
-    (list start end 'display prop)))
 
 ;;; enriched.el ends here
