$NetBSD: patch-lisp_gnus_gnus-fun.el,v 1.1.2.2 2014/07/10 07:39:12 tron Exp $

Fix for CVE-2014-3421.

--- lisp/gnus/gnus-fun.el.orig	2012-01-11 12:35:01.000000000 +0000
+++ lisp/gnus/gnus-fun.el
@@ -261,19 +261,21 @@ colors of the displayed X-Faces."
   (shell-command "xawtv-remote snap ppm")
   (let ((file nil)
 	result)
+    (tempfile (make-temp-file "gnus-face-" nil ".ppm"))
     (while (null (setq file (directory-files "/tftpboot/sparky/tmp"
 					     t "snap.*ppm")))
       (sleep-for 1))
     (setq file (car file))
     (shell-command
-     (format "pnmcut -left 110 -top 30 -width 144 -height 144 '%s' | pnmscale -width 48 -height 48 | ppmtopgm > /tmp/gnus.face.ppm"
-	     file))
+     (format "pnmcut -left 110 -top 30 -width 144 -height 144 '%s' | pnmscale 
+-width 48 -height 48 | ppmtopgm >> %s"
+	     file tempfile))
     (let ((gnus-convert-image-to-face-command
 	   (format "cat '%%s' | ppmquant %%d | ppmchange %s | pnmtopng"
 		   (gnus-fun-ppm-change-string))))
-      (setq result (gnus-face-from-file "/tmp/gnus.face.ppm")))
+      (setq result (gnus-face-from-file tempfile)))
     (delete-file file)
-    ;;(delete-file "/tmp/gnus.face.ppm")
+    ;;(delete-file tempfile)    ; FIXME why are we not deleting it?!
     result))
 
 (defun gnus-fun-ppm-change-string ()
