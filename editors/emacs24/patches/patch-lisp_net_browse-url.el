$NetBSD: patch-lisp_net_browse-url.el,v 1.2 2015/03/03 13:47:14 ryoon Exp $

* Support firefox 36.0 or later.
  https://debbugs.gnu.org/cgi/bugreport.cgi?bug=19921

--- lisp/net/browse-url.el.orig	2014-05-14 02:59:18.000000000 +0000
+++ lisp/net/browse-url.el
@@ -337,6 +337,9 @@ Defaults to the value of `browse-url-fir
   :type '(repeat (string :tag "Argument"))
   :group 'browse-url)
 
+(make-obsolete-variable 'browse-url-firefox-startup-arguments
+                        "it no longer has any effect." "24.5")
+
 (defcustom browse-url-chromium-program
   (let ((candidates '("chromium" "chromium-browser")))
     (while (and candidates (not (executable-find (car candidates))))
@@ -1102,68 +1105,39 @@ used instead of `browse-url-new-window-f
 ;;;###autoload
 (defun browse-url-firefox (url &optional new-window)
   "Ask the Firefox WWW browser to load URL.
-Default to the URL around or before point.  The strings in
-variable `browse-url-firefox-arguments' are also passed to
-Firefox.
+Defaults to the URL around or before point.  Passes the strings
+in the variable `browse-url-firefox-arguments' to Firefox.
 
-When called interactively, if variable
-`browse-url-new-window-flag' is non-nil, load the document in a
-new Firefox window, otherwise use a random existing one.  A
-non-nil interactive prefix argument reverses the effect of
-`browse-url-new-window-flag'.
+Interactively, if the variable `browse-url-new-window-flag' is non-nil,
+loads the document in a new Firefox window.  A non-nil prefix argument
+reverses the effect of `browse-url-new-window-flag'.
 
 If `browse-url-firefox-new-window-is-tab' is non-nil, then
 whenever a document would otherwise be loaded in a new window, it
 is loaded in a new tab in an existing window instead.
 
-When called non-interactively, optional second argument
-NEW-WINDOW is used instead of `browse-url-new-window-flag'.
+Non-interactively, this uses the optional second argument NEW-WINDOW
+instead of `browse-url-new-window-flag'.
 
-On MS-Windows systems the optional `new-window' parameter is
-ignored.  Firefox for Windows does not support the \"-remote\"
-command line parameter.  Therefore, the
-`browse-url-new-window-flag' and `browse-url-firefox-new-window-is-tab'
-are ignored as well.  Firefox on Windows will always open the requested
-URL in a new window."
+On MS Windows, this ignores `browse-url-new-window-flag' and
+`browse-url-firefox-new-window-is-tab', as well as the NEW-WINDOW argument.
+It always uses a new window."
   (interactive (browse-url-interactive-arg "URL: "))
   (setq url (browse-url-encode-url url))
-  (let* ((process-environment (browse-url-process-environment))
-	 (use-remote
-	  (not (memq system-type '(windows-nt ms-dos))))
-	 (process
-	  (apply 'start-process
-		 (concat "firefox " url) nil
-		 browse-url-firefox-program
-		 (append
-		  browse-url-firefox-arguments
-		  (if use-remote
-		      (list "-remote"
-			    (concat
-			     "openURL("
-			     url
-			     (if (browse-url-maybe-new-window new-window)
-				 (if browse-url-firefox-new-window-is-tab
-				     ",new-tab"
-				   ",new-window"))
-			     ")"))
-		    (list url))))))
-    ;; If we use -remote, the process exits with status code 2 if
-    ;; Firefox is not already running.  The sentinel runs firefox
-    ;; directly if that happens.
-    (when use-remote
-      (set-process-sentinel process
-			    `(lambda (process change)
-			       (browse-url-firefox-sentinel process ,url))))))
-
-(defun browse-url-firefox-sentinel (process url)
-  "Handle a change to the process communicating with Firefox."
-  (or (eq (process-exit-status process) 0)
-      (let* ((process-environment (browse-url-process-environment)))
-	;; Firefox is not running - start it
-	(message "Starting Firefox...")
-	(apply 'start-process (concat "firefox " url) nil
-	       browse-url-firefox-program
-	       (append browse-url-firefox-startup-arguments (list url))))))
+  (let* ((process-environment (browse-url-process-environment)))
+    (apply 'start-process
+           (concat "firefox " url) nil
+           browse-url-firefox-program
+           (append
+            browse-url-firefox-arguments
+            ;; FIXME someone should check if this limitation
+            ;; still applies.
+            (unless (memq system-type '(windows-nt ms-dos))
+              (if (browse-url-maybe-new-window new-window)
+                  (if browse-url-firefox-new-window-is-tab
+                      '("-new-tab")
+                    '("-new-window"))))
+            (list url)))))
 
 ;;;###autoload
 (defun browse-url-chromium (url &optional _new-window)
