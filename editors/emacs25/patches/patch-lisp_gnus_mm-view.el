$NetBSD: patch-lisp_gnus_mm-view.el,v 1.1 2017/09/11 11:33:33 wiz Exp $

GNU Emacs is an extensible, customizable, free/libre text editor and software
environment.  When Emacs renders MIME text/enriched data (Internet RFC 1896),
it is vulnerable to arbitrary code execution. Since Emacs-based mail clients
decode "Content-Type: text/enriched", this code is exploitable remotely. This
bug affects GNU Emacs versions 19.29 through 25.2.

== Details ==

https://bugs.gnu.org/28350

== Patch ==

https://git.savannah.gnu.org/cgit/emacs.git/commit/?h=emacs-25&id=9ad0fcc54442a9a01d41be19880250783426db70

--- lisp/gnus/mm-view.el.orig	2017-02-03 10:25:44.000000000 +0000
+++ lisp/gnus/mm-view.el
@@ -383,10 +383,6 @@
 	(goto-char (point-max))))
     (save-restriction
       (narrow-to-region b (point))
-      (when (member type '("enriched" "richtext"))
-        (set-text-properties (point-min) (point-max) nil)
-	(ignore-errors
-	  (enriched-decode (point-min) (point-max))))
       (mm-handle-set-undisplayer
        handle
        `(lambda ()
