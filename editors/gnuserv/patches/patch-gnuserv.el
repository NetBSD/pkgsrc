$NetBSD: patch-gnuserv.el,v 1.1 2023/09/09 22:58:51 mef Exp $

For emacs28, (define-obsolete-variable-alias) needs when argument

--- gnuserv.el.orig	2004-10-19 17:50:01.000000000 +0900
+++ gnuserv.el	2023-09-10 07:50:00.863815888 +0900
@@ -103,25 +103,25 @@ Set this to nil if you don't want a mode
 ;; new forms.  This ugly crock must be before the variable
 ;; declaration, or the scheme fails.
 
-(define-obsolete-variable-alias 'server-frame 'gnuserv-frame)
+(define-obsolete-variable-alias 'server-frame 'gnuserv-frame t)
 (define-obsolete-variable-alias 'server-done-function
-  'gnuserv-done-function)
+  'gnuserv-done-function t)
 (define-obsolete-variable-alias 'server-done-temp-file-function
-  'gnuserv-done-temp-file-function)
+  'gnuserv-done-temp-file-function t)
 (define-obsolete-variable-alias 'server-find-file-function
-  'gnuserv-find-file-function)
+  'gnuserv-find-file-function t)
 (define-obsolete-variable-alias 'server-program
-  'gnuserv-program)
+  'gnuserv-program t)
 (define-obsolete-variable-alias 'server-visit-hook
-  'gnuserv-visit-hook)
+  'gnuserv-visit-hook t)
 (define-obsolete-variable-alias 'server-done-hook
-  'gnuserv-done-hook)
+  'gnuserv-done-hook t)
 (define-obsolete-variable-alias 'server-kill-quietly
-  'gnuserv-kill-quietly)
+  'gnuserv-kill-quietly t)
 (define-obsolete-variable-alias 'server-temp-file-regexp
-  'gnuserv-temp-file-regexp)
+  'gnuserv-temp-file-regexp t)
 (define-obsolete-variable-alias 'server-make-temp-file-backup
-  'gnuserv-make-temp-file-backup)
+  'gnuserv-make-temp-file-backup t)
 
 ;;;###autoload
 (defcustom gnuserv-frame nil
