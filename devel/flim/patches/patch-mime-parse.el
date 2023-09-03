$NetBSD: patch-mime-parse.el,v 1.2 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mime-parse.el	2023-09-02 12:45:03.684120507 +0900
+++ ./mime-parse.el	2023-08-31 08:29:38.610505135 +0900
@@ -1,4 +1,4 @@
-;;; mime-parse.el --- MIME message parser
+;;; mime-parse.el --- MIME message parser  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1994,95,96,97,98,99,2001 Free Software Foundation, Inc.
 
@@ -25,9 +25,13 @@
 
 ;;; Code:
 
-(require 'mime-def)
+(require 'pccl)
+(require 'broken)
+
 (require 'luna)
+(require 'mime-def)
 (require 'std11)
+(require 'mime)
 
 (autoload 'mime-entity-body-buffer "mime")
 (autoload 'mime-entity-body-start-point "mime")
@@ -37,6 +41,132 @@
 ;;; @ lexical analyzer
 ;;;
 
+(unless-broken ccl-usable
+(define-ccl-program mime-default-ccl-lexical-analyzer
+  ;; r0 input
+  ;; r1 flag means any character exists.
+  ;; r2 in parse flag
+  ;;    1 atom, 2 spaces 3 comment (no output) 4 encloser 5 error
+  ;; r3 comment depth
+  (eval-when-compile
+    (let* ((wrt `(if (r0 == ?\") (write "\\\"")
+		   (if (r0 == ?\\) (write "\\\\")
+		     (write r0))))
+	   (atm `((branch r2
+			  ((r2 = 1)
+			   (write "(mime-token . \"")
+			   (write-read-repeat r0))
+			  (write-read-repeat r0)
+			  ((r2 = 1)
+			   (write "(mime-token . \"")
+			   (write-read-repeat r0)))))
+	   (ts  `((if (r2 == 1) ((write "\")") (r2 = 0)))
+		  (write "(tspecials . \"")
+		  ,wrt
+		  (write "\")")
+		  (read r0)
+		  (repeat)))
+	   (sp  `((branch r2
+			  ((r2 = 2)
+			   (read r0)
+			   (repeat))
+			  ((write "\")")
+			   (r2 = 2)
+			   (read r0)
+			   (repeat))
+			  ((read r0) (repeat)))))
+	   (err `((branch r2
+			  ((write "(error . \""))
+			  ((write "\")")
+			   (write "(error . \""))
+			  ((write "(error . \"")))
+		  (r2 = 5)
+		  (loop
+		   (write-read-repeat r0))))
+	   (enc (lambda (name tag)
+		  `((if (r2 == 1) ((write "\")")))
+		    (write ,(concat "(" name " . \""))
+		    (r2 = 4)
+		    (loop
+		     (read-branch
+		      r0
+		      ,@(let* ((count (1+ (max tag ?\\)))
+			       (result (make-vector count '(write-repeat r0))))
+			  (aset result ?\\ `((write "\\\\")
+					     (read r0)
+					     ,wrt
+					     (repeat)))
+			  (aset result ?\" '((write "\\\"") (repeat)))
+			  (aset result tag '(break))
+			  (mapcar 'identity result)))
+		     (write-repeat r0))
+		    (write "\")")
+		    (r2 = 0)
+		    (read r0)
+		    (repeat))))
+	   (qs (funcall enc "quoted-string" ?\"))
+	   (dl (funcall enc "domain-literal" ?\]))
+	   (cm  `((if (r2 == 1) ((write "\")")))
+		  (r2 = 3)
+		  (r3 = 1)
+		  (loop
+		   (read-branch
+		    r0
+		    ,@(let* ((count (1+ (max ?\( ?\) ?\\)))
+			     (result (make-vector count '(repeat))))
+			(aset result ?\( '((r3 += 1) (repeat)))
+			(aset result ?\) '((r3 -= 1)
+					   (if (r3 < 1) (break)
+					     (repeat))))
+			(aset result ?\\ `((read r0) (repeat)))
+			(mapcar 'identity result)))
+		   (repeat))
+		  (r2 = 0)
+		  (read r0)
+		  (repeat))))
+      `(8
+	((r2 = 0)
+	 (read r0)
+	 (r1 = 1)
+	 (write "((")
+	 (loop
+	  (branch r0
+		  ,@(mapcar (lambda (elt) (eval elt))
+			    '(err err err err err err err err
+				  err sp  sp  err err err err err
+				  err err err err err err err err
+				  err err err err err err err err
+				  sp  atm qs  atm atm atm atm atm
+				  cm  ts  atm atm ts  atm atm ts 
+				  atm atm atm atm atm atm atm atm
+				  atm atm ts  ts  ts  ts  ts  ts
+				  ts  atm atm atm atm atm atm atm
+				  atm atm atm atm atm atm atm atm
+				  atm atm atm atm atm atm atm atm
+				  atm atm atm dl  ts  ts)))
+	  ,@atm))
+	((branch r1
+		 (write "(nil . t)")
+		 (branch r2
+			 (write ") . t)")
+			 (write "\")) . t)")
+			 (write ") . t)")
+			 (write "))")
+			 (write "\")))")
+			 (write "\")) . t)")))))))))
+
+(defcustom mime-ccl-lexical-analyzer
+  (static-unless (or (broken-p 'ccl-usable)
+		     (broken-p 'ccl-execute-eof-block))
+    'mime-default-ccl-lexical-analyzer)
+  "Specify CCL-program symbol for `mime-lexical-analyze'.
+When nil, do not use CCL.
+See docstring of `std11-ccl-lexical-analyzer' for details of CCL-program.
+If you modify `mime-lexical-analyzer', set this variable to nil
+or prepare corresponding CCL-program."
+  :group 'mime
+  :type '(choice symbol (const :tag "Do not use CCL." nil)))
+
 (defcustom mime-lexical-analyzer
   '(std11-analyze-quoted-string
     std11-analyze-domain-literal
@@ -70,22 +200,27 @@
 
 (defun mime-lexical-analyze (string)
   "Analyze STRING as lexical tokens of MIME."
-  (let ((ret (std11-lexical-analyze string mime-lexical-analyzer))
-        prev tail)
-    ;; skip leading linear-white-space.
-    (while (memq (car (car ret)) '(spaces comment))
-      (setq ret (cdr ret)))
-    (setq prev ret
-          tail (cdr ret))
-    ;; remove linear-white-space.
-    (while tail
-      (if (memq (car (car tail)) '(spaces comment))
-          (progn
-            (setcdr prev (cdr tail))
-            (setq tail (cdr tail)))
-        (setq prev (cdr prev)
-              tail (cdr tail))))
-    ret))
+  (let (ret prev tail)
+    (if (and mime-ccl-lexical-analyzer
+	     (cdr (setq ret (read (ccl-execute-on-string
+				   mime-ccl-lexical-analyzer
+				   (make-vector 9 0) (or string ""))))))
+	(car ret)
+      (setq ret (std11-lexical-analyze string mime-lexical-analyzer))
+      ;; skip leading linear-white-space.
+      (while (memq (car (car ret)) '(spaces comment))
+	(setq ret (cdr ret)))
+      (setq prev ret
+	    tail (cdr ret))
+      ;; remove linear-white-space.
+      (while tail
+	(if (memq (car (car tail)) '(spaces comment))
+	    (progn
+	      (setcdr prev (cdr tail))
+	      (setq tail (cdr tail)))
+	  (setq prev (cdr prev)
+		tail (cdr tail))))
+      ret)))
 
 
 ;;; @ field parser
@@ -103,11 +238,7 @@
                 (delete-region (point)(- (point) 3)))))
     (setq text (buffer-string))
     (when charset
-      ;; I believe that `decode-mime-charset-string' of mcs-e20.el should
-      ;; be independent of the value of `enable-multibyte-characters'.
-      (erase-buffer)
-      (set-buffer-multibyte t)
-      (setq text (decode-mime-charset-string text charset)))
+      (setq text (mime-charset-decode-string text charset)))
     (when language
       (put-text-property 0 (length text) 'mime-language language text))
     text))
@@ -122,7 +253,7 @@
                                  (concat mime-attribute-char-regexp "+")))
                (goto-char (match-end 0)))
              (not (eobp)))
-      (insert (prog1 (format "%%%02X" (char-int (char-after)))
+      (insert (prog1 (format "%%%02X" (following-char))
                 (delete-region (point)(1+ (point))))))
     (buffer-string)))
 
@@ -237,12 +368,216 @@
 
 ;;; for compatibility with flim-1_13-rfc2231 API.
 (defalias 'mime-parse-parameters-from-list 'mime-decode-parameters)
-(make-obsolete 'mime-parse-parameters-from-list 'mime-decode-parameters)
+(make-obsolete 'mime-parse-parameters-from-list
+	       'mime-decode-parameters "28 Feb 2001")
+
+
+;;; @ parameter value encoder
+;;;
+
+(defun mime-divide-extended-parameter (name value)
+  "Divide MIME parameter value \"NAME=VALUE\" into segments.
+Each of \" NAME*n*=SEGMENT_n\;\" will be no more than 78 characters.
+Return value is a list of string when division is performed, otherwise
+return value is just a string."
+  ;; `limit' must be more than (length "CHARSET'LANGUAGE'%XX").
+  ;;
+  ;; Since MIME spec does not limit either length of CHARSET or length
+  ;; of LANGUAGE, we choose 30 for minimum `limit' based on the longest
+  ;; name of charset that Emacs supports ("ISO-2022-CN-EXT"; 15 chars).
+  ;;
+  ;; Anyway, if `name' is too long, we will ignore 78 chars limit.
+  (let ((limit (max (- 78 4 (length name)) 30))); (length " *=;") => 4
+    (if (> limit (length value))
+	value
+      (let ((count 0)
+	    result)
+	(setq limit (max (- limit 2) 30))	; (length "*n") => 2
+	(with-temp-buffer
+	  (set-buffer-multibyte nil)
+	  (insert value)
+	  (while (> (point-max) limit)
+	    (goto-char (- limit 3))		; (length "%XX") => 3
+	    (cond
+	     ((eq (following-char) ?%)
+	      (forward-char 3))
+	     ((progn
+		(forward-char)
+		(eq (following-char) ?%)))
+	     ((progn
+		(forward-char)
+		(eq (following-char) ?%)))
+	     (t
+	      (forward-char)))
+	    (setq result (cons (prog1 (buffer-substring (point-min)(point))
+				 (delete-region (point-min)(point)))
+			       result)
+		  count (1+ count))
+	    (when (zerop (% count 10))
+	      (setq limit (max (1- limit) 30))))
+	  (nreverse
+	   (cons (buffer-substring (point-min)(point-max))
+		 result)))))))
+
+(defun mime-encode-extended-parameter (name value)
+  "Encode MIME parameter value \"NAME=VALUE\" as an extended-parameter.
+If encoding is unnecessary, return nil.
+If division is performed, return value is a list of string, otherwise
+return value is just a string."
+  (let ((language (get-text-property 0 'mime-language value)))
+    (when (or language
+	      (string-match "[^ -~]" value)) ; Nonmatching printable US-ASCII.
+      (with-temp-buffer
+	(let ((charset (find-mime-charset-by-charsets
+			(find-charset-string value))))
+	  (setq value (mime-charset-encode-string value charset))
+	  (set-buffer-multibyte nil)
+	  (insert value)
+	  (goto-char (point-min))
+	  (insert (symbol-name charset)
+		  ?'
+		  (if language (symbol-name language) "")
+		  ?')
+	  (while (re-search-forward mime-non-attribute-char-regexp nil t)
+	    (insert (prog1 (format "%%%02X" (preceding-char))
+		      (delete-region (1- (point))(point)))))
+	  (mime-divide-extended-parameter name (buffer-string)))))))
+
+(defun mime-divide-regular-parameter (name value)
+  "Divide MIME parameter value \"NAME=VALUE\" into segments.
+Each of \" NAME*n=SEGMENT_n\;\" will be no more than 78 characters.
+Return value is a list of string when division is performed, otherwise
+just a string is returned."
+  (let ((limit (max (- (eval-when-compile (- 78 (length " =\"\";")))
+		       (length name))
+		    30)))
+    (if (> limit (length value))
+	(concat "\"" value "\"")
+      (let ((count 0)
+	    result)
+	(setq limit (max (- limit 2) 30))	; (length "*n") => 2
+	(setq limit (1- limit))			; XXX
+	(with-temp-buffer
+	  (set-buffer-multibyte nil)
+	  (insert value)
+	  (while (> (point-max) limit)
+	    (goto-char (point-min))
+	    (while (< (point) limit)
+	      (when (eq (following-char) ?\\)
+		(forward-char))
+	      (forward-char))
+	    (setq result (cons (concat "\""
+				       (prog1 (buffer-substring
+					       (point-min)(point))
+					 (delete-region
+					  (point-min)(point)))
+				       "\"")
+			       result)
+		  count (1+ count))
+	    (when (zerop (% count 10))
+	      (setq limit (max (1- limit) 30))))
+	  (nreverse
+	   (cons (concat "\""
+			 (buffer-substring (point-min)(point-max))
+			 "\"")
+		 result)))))))
+
+(defun mime-encode-regular-parameter (name value)
+  "Encode MIME parameter value \"NAME=VALUE\" as a regular-parameter.
+If division is performed, return value is a list of string, otherwise
+return value is just a string."
+  (with-temp-buffer
+    (set-buffer-multibyte nil)
+    (insert value)
+    (goto-char (point-min))
+    (while (not (eobp))
+      (when (memq (following-char) '(?\\ ?\"))
+	(insert ?\\))
+      (forward-char 1))
+    (mime-divide-regular-parameter name (buffer-string))))
+
+(defun mime-encode-parameters (params)
+  "Encode PARAMS plist with MIME Parameter-Value Extensions.
+Return value is an alist of MIME parameter values."
+  (let (name value encoded result)
+    (while params
+      (setq name (car params)
+            value (car (cdr params))
+            params (cdr (cdr params)))
+      (cond
+       ;; first two clauses are for backward compatibility,
+       ;; especially for "ftp.in" in the distribution.
+       ((not (string-match (eval-when-compile
+			     (concat "^\\(" mime-attribute-char-regexp "+\\)"
+				     "\\(\\*[0-9]+\\)?" ; continuation
+				     "\\(\\*\\)?$")) ; charset/language
+			   name))
+	;; invalid parameter name.
+	;; XXX: Should we signal an error?
+	)
+       ((> (match-end 0) (match-end 1))
+	;; this parameter value is already encoded.
+	(setq result (cons (cons name
+				 (if (match-beginning 3)
+				     ;; extended-parameter
+				     value
+				   ;; regular-parameter
+				   (std11-wrap-as-quoted-string value)))
+			   result)))
+       ((setq encoded (mime-encode-extended-parameter name value))
+	;; extended-parameter
+	(if (stringp encoded)
+	    (setq result (cons (cons (concat name "*") encoded) result))
+	  ;; with continuation
+	  (let ((section 0))
+	    (while encoded
+	      (setq result (cons (cons (concat name
+					       "*" (int-to-string section)
+					       "*")
+				       (car encoded))
+				 result)
+		    section (1+ section)
+		    encoded(cdr encoded))))))
+       (t
+	;; regular-parameter
+	(setq encoded (mime-encode-regular-parameter name value))
+        (if (stringp encoded)
+            (setq result (cons (cons name encoded) result))
+	  ;; with continuation
+          (let ((section 0))
+            (while encoded
+              (setq result (cons (cons (concat name
+                                               "*" (int-to-string section))
+				       (car encoded))
+				 result)
+		    section (1+ section)
+		    encoded (cdr encoded))))))))
+    (nreverse result)))
+
+(provide 'mime-parse)
+(require 'eword-encode)
+
+(defun mime-encode-parameters-broken-mime (params)
+  "Encode PARAMS plist compatibly with Outlook.
+Return value is an alist of MIME parameter values."
+  (let (result)
+    (while (cadr params)
+      (setq result
+	    `((,(car params)
+	       . ,(eword-encode-string (cadr params)
+				       (+ (length (car params)) 3)))
+	      . ,result)
+	    params (cddr params)))
+    (nreverse result)))
+
+
+;;; @ field parser
+;;;
 
 (defun mime-parse-parameters (tokens)
   "Parse TOKENS as MIME parameter values.
 Return a property list, which is a list of the form
-\(PARAMETER-NAME1 VALUE1 PARAMETER-NAME2 VALUE2...)."
+(PARAMETER-NAME1 VALUE1 PARAMETER-NAME2 VALUE2...)."
   (let (params attribute)
     (while (and tokens
 		(eq (car (car tokens)) 'tspecials)
@@ -294,8 +629,7 @@
 If Content-Type field is not found, return nil."
   (let ((field-body (std11-field-body "Content-Type")))
     (if field-body
-	(mime-parse-Content-Type field-body)
-      )))
+	(mime-parse-Content-Type field-body))))
 
 
 ;;; @@ Content-Disposition
@@ -321,8 +655,7 @@
 If Content-Disposition field is not found, return nil."
   (let ((field-body (std11-field-body "Content-Disposition")))
     (if field-body
-	(mime-parse-Content-Disposition field-body)
-      )))
+	(mime-parse-Content-Disposition field-body))))
 
 
 ;;; @@ Content-Transfer-Encoding
@@ -345,8 +678,7 @@
 If Content-Transfer-Encoding field is not found, return nil."
   (let ((field-body (std11-field-body "Content-Transfer-Encoding")))
     (if field-body
-	(mime-parse-Content-Transfer-Encoding field-body)
-      )))
+	(mime-parse-Content-Transfer-Encoding field-body))))
 
 
 ;;; @@ Content-ID / Message-ID
@@ -360,10 +692,13 @@
 ;;;###autoload
 (defun mime-uri-parse-cid (string)
   "Parse STRING as cid URI."
-  (mime-parse-msg-id (cons '(specials . "<")
-			   (nconc
-			    (cdr (cdr (std11-lexical-analyze string)))
-			    '((specials . ">"))))))
+  (when (string-match "^cid:" string)
+    (setq string (concat "<" (substring string 4) ">"))
+    (let ((parser (cdr (assq 'Content-Id mime-field-parser-alist))))
+      (if parser
+	  (funcall parser (eword-lexical-analyze string))
+	(mime-decode-field-body string 'Content-Id 'plain)))))
+
 
 
 ;;; @ message parser
@@ -470,12 +805,8 @@
 	    body-start (point-min)))
     (save-restriction
       (narrow-to-region header-start header-end)
-      (setq content-type (or (let ((str (std11-fetch-field "Content-Type")))
-			       (if str
-				   (mime-parse-Content-Type str)
-				 ))
-			     default-ctl))
-      )
+      (setq content-type (or (mime-read-Content-Type)
+			     default-ctl)))
     (luna-make-entity representation-type
 		      :location (current-buffer)
 		      :content-type content-type
@@ -485,8 +816,7 @@
 		      :header-start header-start
 		      :header-end header-end
 		      :body-start body-start
-		      :body-end body-end)
-    ))
+		      :body-end body-end)))
 
 
 ;;; @ for buffer
