$NetBSD: patch-sasl-xoauth2.el,v 1.1 2023/09/03 14:58:39 mef Exp $

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./sasl-xoauth2.el	1970-01-01 09:00:00.000000000 +0900
+++ ././sasl-xoauth2.el	2020-09-05 16:02:39.901994104 +0900
@@ -0,0 +1,248 @@
+;;; sasl-xoauth2.el --- OAuth 2.0 module for the SASL client framework  -*- lexical-binding: t -*-
+
+;; Copyright (C) 2018 Kazuhiro Ito
+
+;; Author: Kazuhiro Ito <kzhr@d1.dion.ne.jp>
+;; Keywords: SASL, OAuth 2.0
+;; Version: 1.00
+;; Created: January 2018
+
+;; This program is free software; you can redistribute it and/or modify
+;; it under the terms of the GNU General Public License as published by
+;; the Free Software Foundation; either version 3, or (at your option)
+;; any later version.
+;;
+;; This program is distributed in the hope that it will be useful,
+;; but WITHOUT ANY WARRANTY; without even the implied warranty of
+;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+;; GNU General Public License for more details.
+;;
+;; You should have received a copy of the GNU General Public License
+;; along with this program; see the file COPYING.  If not, write to the
+;; Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
+;; Boston, MA 02110-1301, USA.
+
+;;; Commentary:
+
+;; This is a SASL interface layer for OAuth 2.0 authorization message.
+
+;;; Requirements:
+;;
+;; * oauth2.el
+;; https://elpa.gnu.org/packages/oauth2.html
+
+;;; Usage
+;;
+;; 1. Set up sasl-xoauth2-host-url-table and
+;; sasl-xoauth2-host-user-id-table variables.
+;;
+;; 2. When passphrase is asked, input client secret.
+
+;;; Code:
+
+(require 'sasl)
+(require 'oauth2)
+
+(defconst sasl-xoauth2-steps
+  '(sasl-xoauth2-response))
+
+(defgroup sasl-xoauth2 nil
+  "SASL interface layer for OAuth 2.0 authorization message."
+  :group 'mail)
+
+(defcustom sasl-xoauth2-token-directory
+  (expand-file-name "sasl-xoauth2" user-emacs-directory)
+  "Directory name to store OAuth 2.0 tokens."
+  :type 'directory
+  :group 'sasl-xoauth2)
+
+(defcustom sasl-xoauth2-refresh-token-threshold 60
+  "Refresh token if expiration limit is left less than specified seconds."
+  :type 'number
+  :group 'sasl-xoauth2)
+
+(defcustom sasl-xoauth2-host-url-table
+  '(;; Gmail
+    ("gmail\\.com$"
+     "https://accounts.google.com/o/oauth2/v2/auth"
+     "https://www.googleapis.com/oauth2/v4/token"
+     "https://mail.google.com/"
+     nil)
+    ;; Outlook.com
+    ("outlook\\.com$"
+     "https://login.live.com/oauth20_authorize.srf"
+     "https://login.live.com/oauth20_token.srf"
+     "wl.offline_access wl.imap"
+     ;; You need register redirect URL at Application Registration Portal
+     ;; https://apps.dev.microsoft.com/
+     "http://localhost/result"))
+  "List of OAuth 2.0 URLs.  Each element of list is regexp for host, auth-url, token-url, scope and redirect-uri (optional)."
+      :type '(repeat (list
+		      (regexp :tag "Regexp for Host")
+		      (string :tag "Auth-URL")
+		      (string :tag "Token-URL")
+		      (string :tag "Scope")
+		      (choice string (const :tag "none" nil))))
+      :group 'sasl-xoauth2)
+
+(defcustom sasl-xoauth2-host-user-id-table
+  nil
+  "List of OAuth 2.0 Client IDs.  Each element of list is regexp for host, regexp for User ID, client ID and client secret (optional).
+Below is example to use Thunderbird's client ID and secret (not recommended, just an expample).
+
+(setq sasl-xoauth2-host-user-id-table
+      '((\"\\\\.gmail\\\\.com$\"
+	 \".\"
+	 \"91623021742-ud877vhta8ch9llegih22bc7er6589ar.apps.googleusercontent.com\"
+	 \"iBn5rLbhbm_qoPbdGkgX81Dj\"))
+"
+  :type '(repeat (list
+		  (regexp :tag "Regexp for Host")
+		  (regexp :tag "Regexp for User ID")
+		  (string :tag "Client ID")
+		  (choice :tag "Client Secret"
+			  string
+			  (const :tag "none" nil))))
+  :group 'sasl-xoauth2)
+
+
+;; This advice makes oauth2.el to keep the time of getting token.
+(defadvice oauth2-make-access-request (after sasl-xoauth2 disable)
+  (setq ad-return-value (cons `(auth_time . ,(current-time))
+			      ad-return-value)))
+
+;; Modified version of oauth2-refresh-access.  It keeps refreshed time
+;; and updates expires_in parameter.
+(defun sasl-xoauth2-refresh-access (token)
+  "Refresh OAuth access TOKEN.
+TOKEN should be obtained with `oauth2-request-access'."
+  (let ((response
+	 (oauth2-make-access-request
+          (oauth2-token-token-url token)
+          (concat "client_id=" (oauth2-token-client-id token)
+                  "&client_secret=" (oauth2-token-client-secret token)
+                  "&refresh_token=" (oauth2-token-refresh-token token)
+                  "&grant_type=refresh_token"))))
+    (setf (oauth2-token-access-token token)
+          (cdr (assq 'access_token response)))
+    ;; Update authorization time.
+    (setcdr (assq 'auth_time (oauth2-token-access-response token))
+	    (current-time))
+    ;; Update expires_in parameter.
+    (cond
+     ((and (assq 'expires_in (oauth2-token-access-response token))
+	   (assq 'expires_in response))
+      (setcdr (assq 'expires_in (oauth2-token-access-response token))
+	      (cdr (assq 'expires_in response))))
+     ((assq 'expires_in (oauth2-token-access-response token))
+      (let ((list (memq (assq 'expires_in (oauth2-token-access-response token))
+			(oauth2-token-access-response token))))
+	(setcdr list (cdr list))))
+     ((assq 'expires_in response)
+      (setf (oauth2-token-access-response token)
+	    (cons (assq 'expires_in response)
+		  (oauth2-token-access-response token))))))
+  ;; If the token has a plstore, update it
+  (let ((plstore (oauth2-token-plstore token)))
+    (when plstore
+      (plstore-put plstore (oauth2-token-plstore-id token)
+                   nil `(:access-token
+                         ,(oauth2-token-access-token token)
+                         :refresh-token
+                         ,(oauth2-token-refresh-token token)
+                         :access-response
+                         ,(oauth2-token-access-response token)))
+      (plstore-save plstore)))
+  token)
+
+(defun sasl-xoauth2-resolve-urls (host user)
+  (let (auth-url token-url client-id scope redirect-uri client-secret)
+    (let ((table sasl-xoauth2-host-url-table))
+      (while table
+	(when (string-match (caar table) host)
+	  (setq auth-url  (nth 1 (car table))
+		token-url (nth 2 (car table))
+		scope     (nth 3 (car table))
+		redirect-uri (nth 4 (car table))
+		table nil))
+	(setq table (cdr table))))
+    (let ((table sasl-xoauth2-host-user-id-table))
+      (while table
+	(when (and (string-match (caar table) host)
+		   (string-match (nth 1 (car table)) user))
+	  (setq client-id (nth 2 (car table))
+		client-secret (nth 3 (car table))
+		table nil))
+	(setq table (cdr table))))
+    (list auth-url token-url scope client-id client-secret redirect-uri)))
+
+(defun sasl-xoauth2-token-expired-p (token)
+  (let ((access-response (oauth2-token-access-response token)))
+    (or (null (assq 'expires_in access-response))
+	(time-less-p
+	 (time-add (cdr (assq 'auth_time access-response))
+		   (cdr (assq 'expires_in access-response)))
+	 (time-add (current-time)
+		   (- sasl-xoauth2-refresh-token-threshold))))))
+
+(defun sasl-xoauth2-response (client _step &optional _retry)
+  (let ((host (sasl-client-server client))
+	(user (sasl-client-name client))
+	info access-token oauth2-token
+	auth-url token-url client-id scope redirect-uri client-secret)
+    (setq info (sasl-xoauth2-resolve-urls host user)
+	  auth-url
+	  (or (car info)
+	      (read-string (format "Input OAuth 2.0 AUTH-URL for %s: " host)))
+	  token-url
+	  (or (nth 1 info)
+	      (read-string (format "Input OAuth 2.0 TOKEN-URL for %s: " host)))
+	  scope
+	  (or (nth 2 info)
+	      (read-string (format "Input OAuth 2.0 SCOPE for %s: " host)))
+	  client-id
+	  (or (nth 3 info)
+	      (read-string
+	       (format "Input OAuth 2.0 CLIENT-ID for %s@%s: " user host)
+	       user nil user))
+	  client-secret
+	  (or (nth 4 info)
+	      (sasl-read-passphrase
+	       (format "Input Oauth 2.0 CLIENT-SECRET for %s@%s: " user host)))
+	  redirect-uri
+	  (or (nth 5 info)
+	      ;; Do not ask when sasl-xoauth2-host-url-table is
+	      ;; matched.
+	      (unless (car info)
+		(read-string
+		 (format "Input OAuth 2.0 Redirect-URI for %s: " host)))))
+    (setq oauth2-token
+	  (let ((oauth2-token-file
+		 (expand-file-name (concat
+				    (md5 (concat
+					  client-id
+					  client-secret
+					  (sasl-client-name client)))
+				    ".plstore")
+				   sasl-xoauth2-token-directory)))
+	    (ad-enable-advice 'oauth2-make-access-request 'after 'sasl-xoauth2)
+	    (ad-activate 'oauth2-make-access-request)
+	    (prog1
+		(oauth2-auth-and-store
+		 auth-url token-url scope client-id client-secret redirect-uri)
+	      (ad-disable-advice 'oauth2-make-access-request
+				 'after 'sasl-xoauth2)
+	      (ad-activate 'oauth2-make-access-request))))
+    (when (sasl-xoauth2-token-expired-p oauth2-token)
+      (setq oauth2-token (sasl-xoauth2-refresh-access oauth2-token)))
+    (setq access-token (oauth2-token-access-token oauth2-token))
+    (format "user=%s\001auth=Bearer %s\001\001"
+	    (sasl-client-name client)
+	    access-token)))
+
+(put 'sasl-xoauth2 'sasl-mechanism
+     (sasl-make-mechanism "XOAUTH2" sasl-xoauth2-steps))
+
+(provide 'sasl-xoauth2)
+
+;;; sasl-xoauth2.el ends here
