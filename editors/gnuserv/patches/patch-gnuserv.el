$NetBSD: patch-gnuserv.el,v 1.2 2023/09/11 21:18:49 vins Exp $

* For emacs28, (define-obsolete-variable-alias) needs when argument
* Function process-kill-without-query is obsolete since 22.1
  and no longer exists in 27.

--- gnuserv.el.orig	2004-10-19 08:50:01.000000000 +0000
+++ gnuserv.el
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
@@ -738,7 +738,7 @@ All the clients will be disposed of via 
 	    (start-process "gnuserv" nil gnuserv-program)))
     (set-process-sentinel gnuserv-process 'gnuserv-sentinel)
     (set-process-filter gnuserv-process 'gnuserv-process-filter)
-    (process-kill-without-query gnuserv-process)
+    (set-process-query-on-exit-flag gnuserv-process nil)
     (setq allow-deletion-of-last-visible-frame t)
     (run-hooks 'gnuserv-init-hook)))
 
