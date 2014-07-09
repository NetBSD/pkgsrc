$NetBSD$

Fix for CVE-2014-3424.

--- lisp/net/tramp.el.orig	2012-01-11 12:35:01.000000000 +0000
+++ lisp/net/tramp.el
@@ -1687,9 +1687,9 @@ means to use always cached values for th
   "Remote host for this *tramp* buffer.")
 
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
@@ -7173,7 +7173,7 @@ Each item is a list that looks like this
 
 \(FORMAT ENCODING DECODING\)
 
-FORMAT is  symbol describing the encoding/decoding format.  It can be
+FORMAT is a symbol describing the encoding/decoding format.  It can be
 `b64' for base64 encoding, `uu' for uu encoding, or `pack' for simple packing.
 
 ENCODING and DECODING can be strings, giving commands, or symbols,
@@ -7220,9 +7220,11 @@ filename will be put into the command li
 specifier is not present, the input should be read from standard
 input.
 
-If they are variables, this variable is a string containing a Perl
-implementation for this functionality.  This Perl program will be transferred
-to the remote host, and it is available as shell function with the same name.")
+If they are variables, this variable is a string containing a
+Perl or Shell implementation for this functionality.  This
+program will be transferred to the remote host, and it is
+available as shell function with the same name.  A \"%t\" format
+specifier in the variable value denotes a temporary file.
 
 (defun tramp-find-inline-encoding (vec)
   "Find an inline transfer encoding that works.
@@ -7286,10 +7288,25 @@ Goes through the list `tramp-local-codin
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
