$NetBSD: patch-anthy.el,v 1.1 2023/09/06 01:50:50 msaitoh Exp $

* Don't use old stype backquote.

--- src-util/anthy.el.orig	2008-11-29 21:46:00.000000000 +0900
+++ src-util/anthy.el	2023-08-24 11:18:12.150159492 +0900
@@ -161,11 +161,11 @@
 
 ;; From skk-macs.el From viper-util.el.  Welcome!
 (defmacro anthy-deflocalvar (var default-value &optional documentation)
-  (` (progn
-       (defvar (, var) (, default-value)
-	 (, (format "%s\n\(buffer local\)" documentation)))
-       (make-variable-buffer-local '(, var))
-       )))
+  ` (progn
+       (defvar ,var ,default-value
+	 ,(format "%s\n\(buffer local\)" documentation))
+       (make-variable-buffer-local ',var)
+       ))
 
 ;; buffer local variables
 (anthy-deflocalvar anthy-context-id nil "コンテキストのid")
