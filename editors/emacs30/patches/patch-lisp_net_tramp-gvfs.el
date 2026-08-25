$NetBSD: patch-lisp_net_tramp-gvfs.el,v 1.1 2026/08/25 17:44:23 wiz Exp $

CVE-2026-79992: Fix local command execution vulnerability in tramp
https://gitweb.gentoo.org/proj/emacs-patches.git/commit/emacs/30.2/05_all_tramp.patch?id=2a6292f81affedcc468c594c60808e652ae87118

--- lisp/net/tramp-gvfs.el.orig	2025-04-05 11:01:10.000000000 +0000
+++ lisp/net/tramp-gvfs.el
@@ -1241,7 +1241,7 @@ file names."
 	  (when (string-match
 		 (rx bos "/" (+ (not "/")) (group "/.." (? "/"))) localname)
 	    (setq localname (replace-match "/" t t localname 1)))
-	(when (string-match (rx bol "/.." (? "/")) localname)
+	(when (string-match (rx bos "/.." (? "/")) localname)
 	  (setq localname (replace-match "/" t t localname))))
       ;; There might be a double slash.  Remove this.
       (while (string-match "//" localname)
@@ -1335,8 +1335,8 @@ If FILE-SYSTEM is non-nil, return file system attribut
   (with-parsed-tramp-file-name filename nil
     (setq localname (file-name-unquote localname))
     (if (or (and (string-match-p
-		  (rx bol (| "afp" (: "dav" (? "s")) "smb") eol) method)
-		 (string-match-p (rx bol (? "/") (+ (not "/")) eol) localname))
+		  (rx bos (| "afp" (: "dav" (? "s")) "smb") eos) method)
+		 (string-match-p (rx bos (? "/") (+ (not "/")) eos) localname))
 	    (string-equal localname "/"))
 	(tramp-gvfs-get-root-attributes filename)
       (assoc
@@ -1773,14 +1773,14 @@ ID-FORMAT valid values are `string' and `integer'."
   "Retrieve file name from D-Bus OBJECT-PATH."
   (dbus-unescape-from-identifier
    (replace-regexp-in-string
-    (rx bol (* nonl) "/" (group (+ (not "/"))) eol) "\\1" object-path)))
+    (rx bos (* nonl) "/" (group (+ (not "/"))) eos) "\\1" object-path)))
 
 (defun tramp-gvfs-url-host (url)
   "Return the host name part of URL, a string.
 We cannot use `url-host', because `url-generic-parse-url' returns
 a downcased host name only."
   (and (stringp url)
-       (string-match (rx bol (+ alnum) "://" (group (+ (not (any "/:"))))) url)
+       (string-match (rx bos (+ alnum) "://" (group (+ (not (any "/:"))))) url)
        (match-string 1 url)))
 
 ;; This is used in GNU ELPA package tramp-locproc.el.
@@ -1934,7 +1934,7 @@ Their full names are \"org.gtk.vfs.MountTracker.mounte
 		   (cadr (assoc "ssl" (cadr mount-spec)))))
 	     (uri (tramp-gvfs-dbus-byte-array-to-string
 		   (cadr (assoc "uri" (cadr mount-spec))))))
-	(when (string-match (rx bol (group (| "afp" "smb"))) method)
+	(when (string-match (rx bos (group (| "afp" "smb"))) method)
 	  (setq method (match-string 1 method)))
 	(when (and (string-equal "dav" method) (string-equal "true" ssl))
 	  (setq method "davs"))
@@ -2034,7 +2034,7 @@ Their full names are \"org.gtk.vfs.MountTracker.mounte
 		      (or
 		       (cadr (assoc "share" (cadr mount-spec)))
 		       (cadr (assoc "volume" (cadr mount-spec)))))))
