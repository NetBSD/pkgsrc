$NetBSD: patch-lisp_net_tramp-sh.el,v 1.1 2014/07/02 09:08:36 taca Exp $

Fix for CVE-2014-3424.

--- lisp/net/tramp-sh.el.orig	2013-02-18 19:49:26.000000000 +0000
+++ lisp/net/tramp-sh.el
@@ -605,9 +605,9 @@ This list is used for copying/renaming w
 See `tramp-actions-before-shell' for more info.")
 
 (defconst tramp-uudecode
-  "(echo begin 600 /tmp/tramp.$$; tail +2) | uudecode
-cat /tmp/tramp.$$
-rm -f /tmp/tramp.$$"
+  "(echo begin 600 %t; tail -n +2) | uudecode
+cat %t
+rm -f %t"
   "Shell function to implement `uudecode' to standard output.
 Many systems support `uudecode -o /dev/stdout' or `uudecode -o -'
 for this or `uudecode -p', but some systems don't, and for them
@@ -3938,7 +3938,7 @@ Each item is a list that looks like this
 
 \(FORMAT ENCODING DECODING [TEST]\)
 
-FORMAT is  symbol describing the encoding/decoding format.  It can be
+FORMAT is a symbol describing the encoding/decoding format.  It can be
 `b64' for base64 encoding, `uu' for uu encoding, or `pack' for simple packing.
 
 ENCODING and DECODING can be strings, giving commands, or symbols,
@@ -3948,9 +3948,11 @@ filename will be put into the command li
 specifier is not present, the input should be read from standard
 input.
 
-If they are variables, this variable is a string containing a Perl
-implementation for this functionality.  This Perl program will be transferred
-to the remote host, and it is available as shell function with the same name.
+If they are variables, this variable is a string containing a
+Perl or Shell implementation for this functionality.  This
+program will be transferred to the remote host, and it is
+available as shell function with the same name.  A \"%t\" format
+specifier in the variable value denotes a temporary file.
 
 The optional TEST command can be used for further tests, whether
 ENCODING and DECODING are applicable.")
@@ -4025,10 +4027,25 @@ Goes through the list `tramp-local-codin
 		    (throw 'wont-work-remote nil))
 
 		  (when (not (stringp rem-dec))
-		    (let ((name (symbol-name rem-dec)))
+		    (let ((name (symbol-name rem-dec))
+			  (value (symbol-value rem-dec))
+			  tmpfile)
 		      (while (string-match (regexp-quote "-") name)
 			(setq name (replace-match "_" nil t name)))
-		      (tramp-maybe-send-script vec (symbol-value rem-dec) name)
+		      (when (string-match "%t" value)
+			(setq tmpfile
+			      (make-temp-name
+			       (expand-file-name
+				tramp-temp-name-prefix
+				(tramp-get-remote-tmpdir vec)))
+			      value
+			      (format-spec
+			       value
+			       (format-spec-make
+				?t
+				(tramp-file-name-handler
+				 'file-remote-p tmpfile 'localname)))))
+		      (tramp-maybe-send-script vec value name)
 		      (setq rem-dec name)))
 		  (tramp-message
 		   vec 5
