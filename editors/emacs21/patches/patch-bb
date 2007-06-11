$NetBSD: patch-bb,v 1.1 2007/06/11 13:38:43 markd Exp $

--- lisp/mail/smtpmail.el.orig	2006-09-02 00:23:45.000000000 +0300
+++ lisp/mail/smtpmail.el
@@ -1,12 +1,15 @@
 ;;; smtpmail.el --- simple SMTP protocol (RFC 821) for sending mail
 
-;; Copyright (C) 1995, 1996, 2001 Free Software Foundation, Inc.
+;; Copyright (C) 1995, 1996, 2001, 2002, 2003, 2004, 2005,
+;;   2006 Free Software Foundation, Inc.
 
 ;; Author: Tomoji Kagatani <kagatani@rbc.ncl.omron.co.jp>
-;; Maintainer: Brian D. Carlstrom <bdc@ai.mit.edu>
+;; Maintainer: Simon Josefsson <simon@josefsson.org>
+;; w32 Maintainer: Brian D. Carlstrom <bdc@ai.mit.edu>
 ;; ESMTP support: Simon Leinen <simon@switch.ch>
 ;; Hacked by Mike Taylor, 11th October 1999 to add support for
 ;; automatically appending a domain to RCPT TO: addresses.
+;; AUTH=LOGIN support: Stephen Cranefield <scranefield@infoscience.otago.ac.nz>
 ;; Keywords: mail
 
 ;; This file is part of GNU Emacs.
@@ -23,8 +26,8 @@
 
 ;; You should have received a copy of the GNU General Public License
 ;; along with GNU Emacs; see the file COPYING.  If not, write to the
-;; Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-;; Boston, MA 02111-1307, USA.
+;; Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
+;; Boston, MA 02110-1301, USA.
 
 ;;; Commentary:
 