-	 (when (string-match (rx bol (group (| "afp" "smb"))) method)
+	 (when (string-match (rx bos (group (| "afp" "smb"))) method)
 	   (setq method (match-string 1 method)))
 	 (when (and (string-equal "dav" method) (string-equal "true" ssl))
 	   (setq method "davs"))
@@ -2067,7 +2067,7 @@ Their full names are \"org.gtk.vfs.MountTracker.mounte
 		(string-equal host (tramp-file-name-host vec))
 		(string-equal port (tramp-file-name-port vec))
 		(string-match-p
-		 (rx bol "/" (literal (or share "")))
+		 (rx bos "/" (literal (or share "")))
 		 (tramp-file-name-unquote-localname vec)))
 	   ;; Set mountpoint and location.
 	   (tramp-set-file-property vec "/" "fuse-mountpoint" fuse-mountpoint)
@@ -2093,7 +2093,7 @@ It was \"a(say)\", but has changed to \"a{sv})\"."
 (defun tramp-gvfs-mount-spec-entry (key value)
   "Construct a mount-spec entry to be used in a mount_spec.
 It was \"a(say)\", but has changed to \"a{sv})\"."
-  (if (string-match-p (rx bol "(aya{sv})") tramp-gvfs-mountlocation-signature)
+  (if (string-match-p (rx bos "(aya{sv})") tramp-gvfs-mountlocation-signature)
       (list :dict-entry key
 	    (list :variant (tramp-gvfs-dbus-string-to-byte-array value)))
     (list :struct key (tramp-gvfs-dbus-string-to-byte-array value))))
@@ -2112,9 +2112,9 @@ It was \"a(say)\", but has changed to \"a{sv})\"."
 		   (tramp-media-device-port media) (tramp-file-name-port vec)))
 	 (localname (tramp-file-name-unquote-localname vec))
 	 (share (when (string-match
-		       (rx bol (? "/") (group (+ (not "/")))) localname)
+		       (rx bos (? "/") (group (+ (not "/")))) localname)
 		  (match-string 1 localname)))
-	 (ssl (if (string-match-p (rx bol (| "davs" "nextcloud")) method)
+	 (ssl (if (string-match-p (rx bos (| "davs" "nextcloud")) method)
 		  "true" "false"))
 	 (mount-spec
           `(:array
@@ -2123,7 +2123,7 @@ It was \"a(say)\", but has changed to \"a{sv})\"."
                 (list (tramp-gvfs-mount-spec-entry "type" "smb-share")
                       (tramp-gvfs-mount-spec-entry "server" host)
                       (tramp-gvfs-mount-spec-entry "share" share)))
-               ((string-match-p (rx bol (| "davs" "nextcloud")) method)
+               ((string-match-p (rx bos (| "davs" "nextcloud")) method)
                 (list (tramp-gvfs-mount-spec-entry "type" "dav")
                       (tramp-gvfs-mount-spec-entry "host" host)
                       (tramp-gvfs-mount-spec-entry "ssl" ssl)))
@@ -2137,7 +2137,7 @@ It was \"a(say)\", but has changed to \"a{sv})\"."
                ((string-equal "nextcloud" method)
                 (list (tramp-gvfs-mount-spec-entry "type" "owncloud")
                       (tramp-gvfs-mount-spec-entry "host" host)))
-               ((string-match-p (rx bol "http") method)
+               ((string-match-p (rx bos "http") method)
                 (list (tramp-gvfs-mount-spec-entry "type" "http")
                       (tramp-gvfs-mount-spec-entry
 		       "uri"
@@ -2154,8 +2154,8 @@ It was \"a(say)\", but has changed to \"a{sv})\"."
             ,@(when port
                 (list (tramp-gvfs-mount-spec-entry "port" port)))))
 	 (mount-pref
-          (if (and (string-match-p (rx bol "dav") method)
-                   (string-match (rx bol (? "/") (+ (not "/"))) localname))
+          (if (and (string-match-p (rx bos "dav") method)
+                   (string-match (rx bos (? "/") (+ (not "/"))) localname))
               (match-string 0 localname)
 	    (tramp-gvfs-get-remote-prefix vec))))
 
