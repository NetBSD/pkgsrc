$NetBSD: patch-smtp.el,v 1.1 2023/09/03 14:58:39 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/smtp.el	2006-09-24 09:40:58.000000000 +0900
+++ ./smtp.el	2023-08-31 08:29:38.622738962 +0900
@@ -1,4 +1,4 @@
-;;; smtp.el --- basic functions to send mail with SMTP server
+;;; smtp.el --- basic functions to send mail with SMTP server  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1995, 1996, 1998, 1999, 2000, 2001 ,2002, 2004
 ;; Free Software Foundation, Inc.
@@ -79,7 +79,7 @@
   :group 'smtp)
 
 (defcustom smtp-fqdn nil
-  "Fully qualified domain name used for Message-ID."
+  "Fully qualified domain name used for SMTP HELO/EHLO."
   :type '(choice (const nil) string)
   :group 'smtp)
 
@@ -98,17 +98,14 @@
   :type 'boolean
   :group 'smtp-extensions)
 
-(defcustom smtp-use-starttls-ignore-error nil
-  "If non-nil, do not use STARTTLS if STARTTLS is not available."
+(defcustom smtp-use-gnutls (gnutls-available-p)
+  "If non-nil, use built-in GnuTLS for STARTTLS."
   :type 'boolean
   :group 'smtp-extensions)
 
-(defcustom smtp-starttls-program "starttls"
-  "The program to run in a subprocess to open an TLSv1 connection."
-  :group 'smtp-extensions)
-
-(defcustom smtp-starttls-extra-args nil
-  "Extra arguments to `starttls-program'"
+(defcustom smtp-use-starttls-ignore-error nil
+  "If non-nil, do not use STARTTLS if STARTTLS is not available."
+  :type 'boolean
   :group 'smtp-extensions)
 
 (defcustom smtp-use-sasl nil
@@ -145,8 +142,8 @@
 `open-network-stream' and should return a process object.
 Here is an example:
 
-\(setq smtp-open-connection-function
-      #'(lambda (name buffer host service)
+(setq smtp-open-connection-function
+      #\\='(lambda (name buffer host service)
 	  (let ((process-connection-type nil))
 	    (start-process name buffer \"ssh\" \"-C\" host
 			   \"nc\" host service))))
@@ -186,8 +183,7 @@
 
 (defun smtp-package-buffer-internal-size (package)
   "Return the size of PACKAGE, an integer."
-  (save-excursion
-    (set-buffer (smtp-package-buffer-internal package))
+  (with-current-buffer (smtp-package-buffer-internal package)
     (let ((size
 	   (+ (buffer-size)
 	      ;; Add one byte for each change-of-line
@@ -245,14 +241,14 @@
   "Return user's fully qualified domain name."
   (if smtp-fqdn
       smtp-fqdn
-    (let ((system-name (system-name)))
+    (let ((name (system-name)))
       (cond
        (smtp-local-domain
-	(concat system-name "." smtp-local-domain))
-       ((string-match "[^.]\\.[^.]" system-name)
-	system-name)
+	(concat name "." smtp-local-domain))
+       ((string-match "[^.]\\.[^.]" name)
+	name)
        (t
-	(error "Cannot generate valid FQDN"))))))
+	(error "invalid FQDN. Set smtp-fqdn or smtp-local-domain correctly"))))))
 
 (defun smtp-find-connection (buffer)
   "Find the connection delivering to BUFFER."
@@ -268,7 +264,8 @@
 
 (eval-and-compile
   (autoload 'starttls-open-stream "starttls")
-  (autoload 'starttls-negotiate "starttls"))
+  (autoload 'starttls-negotiate "starttls")
+  (autoload 'gnutls-negotiate "gnutls"))
 
 (defun smtp-open-connection (buffer server service)
   "Open a SMTP connection for a service to a host.
@@ -276,9 +273,18 @@
 BUFFER is the buffer to associate with the connection.  SERVER is name
 of the host to connect to.  SERVICE is name of the service desired."
   (let ((process
-	 (binary-funcall smtp-open-connection-function
-			 "SMTP" buffer server service))
+	 (binary-funcall
+	  (cond
+	   ((and smtp-use-starttls (null smtp-use-gnutls))
+	    'starttls-open-stream)
+	   (t
+	    smtp-open-connection-function))
+	  "SMTP" buffer server service))
 	connection)
+    (unless (and (processp process)
+		 (memq (process-status process) '(open run)))
+      (error "Open SMTP connection function to %s:%s failed"
+	     server (if (integerp service) (format "%d" service) service)))
     (when process
       (setq connection (smtp-make-connection process server service))
       (set-process-filter process 'smtp-process-filter)
@@ -341,7 +347,7 @@
 	t)
     (smtp-error)))
 
-(make-obsolete 'smtp-via-smtp "It's old API.")
+(make-obsolete 'smtp-via-smtp "It's old API." "02 Nov 2000")
 
 ;;;###autoload
 (defun smtp-send-buffer (sender recipients buffer)
@@ -357,24 +363,22 @@
 	      (or smtp-server
 		  (error "`smtp-server' not defined"))))
 	   (package
-	    (smtp-make-package sender recipients buffer))
-	   (starttls-program smtp-starttls-program)
-	   (starttls-extra-args smtp-starttls-extra-args)
-	   (smtp-open-connection-function
-	    (if smtp-use-starttls
-		#'starttls-open-stream
-	      smtp-open-connection-function)))
-      (save-excursion
-	(set-buffer
-	 (get-buffer-create
-	  (format "*trace of SMTP session to %s*" server)))
+	    (smtp-make-package sender recipients buffer)))
+      (with-current-buffer
+	  (setq buffer (get-buffer-create
+			(format "*trace of SMTP session to %s*" server)))
 	(erase-buffer)
 	(buffer-disable-undo)
-	(unless (smtp-find-connection (current-buffer))
-	  (smtp-open-connection (current-buffer) server smtp-service))
+	(unless (smtp-find-connection buffer)
+	  (smtp-open-connection buffer server smtp-service))
 	(make-local-variable 'smtp-read-point)
 	(setq smtp-read-point (point-min))
-	(funcall smtp-submit-package-function package)))))
+	(funcall smtp-submit-package-function package)
+	(unless (or smtp-debug (smtp-find-connection buffer))
+	  (setq smtp-connection-alist
+		(delq (assq buffer smtp-connection-alist)
+		      smtp-connection-alist))
+	  (kill-buffer nil))))))
 
 (defun smtp-submit-package (package)
   (unwind-protect
@@ -399,7 +403,7 @@
 	(smtp-primitive-rcptto package)
 	(smtp-primitive-data package))
     (let ((connection (smtp-find-connection (current-buffer))))
-      (when (smtp-connection-opened connection)
+      (when (and connection (smtp-connection-opened connection))
 	(condition-case nil
 	    (smtp-primitive-quit package)
 	  (smtp-error))
@@ -412,10 +416,6 @@
 BUFFER may be a buffer or a buffer name which contains mail message."
   (let ((servers
 	 (smtp-find-server recipients))
-	(smtp-open-connection-function
-	 (if smtp-use-starttls
-	     #'starttls-open-stream
-	   smtp-open-connection-function))
 	server package)
       (while (car servers)
 	(setq server (caar servers))
@@ -426,25 +426,29 @@
 			   (mapconcat 'concat recipients ">,<"))))
 	(setq package
 	      (smtp-make-package sender recipients buffer))
-	(save-excursion
-	  (set-buffer
-	   (get-buffer-create
-	    (format "*trace of SMTP session to %s*" server)))
+	(with-current-buffer
+	    (setq buffer (get-buffer-create
+			  (format "*trace of SMTP session to %s*" server)))
 	  (erase-buffer)
 	  (buffer-disable-undo)
-	  (unless (smtp-find-connection (current-buffer))
-	    (smtp-open-connection (current-buffer) server smtp-service))
+	  (unless (smtp-find-connection buffer)
+	    (smtp-open-connection buffer server smtp-service))
 	  (make-local-variable 'smtp-read-point)
 	  (setq smtp-read-point (point-min))
 	  (let ((smtp-use-sasl nil)
 		(smtp-use-starttls-ignore-error t))
-	    (funcall smtp-submit-package-function package)))
+	    (funcall smtp-submit-package-function package))
+	  (unless (or smtp-debug (smtp-find-connection buffer))
+	    (setq smtp-connection-alist
+		  (delq (assq buffer smtp-connection-alist)
+			smtp-connection-alist))
+	    (kill-buffer nil)))
 	(setq servers (cdr servers)))))
 
 ;;; @ hook methods for `smtp-submit-package'
 ;;;
 
-(defun smtp-primitive-greeting (package)
+(defun smtp-primitive-greeting (_package)
   (let* ((connection
 	  (smtp-find-connection (current-buffer)))
 	 (response
@@ -452,7 +456,7 @@
     (if (/= (car response) 220)
 	(smtp-response-error response))))
 
-(defun smtp-primitive-ehlo (package)
+(defun smtp-primitive-ehlo (_package)
   (let* ((connection
 	  (smtp-find-connection (current-buffer)))
 	 response)
@@ -471,7 +475,7 @@
 		     extensions))
 		 (cdr response)))))
 
-(defun smtp-primitive-helo (package)
+(defun smtp-primitive-helo (_package)
   (let* ((connection
 	  (smtp-find-connection (current-buffer)))
 	 response)
@@ -480,7 +484,7 @@
     (if (/= (car response) 250)
 	(smtp-response-error response))))
 
-(defun smtp-primitive-auth (package)
+(defun smtp-primitive-auth (_package)
   (let* ((connection
 	  (smtp-find-connection (current-buffer)))
 	 (mechanisms
@@ -518,7 +522,11 @@
 	  (smtp-response-error response)) ;Bogus server?
 	(if (/= (car response) 334)
 	    (smtp-response-error response))
-	(sasl-step-set-data step (base64-decode-string (nth 1 response)))
+	;; Server may return human readable string.
+	;; https://msdn.microsoft.com/en-us/library/cc246825.aspx
+	(sasl-step-set-data step (condition-case nil
+				     (base64-decode-string (nth 1 response))
+				   (error (nth 1 response))))
 	(setq step (sasl-next-step client step))
 	(smtp-send-command
 	 connection
@@ -531,16 +539,21 @@
 ;;;     connection (sasl-client-decoder client))
     ))
 
-(defun smtp-primitive-starttls (package)
+(defun smtp-primitive-starttls (_package)
   (let* ((connection
 	  (smtp-find-connection (current-buffer)))
+	 (process (smtp-connection-process-internal connection))
 	 response)
     ;; STARTTLS --- begin a TLS negotiation (RFC 2595)
     (smtp-send-command connection "STARTTLS")
     (setq response (smtp-read-response connection))
     (if (/= (car response) 220)
 	(smtp-response-error response))
-    (starttls-negotiate (smtp-connection-process-internal connection))))
+    (if (memq (process-status process) '(run stop exit signal))
+	(starttls-negotiate process)
+      (gnutls-negotiate
+       :process process
+       :hostname (smtp-connection-server-internal connection)))))
 
 (defun smtp-primitive-mailfrom (package)
   (let* ((connection
@@ -555,7 +568,7 @@
     ;; SIZE --- Message Size Declaration (RFC1870)
     (if (and smtp-use-size
 	     (assq 'size extensions))
-	(setq extension (format "SIZE=%d" (smtp-package-buffer-internal-size package))))
+	(setq extension (format " SIZE=%d" (smtp-package-buffer-internal-size package))))
     ;; 8BITMIME --- 8bit-MIMEtransport (RFC1652)
     (if (and smtp-use-8bitmime
 	     (assq '8bitmime extensions))
@@ -563,7 +576,7 @@
     (smtp-send-command
      connection
      (if extension
-	 (format "MAIL FROM:<%s> %s" sender extension)
+	 (format "MAIL FROM:<%s>%s" sender extension)
        (format "MAIL FROM:<%s>" sender)))
     (setq response (smtp-read-response connection))
     (if (/= (car response) 250)
@@ -590,8 +603,7 @@
     (setq response (smtp-read-response connection))
     (if (/= (car response) 354)
 	(smtp-response-error response))
-    (save-excursion
-      (set-buffer (smtp-package-buffer-internal package))
+    (with-current-buffer (smtp-package-buffer-internal package)
       (goto-char (point-min))
       (while (not (eobp))
 	(smtp-send-data
@@ -602,7 +614,7 @@
     (if (/= (car response) 250)
 	(smtp-response-error response))))
 
-(defun smtp-primitive-quit (package)
+(defun smtp-primitive-quit (_package)
   (let* ((connection
 	  (smtp-find-connection (current-buffer)))
 	 response)
@@ -614,8 +626,7 @@
 ;;; @ low level process manipulating function
 ;;;
 (defun smtp-process-filter (process output)
-  (save-excursion
-    (set-buffer (process-buffer process))
+  (with-current-buffer (process-buffer process)
     (goto-char (point-max))
     (insert output)))
 
@@ -663,12 +674,11 @@
     response))
 
 (defun smtp-send-command (connection command)
-  (save-excursion
-    (let ((process
-	   (smtp-connection-process-internal connection))
-	  (encoder
-	   (smtp-connection-encoder-internal connection)))
-      (set-buffer (process-buffer process))
+  (let ((process
+	 (smtp-connection-process-internal connection))
+	(encoder
+	 (smtp-connection-encoder-internal connection)))
+    (with-current-buffer (process-buffer process)
       (goto-char (point-max))
       (setq command (concat command "\r\n"))
       (insert command)
@@ -683,9 +693,7 @@
 	(encoder
 	 (smtp-connection-encoder-internal connection)))
     ;; Escape "." at start of a line.
-    (if (eq (string-to-char data) ?.)
-	(setq data (concat "." data "\r\n"))
-      (setq data (concat data "\r\n")))
+    (setq data (concat (when (eq (string-to-char data) ?.) ".") data "\r\n"))
     (if encoder
 	(setq data (funcall encoder data)))
     (process-send-string process data)))
@@ -698,13 +706,10 @@
 	addr-regexp
 	(smtp-address-buffer (generate-new-buffer " *smtp-mail*")))
     (unwind-protect
-	(save-excursion
-	  ;;
-	  (set-buffer smtp-address-buffer)
+	(with-current-buffer smtp-address-buffer
 	  (setq case-fold-search t)
 	  (erase-buffer)
-	  (insert (save-excursion
-		    (set-buffer smtp-text-buffer)
+	  (insert (with-current-buffer smtp-text-buffer
 		    (buffer-substring-no-properties header-start header-end)))
 	  (goto-char (point-min))
 	  ;; RESENT-* fields should stop processing of regular fields.
@@ -729,11 +734,11 @@
 	  (erase-buffer)
 	  (insert " " simple-address-list "\n")
 	  ;; newline --> blank
-	  (subst-char-in-region (point-min) (point-max) 10 ?  t)
+	  (subst-char-in-region (point-min) (point-max) 10 ?\s t)
 	  ;; comma   --> blank
-	  (subst-char-in-region (point-min) (point-max) ?, ?  t)
+	  (subst-char-in-region (point-min) (point-max) ?, ?\s t)
 	  ;; tab     --> blank
-	  (subst-char-in-region (point-min) (point-max)	 9 ?  t)
+	  (subst-char-in-region (point-min) (point-max)	 9 ?\s t)
 
 	  (goto-char (point-min))
 	  ;; tidyness in case hook is not robust when it looks at this
