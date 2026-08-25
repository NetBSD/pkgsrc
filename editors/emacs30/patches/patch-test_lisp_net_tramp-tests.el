$NetBSD: patch-test_lisp_net_tramp-tests.el,v 1.1 2026/08/25 17:44:23 wiz Exp $

CVE-2026-79992: Fix local command execution vulnerability in tramp
https://gitweb.gentoo.org/proj/emacs-patches.git/commit/emacs/30.2/05_all_tramp.patch?id=2a6292f81affedcc468c594c60808e652ae87118

--- test/lisp/net/tramp-tests.el.orig	2025-05-17 10:45:04.000000000 +0000
+++ test/lisp/net/tramp-tests.el
@@ -325,6 +325,7 @@ is greater than 10.
 	  (should (tramp-tramp-file-p "/method:user@:"))
 	  (should (tramp-tramp-file-p "/method:user@host:"))
 	  (should (tramp-tramp-file-p "/method:user@email@host:"))
+	  (should (tramp-tramp-file-p "/method:$USER@host:"))
 
 	  ;; Using a port.
 	  (should (tramp-tramp-file-p "/method:host#1234:"))
@@ -421,6 +422,7 @@ is greater than 10.
 	  (should (tramp-tramp-file-p "/user@:"))
 	  (should (tramp-tramp-file-p "/user@host:"))
 	  (should (tramp-tramp-file-p "/user@email@host:"))
+	  (should (tramp-tramp-file-p "/$USER@host:"))
 
 	  ;; Using a port.
 	  (should (tramp-tramp-file-p "/host#1234:"))
@@ -483,6 +485,7 @@ is greater than 10.
 	  (should (tramp-tramp-file-p "/[method/user@]"))
 	  (should (tramp-tramp-file-p "/[method/user@host]"))
 	  (should (tramp-tramp-file-p "/[method/user@email@host]"))
+	  (should (tramp-tramp-file-p "/[method/$USER@host]"))
 
 	  ;; Using a port.
 	  (should (tramp-tramp-file-p "/[method/host#1234]"))
@@ -671,6 +674,28 @@ is greater than 10.
 	  (should (string-equal
 		   (file-remote-p "/method:user@email@host:" 'hop) nil))
 
+	  ;; Expand environment variable.  It can be cascaded.
+	  (with-environment-variables
+	      (("REMOTE_USER" "$REMOTE_USER1") ("REMOTE_USER1" "remote-user"))
+	    (should (string-equal
+		     (file-remote-p "/method:$REMOTE_USER@host:")
+		     (format "/%s:%s@%s:" "method" "remote-user" "host")))
+	    (should
+	     (string-equal
+	      (file-remote-p "/method:$REMOTE_USER@host:" 'method) "method"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/method:$REMOTE_USER@host:" 'user) "remote-user"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/method:$REMOTE_USER@host:" 'host) "host"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/method:$REMOTE_USER@host:" 'localname) ""))
+	    (should
+	     (string-equal
+	      (file-remote-p "/method:$REMOTE_USER@host:" 'hop) nil)))
+
 	  ;; Expand `tramp-default-method' and `tramp-default-user'.
 	  (should
 	   (string-equal
@@ -1151,6 +1176,28 @@ is greater than 10.
 	  (should (string-equal
 		   (file-remote-p "/user@email@host:" 'hop) nil))
 
+	  ;; Expand environment variable.  It can be cascaded.
+	  (with-environment-variables
+	      (("REMOTE_USER" "$REMOTE_USER1") ("REMOTE_USER1" "remote-user"))
+	    (should (string-equal
+		     (file-remote-p "/$REMOTE_USER@host:")
+		     (format "/%s@%s:" "remote-user" "host")))
+	    (should
+	     (string-equal
+	      (file-remote-p "/$REMOTE_USER@host:" 'method) "default-method"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/$REMOTE_USER@host:" 'user) "remote-user"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/$REMOTE_USER@host:" 'host) "host"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/$REMOTE_USER@host:" 'localname) ""))
+	    (should
+	     (string-equal
+	      (file-remote-p "/$REMOTE_USER@host:" 'hop) nil)))
+
 	  ;; Expand `tramp-default-method' and `tramp-default-user'.
 	  (should (string-equal
 		   (file-remote-p "/host#1234:")
@@ -1616,6 +1663,28 @@ is greater than 10.
 		   (file-remote-p "/[method/user@email@host]" 'localname) ""))
 	  (should (string-equal
 		   (file-remote-p "/[method/user@email@host]" 'hop) nil))
+
+	  ;; Expand environment variable.  It can be cascaded.
+	  (with-environment-variables
+	      (("REMOTE_USER" "$REMOTE_USER1") ("REMOTE_USER1" "remote-user"))
+	    (should (string-equal
+		     (file-remote-p "/[method/$REMOTE_USER@host]")
+		     (format "/[%s/%s@%s]" "method" "remote-user" "host")))
+	    (should
+	     (string-equal
+	      (file-remote-p "/[method/$REMOTE_USER@host]" 'method) "method"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/[method/$REMOTE_USER@host]" 'user) "remote-user"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/[method/$REMOTE_USER@host]" 'host) "host"))
+	    (should
+	     (string-equal
+	      (file-remote-p "/[method/$REMOTE_USER@host]" 'localname) ""))
+	    (should
+	     (string-equal
+	      (file-remote-p "/[method/$REMOTE_USER@host]" 'hop) nil)))
 
 	  ;; Expand `tramp-default-method' and `tramp-default-user'.
 	  (should (string-equal