@@ -33,20 +36,48 @@
 ;; Please add these lines in your .emacs(_emacs) or use customize.
 ;;
 ;;(setq send-mail-function 'smtpmail-send-it) ; if you use `mail'
-;;(setq message-send-mail-function 'smtpmail-send-it) ; if you are using Gnus.
+;;(setq message-send-mail-function 'smtpmail-send-it) ; if you use message/Gnus
 ;;(setq smtpmail-default-smtp-server "YOUR SMTP HOST")
 ;;(setq smtpmail-local-domain "YOUR DOMAIN NAME")
 ;;(setq smtpmail-sendto-domain "YOUR DOMAIN NAME")
 ;;(setq smtpmail-debug-info t) ; only to debug problems
+;;(setq smtpmail-auth-credentials  ; or use ~/.authinfo
+;;      '(("YOUR SMTP HOST" 25 "username" "password")))
+;;(setq smtpmail-starttls-credentials
+;;      '(("YOUR SMTP HOST" 25 "~/.my_smtp_tls.key" "~/.my_smtp_tls.cert")))
+;; Where the 25 equals the value of `smtpmail-smtp-service', it can be an
+;; integer or a string, just as long as they match (eq).
 
 ;; To queue mail, set smtpmail-queue-mail to t and use
 ;; smtpmail-send-queued-mail to send.
 
+;; Modified by Stephen Cranefield <scranefield@infoscience.otago.ac.nz>,
+;; 22/6/99, to support SMTP Authentication by the AUTH=LOGIN mechanism.
+;; See http://help.netscape.com/products/server/messaging/3x/info/smtpauth.html
+;; Rewritten by Simon Josefsson to use same credential variable as AUTH
+;; support below.
+
+;; Modified by Simon Josefsson <jas@pdc.kth.se>, 22/2/99, to support SMTP
+;; Authentication by the AUTH mechanism.
+;; See http://www.ietf.org/rfc/rfc2554.txt
+
+;; Modified by Simon Josefsson <simon@josefsson.org>, 2000-10-07, to support
+;; STARTTLS.  Requires external program
+;; ftp://ftp.opaopa.org/pub/elisp/starttls-*.tar.gz.
+;; See http://www.ietf.org/rfc/rfc2246.txt, http://www.ietf.org/rfc/rfc2487.txt
 
 ;;; Code:
 
 (require 'sendmail)
-(require 'time-stamp)
+(autoload 'starttls-open-stream "starttls")
+(autoload 'starttls-negotiate "starttls")
+(autoload 'mail-strip-quoted-names "mail-utils")
+(autoload 'message-make-date "message")
+(autoload 'message-make-message-id "message")
+(autoload 'rfc2104-hash "rfc2104")
+(autoload 'netrc-parse "netrc")
+(autoload 'netrc-machine "netrc")
+(autoload 'netrc-get "netrc")
 
 ;;;
 (defgroup smtpmail nil
@@ -55,7 +86,8 @@
 
 
 (defcustom smtpmail-default-smtp-server nil
-  "*Specify default SMTP server."
+  "*Specify default SMTP server.
+This only has effect if you specify it before loading the smtpmail library."
   :type '(choice (const nil) string)
   :group 'smtpmail)
 
@@ -66,8 +98,9 @@
   :group 'smtpmail)
 
 (defcustom smtpmail-smtp-service 25
-  "*SMTP service port number. smtp or 25 ."
-  :type 'integer
+  "*SMTP service port number.
+The default value would be \"smtp\" or 25 ."
+  :type '(choice (integer :tag "Port") (string :tag "Service"))
   :group 'smtpmail)
 
 (defcustom smtpmail-local-domain nil
@@ -94,7 +127,15 @@ buffer includes an exchange like:
   :group 'smtpmail)
 
 (defcustom smtpmail-debug-info nil
-  "*smtpmail debug info printout. messages and process buffer."
+  "Whether to print info in buffer *trace of SMTP session to <somewhere>*.
+See also `smtpmail-debug-verb' which determines if the SMTP protocol should
+be verbose as well."
+  :type 'boolean
+  :group 'smtpmail)
+
+(defcustom smtpmail-debug-verb nil
+  "Whether this library sends the SMTP VERB command or not.
+The commands enables verbose information from the SMTP server."
   :type 'boolean
   :group 'smtpmail)
 
@@ -115,6 +156,34 @@ and sent with `smtpmail-send-queued-mail
   :type 'directory
   :group 'smtpmail)
 
+(defcustom smtpmail-auth-credentials "~/.authinfo"
+  "Specify username and password for servers, directly or via .netrc file.
+This variable can either be a filename pointing to a file in netrc(5)
+format, or list of four-element lists that contain, in order,
+`servername' (a string), `port' (an integer), `user' (a string) and
+`password' (a string, or nil to query the user when needed).  If you
+need to enter a `realm' too, add it to the user string, so that it
+looks like `user@realm'."
+  :type '(choice file
+		 (repeat (list (string  :tag "Server")
+		       (integer :tag "Port")
+		       (string  :tag "Username")
+		       (choice (const :tag "Query when needed" nil)
+				       (string  :tag "Password")))))
+  :version "22.1"
+  :group 'smtpmail)
+
+(defcustom smtpmail-starttls-credentials '(("" 25 "" ""))
+  "Specify STARTTLS keys and certificates for servers.
+This is a list of four-element list with `servername' (a string),
+`port' (an integer), `key' (a filename) and `certificate' (a filename)."
+  :type '(repeat (list (string  :tag "Server")
+		       (integer :tag "Port")
+		       (file    :tag "Key")
+		       (file    :tag "Certificate")))
+  :version "21.1"
+  :group 'smtpmail)
+
 (defcustom smtpmail-warn-about-unknown-extensions nil
   "*If set, print warnings about unknown SMTP extensions.
 This is mainly useful for development purposes, to learn about
@@ -130,19 +199,26 @@ This is relative to `smtpmail-queue-dir'
 (defvar smtpmail-address-buffer)
 (defvar smtpmail-recipient-address-list)
 
+(defvar smtpmail-queue-counter 0)
+
 ;; Buffer-local variable.
 (defvar smtpmail-read-point)
 
 (defvar smtpmail-queue-index (concat smtpmail-queue-dir
 				     smtpmail-queue-index-file))
 
+(defconst smtpmail-auth-supported '(cram-md5 plain login)
+  "List of supported SMTP AUTH mechanisms.")
+
 ;;;
 ;;;
 ;;;
 
+(defvar smtpmail-mail-address nil
+  "Value to use for envelope-from address for mail from ambient buffer.")
+
 ;;;###autoload
 (defun smtpmail-send-it ()
-  (require 'mail-utils)
   (let ((errbuf (if mail-interactive
 		    (generate-new-buffer " smtpmail errors")
 		  0))
@@ -150,6 +226,11 @@ This is relative to `smtpmail-queue-dir'
 	(case-fold-search nil)
 	delimline
 	(mailbuf (current-buffer))
+        ;; Examine this variable now, so that
+	;; local binding in the mail buffer will take effect.
+	(smtpmail-mail-address
+         (or (and mail-specify-envelope-from (mail-envelope-from))
+             user-mail-address))
 	(smtpmail-code-conv-from
 	 (if enable-multibyte-characters
 	     (let ((sendmail-coding-system smtpmail-code-conv-from))
@@ -190,7 +271,7 @@ This is relative to `smtpmail-queue-dir'
 	    ;; they put one in themselves.
 	    (goto-char (point-min))
 	    (if (not (re-search-forward "^From:" delimline t))
-		(let* ((login user-mail-address)
+		(let* ((login smtpmail-mail-address)
 		       (fullname (user-full-name)))
 		  (cond ((eq mail-from-style 'angles)
 			 (insert "From: " fullname)
@@ -232,6 +313,14 @@ This is relative to `smtpmail-queue-dir'
 			 (insert ")\n"))
 			((null mail-from-style)
 			 (insert "From: " login "\n")))))
+	    ;; Insert a `Message-Id:' field if there isn't one yet.
+	    (goto-char (point-min))
+	    (unless (re-search-forward "^Message-Id:" delimline t)
+	      (insert "Message-Id: " (message-make-message-id) "\n"))
+	    ;; Insert a `Date:' field if there isn't one yet.
+	    (goto-char (point-min))
+	    (unless (re-search-forward "^Date:" delimline t)
+	      (insert "Date: " (message-make-date) "\n"))
 	    ;; Insert an extra newline if we need it to work around
 	    ;; Sun's bug that swallows newlines.
 	    (goto-char (1+ delimline))
@@ -242,8 +331,7 @@ This is relative to `smtpmail-queue-dir'
 	    (if (re-search-forward "^FCC:" delimline t)
 		(mail-do-fcc delimline))
 	    (if mail-interactive
-		(save-excursion
-		  (set-buffer errbuf)
+		(with-current-buffer errbuf
 		  (erase-buffer))))
 	  ;;
 	  ;;
@@ -261,19 +349,23 @@ This is relative to `smtpmail-queue-dir'
 			    smtpmail-recipient-address-list tembuf))
 		      (error "Sending failed; SMTP protocol error"))
 		(error "Sending failed; no recipients"))
-	    (let* ((file-data (concat
-			       smtpmail-queue-dir
-			       (concat (time-stamp-yyyy-mm-dd)
-				       "_" (time-stamp-hh:mm:ss))))
-		      (file-data (convert-standard-filename file-data))
-		      (file-elisp (concat file-data ".el"))
+	    (let* ((file-data
+		    (expand-file-name
+		     (format "%s_%i"
+			     (format-time-string "%Y-%m-%d_%H:%M:%S")
+			     (setq smtpmail-queue-counter
+				   (1+ smtpmail-queue-counter)))
+		     smtpmail-queue-dir))
+		   (file-data (convert-standard-filename file-data))
+		   (file-elisp (concat file-data ".el"))
 		   (buffer-data (create-file-buffer file-data))
 		   (buffer-elisp (create-file-buffer file-elisp))
 		   (buffer-scratch "*queue-mail*"))
-	      (save-excursion
-		(set-buffer buffer-data)
+	      (unless (file-exists-p smtpmail-queue-dir)
+		(make-directory smtpmail-queue-dir t))
+	      (with-current-buffer buffer-data
 		(erase-buffer)
-		(insert-buffer tembuf)
+		(insert-buffer-substring tembuf)
 		(write-file file-data)
 		(set-buffer buffer-elisp)
 		(erase-buffer)
@@ -299,35 +391,33 @@ This is relative to `smtpmail-queue-dir'
 (defun smtpmail-send-queued-mail ()
   "Send mail that was queued as a result of setting `smtpmail-queue-mail'."
   (interactive)
-  ;;; Get index, get first mail, send it, get second mail, etc...
-  (let ((buffer-index (find-file-noselect smtpmail-queue-index))
-	(file-msg "")
-	(tembuf nil))
-    (save-excursion
-      (set-buffer buffer-index)
-      (beginning-of-buffer)
+  (with-temp-buffer
+    ;;; Get index, get first mail, send it, update index, get second
+    ;;; mail, send it, etc...
+    (let ((file-msg ""))
+      (insert-file-contents smtpmail-queue-index)
+      (goto-char (point-min))
       (while (not (eobp))
-	(setq file-msg (buffer-substring (point) (save-excursion
-						   (end-of-line)
-						   (point))))
+	(setq file-msg (buffer-substring (point) (line-end-position)))
 	(load file-msg)
 	;; Insert the message literally: it is already encoded as per
 	;; the MIME headers, and code conversions might guess the
 	;; encoding wrongly.
-	(setq tembuf (find-file-noselect file-msg nil t))
-	(if (not (null smtpmail-recipient-address-list))
-	    (if (not (smtpmail-via-smtp smtpmail-recipient-address-list
-					tembuf))
-		(error "Sending failed; SMTP protocol error"))
-	  (error "Sending failed; no recipients"))
+	(with-temp-buffer
+	  (let ((coding-system-for-read 'no-conversion))
+	    (insert-file-contents file-msg))
+          (let ((smtpmail-mail-address
+                 (or (and mail-specify-envelope-from (mail-envelope-from))
+                     user-mail-address)))
+            (if (not (null smtpmail-recipient-address-list))
+                (if (not (smtpmail-via-smtp smtpmail-recipient-address-list
+                                            (current-buffer)))
+                    (error "Sending failed; SMTP protocol error"))
+              (error "Sending failed; no recipients"))))
 	(delete-file file-msg)
 	(delete-file (concat file-msg ".el"))
-	(kill-buffer tembuf)
-	(kill-line 1))
-      (set-buffer buffer-index)
-      (save-buffer smtpmail-queue-index)
-      (kill-buffer buffer-index)
-      )))
+	(delete-region (point-at-bol) (point-at-bol 2)))
+      (write-region (point-min) (point-max) smtpmail-queue-index))))
 
 ;(defun smtpmail-via-smtp (host,port,sender,destination,smtpmail-text-buffer)
 
@@ -336,17 +426,175 @@ This is relative to `smtpmail-queue-dir'
       (concat (system-name) "." smtpmail-local-domain)
     (system-name)))
 
+(defsubst smtpmail-cred-server (cred)
+  (nth 0 cred))
+
+(defsubst smtpmail-cred-port (cred)
+  (nth 1 cred))
+
+(defsubst smtpmail-cred-key (cred)
+  (nth 2 cred))
+
+(defsubst smtpmail-cred-user (cred)
+  (nth 2 cred))
+
+(defsubst smtpmail-cred-cert (cred)
+  (nth 3 cred))
+
+(defsubst smtpmail-cred-passwd (cred)
+  (nth 3 cred))
+
+(defun smtpmail-find-credentials (cred server port)
+  (catch 'done
+    (let ((l cred) el)
+      (while (setq el (pop l))
+	(when (and (equal server (smtpmail-cred-server el))
+		   (equal port (smtpmail-cred-port el)))
+	  (throw 'done el))))))
+
 (defun smtpmail-maybe-append-domain (recipient)
   (if (or (not smtpmail-sendto-domain)
 	  (string-match "@" recipient))
       recipient
     (concat recipient "@" smtpmail-sendto-domain)))
 
+(defun smtpmail-intersection (list1 list2)
+  (let ((result nil))
+    (dolist (el2 list2)
+      (when (memq el2 list1)
+	(push el2 result)))
+    (nreverse result)))
+
+(defvar starttls-extra-args)
+(defvar starttls-extra-arguments)
+
+(defun smtpmail-open-stream (process-buffer host port)
+  (let ((cred (smtpmail-find-credentials
+	       smtpmail-starttls-credentials host port)))
+    (if (null (and cred (condition-case ()
+			    (with-no-warnings
+			      (require 'starttls)
+			      (call-process (if starttls-use-gnutls
+						starttls-gnutls-program
+					      starttls-program)))
+			  (error nil))))
+	;; The normal case.
+	(open-network-stream "SMTP" process-buffer host port)
+      (let* ((cred-key (smtpmail-cred-key cred))
+	     (cred-cert (smtpmail-cred-cert cred))
+	     (starttls-extra-args
+	      (append
+	       starttls-extra-args
+	       (when (and (stringp cred-key) (stringp cred-cert)
+			  (file-regular-p
+			   (setq cred-key (expand-file-name cred-key)))
+			  (file-regular-p
+			   (setq cred-cert (expand-file-name cred-cert))))
+		 (list "--key-file" cred-key "--cert-file" cred-cert))))
+	     (starttls-extra-arguments
+	      (append
+	       starttls-extra-arguments
+	       (when (and (stringp cred-key) (stringp cred-cert)
+			  (file-regular-p
+			   (setq cred-key (expand-file-name cred-key)))
+			  (file-regular-p
+			   (setq cred-cert (expand-file-name cred-cert))))
+		 (list "--x509keyfile" cred-key "--x509certfile" cred-cert)))))
+	(starttls-open-stream "SMTP" process-buffer host port)))))
+
+(defun smtpmail-try-auth-methods (process supported-extensions host port)
+  (let* ((mechs (cdr-safe (assoc 'auth supported-extensions)))
+	 (mech (car (smtpmail-intersection smtpmail-auth-supported mechs)))
+	 (cred (if (stringp smtpmail-auth-credentials)
+		   (let* ((netrc (netrc-parse smtpmail-auth-credentials))
+                          (port-name (format "%s" (or port "smtp")))
+			  (hostentry (netrc-machine netrc host port-name
+                                                    port-name)))
+                     (when hostentry
+                       (list host port
+                             (netrc-get hostentry "login")
+                             (netrc-get hostentry "password"))))
+		 (smtpmail-find-credentials
+		  smtpmail-auth-credentials host port)))
+	 (passwd (when cred
+		   (or (smtpmail-cred-passwd cred)
+		       (read-passwd
+			(format "SMTP password for %s:%s: "
+				(smtpmail-cred-server cred)
+				(smtpmail-cred-port cred))))))
+	 ret)
+    (when (and cred mech)
+      (cond
+       ((eq mech 'cram-md5)
+	(smtpmail-send-command process (upcase (format "AUTH %s" mech)))
+	(if (or (null (car (setq ret (smtpmail-read-response process))))
+		(not (integerp (car ret)))
+		(>= (car ret) 400))
+	    (throw 'done nil))
+	(when (eq (car ret) 334)
+	  (let* ((challenge (substring (cadr ret) 4))
+		 (decoded (base64-decode-string challenge))
+		 (hash (rfc2104-hash 'md5 64 16 passwd decoded))
+		 (response (concat (smtpmail-cred-user cred) " " hash))
+		 (encoded (base64-encode-string response)))
+	    (smtpmail-send-command process (format "%s" encoded))
+	    (if (or (null (car (setq ret (smtpmail-read-response process))))
+		    (not (integerp (car ret)))
+		    (>= (car ret) 400))
+		(throw 'done nil)))))
+       ((eq mech 'login)
+	(smtpmail-send-command process "AUTH LOGIN")
+	(if (or (null (car (setq ret (smtpmail-read-response process))))
+		(not (integerp (car ret)))
+		(>= (car ret) 400))
+	    (throw 'done nil))
+	(smtpmail-send-command
+	 process (base64-encode-string (smtpmail-cred-user cred)))
+	(if (or (null (car (setq ret (smtpmail-read-response process))))
+		(not (integerp (car ret)))
+		(>= (car ret) 400))
+	    (throw 'done nil))
+	(smtpmail-send-command process (base64-encode-string passwd))
+	(if (or (null (car (setq ret (smtpmail-read-response process))))
+		(not (integerp (car ret)))
+		(>= (car ret) 400))
+	    (throw 'done nil)))
+       ((eq mech 'plain)
+	;; We used to send an empty initial request, and wait for an
+	;; empty response, and then send the password, but this
+	;; violate a SHOULD in RFC 2222 paragraph 5.1.  Note that this
+	;; is not sent if the server did not advertise AUTH PLAIN in
+	;; the EHLO response.  See RFC 2554 for more info.
+	(smtpmail-send-command process
+			       (concat "AUTH PLAIN "
+				       (base64-encode-string
+					(concat "\0"
+						(smtpmail-cred-user cred)
+						"\0"
+						passwd))))
+	(if (or (null (car (setq ret (smtpmail-read-response process))))
+		(not (integerp (car ret)))
+		(not (equal (car ret) 235)))
+	    (throw 'done nil)))
+
+       (t
+	(error "Mechanism %s not implemented" mech)))
+      ;; Remember the password.
+      (when (and (not (stringp smtpmail-auth-credentials))
+		 (null (smtpmail-cred-passwd cred)))
+	(setcar (cdr (cdr (cdr cred))) passwd)))))
+
 (defun smtpmail-via-smtp (recipient smtpmail-text-buffer)
   (let ((process nil)
 	(host (or smtpmail-smtp-server
 		  (error "`smtpmail-smtp-server' not defined")))
 	(port smtpmail-smtp-service)
+        ;; smtpmail-mail-address should be set to the appropriate
+        ;; buffer-local value by the caller, but in case not:
+        (envelope-from (or smtpmail-mail-address
+                           (and mail-specify-envelope-from
+                                (mail-envelope-from))
+                           user-mail-address))
 	response-code
 	greeting
 	process-buffer
@@ -358,19 +606,18 @@ This is relative to `smtpmail-queue-dir'
 		(get-buffer-create (format "*trace of SMTP session to %s*" host)))
 
 	  ;; clear the trace buffer of old output
-	  (save-excursion
-	    (set-buffer process-buffer)
+	  (with-current-buffer process-buffer
+	    (setq buffer-undo-list t)
 	    (erase-buffer))
 
 	  ;; open the connection to the server
-	  (setq process (open-network-stream "SMTP" process-buffer host port))
+	  (setq process (smtpmail-open-stream process-buffer host port))
 	  (and (null process) (throw 'done nil))
 
 	  ;; set the send-filter
 	  (set-process-filter process 'smtpmail-process-filter)
 
-	  (save-excursion
-	    (set-buffer process-buffer)
+	  (with-current-buffer process-buffer
 	    (set-buffer-process-coding-system 'raw-text-unix 'raw-text-unix)
 	    (make-local-variable 'smtpmail-read-point)
 	    (setq smtpmail-read-point (point-min))
@@ -382,32 +629,58 @@ This is relative to `smtpmail-queue-dir'
 		(throw 'done nil)
 	      )
 
+	    (let ((do-ehlo t)
+		  (do-starttls t))
+	      (while do-ehlo
 	    ;; EHLO
 	    (smtpmail-send-command process (format "EHLO %s" (smtpmail-fqdn)))
 
-	    (if (or (null (car (setq response-code (smtpmail-read-response process))))
+	    (if (or (null (car (setq response-code
+				     (smtpmail-read-response process))))
 		    (not (integerp (car response-code)))
 		    (>= (car response-code) 400))
 		(progn
 		  ;; HELO
-		  (smtpmail-send-command process (format "HELO %s" (smtpmail-fqdn)))
+		  (smtpmail-send-command
+		   process (format "HELO %s" (smtpmail-fqdn)))
 
-		  (if (or (null (car (setq response-code (smtpmail-read-response process))))
+		  (if (or (null (car (setq response-code
+					   (smtpmail-read-response process))))
 			  (not (integerp (car response-code)))
 			  (>= (car response-code) 400))
 		      (throw 'done nil)))
-	      (let ((extension-lines (cdr (cdr response-code))))
-		(while extension-lines
-		  (let ((name (intern (downcase (car (split-string (substring (car extension-lines) 4) "[ ]"))))))
+	      (dolist (line (cdr (cdr response-code)))
+		(let ((name (mapcar (lambda (s) (intern (downcase s)))
+				    (split-string (substring line 4) "[ ]"))))
+		  (and (eq (length name) 1)
+		       (setq name (car name)))
 		    (and name
-			 (cond ((memq name '(verb xvrb 8bitmime onex xone
+		       (cond ((memq (if (consp name) (car name) name)
+				    '(verb xvrb 8bitmime onex xone
 						  expn size dsn etrn
-						  help xusr))
+				      enhancedstatuscodes
+				      help xusr
+				      auth=login auth starttls))
 				(setq supported-extensions
 				      (cons name supported-extensions)))
 			       (smtpmail-warn-about-unknown-extensions
-				(message "Unknown extension %s" name)))))
-		  (setq extension-lines (cdr extension-lines)))))
+			      (message "Unknown extension %s" name)))))))
+
+	    (if (and do-starttls
+		     (smtpmail-find-credentials smtpmail-starttls-credentials host port)
+		     (member 'starttls supported-extensions)
+		     (numberp (process-id process)))
+		(progn
+		  (smtpmail-send-command process (format "STARTTLS"))
+		  (if (or (null (car (setq response-code (smtpmail-read-response process))))
+			  (not (integerp (car response-code)))
+			  (>= (car response-code) 400))
+		      (throw 'done nil))
+		  (starttls-negotiate process)
+		  (setq do-starttls nil))
+	      (setq do-ehlo nil))))
+
+	    (smtpmail-try-auth-methods process supported-extensions host port)
 
 	    (if (or (member 'onex supported-extensions)
 		    (member 'xone supported-extensions))
@@ -418,7 +691,7 @@ This is relative to `smtpmail-queue-dir'
 			  (>= (car response-code) 400))
 		      (throw 'done nil))))
 
-	    (if (and smtpmail-debug-info
+	    (if (and smtpmail-debug-verb
 		     (or (member 'verb supported-extensions)
 			 (member 'xvrb supported-extensions)))
 		(progn
@@ -436,22 +709,17 @@ This is relative to `smtpmail-queue-dir'
 			  (>= (car response-code) 400))
 		      (throw 'done nil))))
 
-	    ;; MAIL FROM: <sender>
+	    ;; MAIL FROM:<sender>
 	    (let ((size-part
-		   (if (member 'size supported-extensions)
+		   (if (or (member 'size supported-extensions)
+			   (assoc 'size supported-extensions))
 		       (format " SIZE=%d"
-			       (save-excursion
-				 (set-buffer smtpmail-text-buffer)
+			       (with-current-buffer smtpmail-text-buffer
 				 ;; size estimate:
 				 (+ (- (point-max) (point-min))
 				    ;; Add one byte for each change-of-line
-				    ;; because or CR-LF representation:
-				    (count-lines (point-min) (point-max))
-				    ;; For some reason, an empty line is
-				    ;; added to the message.  Maybe this
-				    ;; is a bug, but it can't hurt to add
-				    ;; those two bytes anyway:
-				    2)))
+				    ;; because of CR-LF representation:
+				    (count-lines (point-min) (point-max)))))
 		     ""))
 		  (body-part
 		   (if (member '8bitmime supported-extensions)
@@ -471,8 +739,8 @@ This is relative to `smtpmail-queue-dir'
 			 "")
 		     "")))
 ;	      (smtpmail-send-command process (format "MAIL FROM:%s@%s" (user-login-name) (smtpmail-fqdn)))
-	      (smtpmail-send-command process (format "MAIL FROM: <%s>%s%s"
-						     user-mail-address
+	      (smtpmail-send-command process (format "MAIL FROM:<%s>%s%s"
+                                                     envelope-from
 						     size-part
 						     body-part))
 
@@ -482,10 +750,10 @@ This is relative to `smtpmail-queue-dir'
 		  (throw 'done nil)
 		))
 
-	    ;; RCPT TO: <recipient>
+	    ;; RCPT TO:<recipient>
 	    (let ((n 0))
 	      (while (not (null (nth n recipient)))
-		(smtpmail-send-command process (format "RCPT TO: <%s>" (smtpmail-maybe-append-domain (nth n recipient))))
+		(smtpmail-send-command process (format "RCPT TO:<%s>" (smtpmail-maybe-append-domain (nth n recipient))))
 		(setq n (1+ n))
 
 		(setq response-code (smtpmail-read-response process))
@@ -523,8 +791,7 @@ This is relative to `smtpmail-queue-dir'
 ;		 (throw 'done nil))
 	    t ))
       (if process
-	  (save-excursion
-	    (set-buffer (process-buffer process))
+	  (with-current-buffer (process-buffer process)
 	    (smtpmail-send-command process "QUIT")
 	    (smtpmail-read-response process)
 
@@ -533,12 +800,13 @@ This is relative to `smtpmail-queue-dir'
 ;		    (>= (car response-code) 400))
 ;		(throw 'done nil)
 ;	      )
-	    (delete-process process))))))
+	    (delete-process process)
+	    (unless smtpmail-debug-info
+	      (kill-buffer process-buffer)))))))
 
 
 (defun smtpmail-process-filter (process output)
-  (save-excursion
-    (set-buffer (process-buffer process))
+  (with-current-buffer (process-buffer process)
     (goto-char (point-max))
     (insert output)))
 
@@ -548,49 +816,49 @@ This is relative to `smtpmail-queue-dir'
 	(response-continue t)
 	(return-value '(nil ()))
 	match-end)
-
-    (while response-continue
-      (goto-char smtpmail-read-point)
-      (while (not (search-forward "\r\n" nil t))
-	(accept-process-output process)
-	(goto-char smtpmail-read-point))
-
-      (setq match-end (point))
-      (setq response-strings
-	    (cons (buffer-substring smtpmail-read-point (- match-end 2))
-		  response-strings))
-
-      (goto-char smtpmail-read-point)
-      (if (looking-at "[0-9]+ ")
-	  (let ((begin (match-beginning 0))
-		(end (match-end 0)))
-	    (if smtpmail-debug-info
-		(message "%s" (car response-strings)))
-
-	    (setq smtpmail-read-point match-end)
-
-	    ;; ignore lines that start with "0"
-	    (if (looking-at "0[0-9]+ ")
-		nil
+    (catch 'done
+      (while response-continue
+	(goto-char smtpmail-read-point)
+	(while (not (search-forward "\r\n" nil t))
+	  (unless (memq (process-status process) '(open run))
+	    (throw 'done nil))
+	  (accept-process-output process)
+	  (goto-char smtpmail-read-point))
+
+	(setq match-end (point))
+	(setq response-strings
+	      (cons (buffer-substring smtpmail-read-point (- match-end 2))
+		    response-strings))
+
+	(goto-char smtpmail-read-point)
+	(if (looking-at "[0-9]+ ")
+	    (let ((begin (match-beginning 0))
+		  (end (match-end 0)))
+	      (if smtpmail-debug-info
+		  (message "%s" (car response-strings)))
+
+	      (setq smtpmail-read-point match-end)
+
+	      ;; ignore lines that start with "0"
+	      (if (looking-at "0[0-9]+ ")
+		  nil
+		(setq response-continue nil)
+		(setq return-value
+		      (cons (string-to-number
+			     (buffer-substring begin end))
+			    (nreverse response-strings)))))
+
+	  (if (looking-at "[0-9]+-")
+	      (progn (if smtpmail-debug-info
+			 (message "%s" (car response-strings)))
+		     (setq smtpmail-read-point match-end)
+		     (setq response-continue t))
+	    (progn
+	      (setq smtpmail-read-point match-end)
 	      (setq response-continue nil)
 	      (setq return-value
-		    (cons (string-to-int
-			   (buffer-substring begin end))
-			  (nreverse response-strings)))))
-
-	(if (looking-at "[0-9]+-")
-	    (progn (if smtpmail-debug-info
-		     (message "%s" (car response-strings)))
-		   (setq smtpmail-read-point match-end)
-		   (setq response-continue t))
-	  (progn
-	    (setq smtpmail-read-point match-end)
-	    (setq response-continue nil)
-	    (setq return-value
-		  (cons nil (nreverse response-strings)))
-	    )
-	  )))
-    (setq smtpmail-read-point match-end)
+		    (cons nil (nreverse response-strings)))))))
+      (setq smtpmail-read-point match-end))
     return-value))
 
 
@@ -623,41 +891,21 @@ This is relative to `smtpmail-queue-dir'
   )
 
 (defun smtpmail-send-data (process buffer)
-  (let
-      ((data-continue t)
-       (sending-data nil)
-       this-line
-       this-line-end)
-
-    (save-excursion
-      (set-buffer buffer)
+  (let ((data-continue t) sending-data)
+    (with-current-buffer buffer
       (goto-char (point-min)))
-
     (while data-continue
-      (save-excursion
-	(set-buffer buffer)
-	(beginning-of-line)
-	(setq this-line (point))
-	(end-of-line)
-	(setq this-line-end (point))
-	(setq sending-data nil)
-	(setq sending-data (buffer-substring this-line this-line-end))
-	(if (/= (forward-line 1) 0)
-	    (setq data-continue nil)))
-
-      (smtpmail-send-data-1 process sending-data)
-      )
-    )
-  )
-
+      (with-current-buffer buffer
+        (setq sending-data (buffer-substring (point-at-bol) (point-at-eol)))
+	(end-of-line 2)
+        (setq data-continue (not (eobp))))
+      (smtpmail-send-data-1 process sending-data))))
 
 (defun smtpmail-deduce-address-list (smtpmail-text-buffer header-start header-end)
   "Get address list suitable for smtp RCPT TO: <address>."
-  (require 'mail-utils)  ;; pick up mail-strip-quoted-names
-
   (unwind-protect
-      (save-excursion
-	(set-buffer smtpmail-address-buffer) (erase-buffer)
+      (with-current-buffer smtpmail-address-buffer
+	(erase-buffer)
 	(let
 	    ((case-fold-search t)
 	     (simple-address-list "")
@@ -668,9 +916,11 @@ This is relative to `smtpmail-queue-dir'
 	  (goto-char (point-min))
 	  ;; RESENT-* fields should stop processing of regular fields.
 	  (save-excursion
-	    (if (re-search-forward "^Resent-\\(to\\|cc\\|bcc\\):" header-end t)
-		(setq addr-regexp "^Resent-\\(to\\|cc\\|bcc\\):")
-	      (setq addr-regexp  "^\\(To:\\|Cc:\\|Bcc:\\)")))
+	    (setq addr-regexp
+		  (if (re-search-forward "^Resent-\\(to\\|cc\\|bcc\\):"
+					 header-end t)
+		      "^Resent-\\(to\\|cc\\|bcc\\):"
+		    "^\\(To:\\|Cc:\\|Bcc:\\)")))
 
 	  (while (re-search-forward addr-regexp header-end t)
 	    (replace-match "")
@@ -685,9 +935,7 @@ This is relative to `smtpmail-queue-dir'
 			  (mail-strip-quoted-names (buffer-substring this-line this-line-end))))
 	    )
 	  (erase-buffer)
-	  (insert-string " ")
-	  (insert-string simple-address-list)
-	  (insert-string "\n")
+	  (insert " " simple-address-list "\n")
 	  (subst-char-in-region (point-min) (point-max) 10 ?  t);; newline --> blank
 	  (subst-char-in-region (point-min) (point-max) ?, ?  t);; comma   --> blank
 	  (subst-char-in-region (point-min) (point-max)  9 ?  t);; tab     --> blank
@@ -729,4 +977,5 @@ many continuation lines."
 
 (provide 'smtpmail)
 
+;;; arch-tag: a76992df-6d71-43b7-9e72-4bacc6c05466
 ;;; smtpmail.el ends here
