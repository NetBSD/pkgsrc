$NetBSD: patch-eword-encode.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/eword-encode.el	2007-09-06 16:48:50.000000000 +0900
+++ ./eword-encode.el	2023-08-31 08:29:38.589006246 +0900
@@ -1,4 +1,4 @@
-;;; eword-encode.el --- RFC 2047 based encoded-word encoder for GNU Emacs
+;;; eword-encode.el --- RFC 2047 based encoded-word encoder for GNU Emacs  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1995,1996,1997,1998,1999,2000,2002,2003,2004 Free
 ;;   Software Foundation, Inc.
@@ -30,7 +30,6 @@
 (require 'std11)
 (require 'eword-decode)
 
-
 ;;; @ variables
 ;;;
 
@@ -59,8 +58,7 @@
     (tis-620		. "B")
     (iso-2022-jp-2	. "B")
     (iso-2022-int-1	. "B")
-    (utf-8		. "B")
-    ))
+    (utf-8		. "B")))
 
 (defvar mime-header-default-charset-encoding "Q")
 
@@ -74,6 +72,8 @@
 	Dcc))
     (eword-encode-in-reply-to . (In-Reply-To))
     (eword-encode-structured-field-body . (Mime-Version User-Agent))
+    (eword-encode-Content-Disposition-field-body . (Content-Disposition))
+    (eword-encode-Content-Type-field-body . (Content-Type))
     (eword-encode-unstructured-field-body)))
 
 ;;; @ encoded-text encoder
@@ -88,126 +88,64 @@
   (let ((text (encoded-text-encode-string string encoding mode)))
     (if text
 	(concat "=?" (upcase (symbol-name charset)) "?"
-		encoding "?" text "?=")
-      )))
+		encoding "?" text "?="))))
 
 
 ;;; @ charset word
 ;;;
 
-(defsubst eword-encode-char-type (character)
-  (if (memq character '(?  ?\t ?\n))
-      nil
-    (char-charset character)
-    ))
-
-(defun eword-encode-divide-into-charset-words (string)
-  (let ((len (length string))
-	dest)
-    (while (> len 0)
-      (let* ((chr (aref string 0))
-             ;; (chr (sref string 0))
-	     (charset (eword-encode-char-type chr))
-             (i 1)
-	     ;; (i (char-length chr))
-	     )
-	(while (and (< i len)
-		    (setq chr (aref string i))
-                    ;; (setq chr (sref string i))
-		    (eq charset (eword-encode-char-type chr)))
-	  (setq i (1+ i))
-          ;; (setq i (char-next-index chr i))
-	  )
-	(setq dest (cons (cons charset (substring string 0 i)) dest)
-	      string (substring string i)
-	      len (- len i))))
-    (nreverse dest)))
-
 
 ;;; @ word
 ;;;
 
-(defun eword-encode-charset-words-to-words (charset-words)
-  (let (dest)
-    (while charset-words
-      (let* ((charset-word (car charset-words))
-	     (charset (car charset-word))
-	     )
-	(if charset
-	    (let ((charsets (list charset))
-		  (str (cdr charset-word))
-		  )
-	      (catch 'tag
-		(while (setq charset-words (cdr charset-words))
-		  (setq charset-word (car charset-words)
-			charset (car charset-word))
-		  (if (null charset)
-		      (throw 'tag nil)
-		    )
-		  (or (memq charset charsets)
-		      (setq charsets (cons charset charsets))
-		      )
-		  (setq str (concat str (cdr charset-word)))
-		  ))
-	      (setq dest (cons (cons charsets str) dest))
-	      )
-	  (setq dest (cons charset-word dest)
-		charset-words (cdr charset-words)
-		))))
-    (nreverse dest)
-    ))
-
 
 ;;; @ rule
 ;;;
 
 (defmacro make-ew-rword (text charset encoding type)
-  (` (list (, text)(, charset)(, encoding)(, type))))
+  `(list ,text ,charset ,encoding ,type))
 (defmacro ew-rword-text (rword)
-  (` (car (, rword))))
+  `(car ,rword))
 (defmacro ew-rword-charset (rword)
-  (` (car (cdr (, rword)))))
+  `(car (cdr ,rword)))
 (defmacro ew-rword-encoding (rword)
-  (` (car (cdr (cdr (, rword))))))
+  `(car (cdr (cdr ,rword))))
 (defmacro ew-rword-type (rword)
-  (` (car (cdr (cdr (cdr (, rword)))))))
+  `(car (cdr (cdr (cdr ,rword)))))
+
+(defun ew-find-string-rule (string)
+  (let ((charset (detect-mime-charset-string string)))
+    (list charset
+	  (cdr (or (assq charset mime-header-charset-encoding-alist)
+		   (cons nil mime-header-default-charset-encoding))))))
 
-(defun ew-find-charset-rule (charsets)
-  (if charsets
-      (let* ((charset (find-mime-charset-by-charsets charsets))
-	     (encoding
-	      (cdr (or (assq charset mime-header-charset-encoding-alist)
-		       (cons charset mime-header-default-charset-encoding)))))
-	(list charset encoding))))
-
-;; [tomo:2002-11-05] The following code is a quick-fix for emacsen
-;; which is not depended on the Mule model.  We should redesign
-;; `eword-encode-split-string' to avoid to depend on the Mule model.
-(if (featurep 'utf-2000)
-;; for CHISE Architecture
-(defun tm-eword::words-to-ruled-words (wl &optional mode)
-  (let (mcs)
-    (mapcar (function
-	     (lambda (word)
-	       (setq mcs (detect-mime-charset-string (cdr word)))
-	       (make-ew-rword
-		(cdr word)
-		mcs
-		(cdr (or (assq mcs mime-header-charset-encoding-alist)
-			 (cons mcs mime-header-default-charset-encoding)))
-		mode)
-	       ))
-	    wl)))
-
-;; for legacy Mule
-(defun tm-eword::words-to-ruled-words (wl &optional mode)
-  (mapcar (function
-	   (lambda (word)
-	     (let ((ret (ew-find-charset-rule (car word))))
-	       (make-ew-rword (cdr word) (car ret)(nth 1 ret) mode)
-	       )))
-	  wl))
-)
+(defun tm-eword::string-to-ruled-words (string &optional mode)
+  (let ((len (length string))
+	(beg 0)
+	(i 1)
+	spacep dest mcs)
+    (when (> len 0)
+      (mapcar
+       (lambda (elt)
+	 (if (cdr elt)
+	     (make-ew-rword (car elt) nil nil mode)
+	   (setq mcs (detect-mime-charset-string (car elt)))
+	   (make-ew-rword
+	    (car elt)
+	    mcs
+	    (cdr (or (assq mcs mime-header-charset-encoding-alist)
+		     (cons nil mime-header-default-charset-encoding)))
+	    mode)))
+       (progn
+	 (setq spacep (memq (aref string 0) '(?\s ?\t ?\n)))
+	 (while (< i len)
+	   (unless (eq spacep (memq (aref string i) '(?\s ?\t ?\n)))
+	     (setq dest (cons (cons (substring string beg i) spacep) dest))
+	     (setq beg i)
+	     (setq spacep (null spacep)))
+	   (setq i (1+ i)))
+	 (nreverse
+	  (cons (cons (substring string beg len) spacep) dest)))))))
 
 (defun ew-space-process (seq)
   (let (prev a ac b c cc)
@@ -227,30 +165,19 @@
 		       (setq prev (cons
 				   (cons (concat (car a)(car b)(car c))
 					 (cdr a))
-				   (cdr prev)
-				   ))
-		       (setq seq (cdr seq))
-		       )
+				   (cdr prev)))
+		       (setq seq (cdr seq)))
 		      (t
 		       (setq prev (cons
 				   (cons (concat (car a)(car b))
 					 (cdr a))
-				   (cdr prev)
-				   ))
-		       ))
-	      (setq prev (cons b prev))
-	      ))
-	(setq prev (cons b prev))
-	))
-    (reverse prev)
-    ))
+				   (cdr prev)))))
+	      (setq prev (cons b prev))))
+	(setq prev (cons b prev))))
+    (reverse prev)))
 
 (defun eword-encode-split-string (str &optional mode)
-  (ew-space-process
-   (tm-eword::words-to-ruled-words
-    (eword-encode-charset-words-to-words
-     (eword-encode-divide-into-charset-words str))
-    mode)))
+  (ew-space-process (tm-eword::string-to-ruled-words str mode)))
 
 
 ;;; @ length
@@ -263,16 +190,13 @@
 	ret)
     (setq ret
 	  (cond ((string-equal encoding "B")
-		 (setq string (encode-mime-charset-string string charset))
-		 (base64-encoded-length string)
-		 )
+		 (setq string (mime-charset-encode-string string charset))
+		 (base64-encoded-length string))
 		((string-equal encoding "Q")
-		 (setq string (encode-mime-charset-string string charset))
-		 (Q-encoded-text-length string (ew-rword-type rword))
-		 )))
+		 (setq string (mime-charset-encode-string string charset))
+		 (Q-encoded-text-length string (ew-rword-type rword)))))
     (if ret
-	(cons (+ 7 (length (symbol-name charset)) ret) string)
-      )))
+	(cons (+ 7 (length (symbol-name charset)) ret) string))))
 
 
 ;;; @ encode-string
@@ -286,35 +210,27 @@
       (if (null ret)
 	  (cond ((and (setq string (car rword))
 		      (or (<= (setq len (+ (length string) column)) 76)
-			  (<= column 1))
-		      )
-		 (setq rwl (cdr rwl))
-		 )
-		((memq (aref string 0) '(?  ?\t))
+			  (<= column 1)))
+		 (setq rwl (cdr rwl)))
+		((memq (aref string 0) '(?\s ?\t))
 		 (setq string (concat "\n" string)
 		       len (length string)
-		       rwl (cdr rwl))
-		 )
+		       rwl (cdr rwl)))
 		(must-output
 		 (setq string "\n "
-		       len 1)
-		 )
+		       len 1))
 		(t
-		 (throw 'can-not-output nil)
-		 ))
+		 (throw 'can-not-output nil)))
 	(cond ((and (setq len (car ret))
-		    (<= (+ column len) 76)
-		    )
+		    (<= (+ column len) 76))
 	       (setq string
 		     (eword-encode-text
 		      (ew-rword-charset rword)
 		      (ew-rword-encoding rword)
 		      (cdr ret)
-		      (ew-rword-type rword)
-		      ))
+		      (ew-rword-type rword)))
 	       (setq len (+ (length string) column))
-	       (setq rwl (cdr rwl))
-	       )
+	       (setq rwl (cdr rwl)))
 	      (t
 	       (setq string (car rword))
 	       (let* ((p 0) np
@@ -325,12 +241,10 @@
 			       ;;(setq np (char-next-index (sref string p) p))
 			       (setq nstr (substring string 0 np))
 			       (setq ret (tm-eword::encoded-word-length
-					  (cons nstr (cdr rword))
-					  ))
+					  (cons nstr (cdr rword))))
 			       (setq nstr (cdr ret))
 			       (setq len (+ (car ret) column))
-			       (<= len 76)
-			       ))
+			       (<= len 76)))
 		   (setq str nstr
 			 p np))
 		 (if (string-equal str "")
@@ -346,12 +260,8 @@
 			  (ew-rword-encoding rword)
 			  str
 			  (ew-rword-type rword)))
-		   (setq len (+ (length string) column))
-		   )
-		 )))
-	)
-      (list string len rwl)
-      )))
+		   (setq len (+ (length string) column)))))))
+      (list string len rwl))))
 
 (defun eword-encode-rword-list (column rwl)
   (let (ret dest str ew-f pew-f folded-points)
@@ -360,23 +270,20 @@
       (if (and pew-f ew-f)
 	  (setq rwl (cons '(" ") rwl)
 		pew-f nil)
-	(setq pew-f ew-f)
-	)
+	(setq pew-f ew-f))
       (if (null (setq ret (ew-encode-rword-1 column rwl)))
 	  (let ((i (1- (length dest)))
 		c s r-dest r-column)
 	    (catch 'success
 	      (while (catch 'found
 		       (while (>= i 0)
-			 (cond ((memq (setq c (aref dest i)) '(?  ?\t))
+			 (cond ((memq (setq c (aref dest i)) '(?\s ?\t))
 				(if (memq i folded-points)
 				    (throw 'found nil)
 				  (setq folded-points (cons i folded-points))
-				  (throw 'found i))
-				)
+				  (throw 'found i)))
 			       ((eq c ?\n)
-				(throw 'found nil)
-				))
+				(throw 'found nil)))
 			 (setq i (1- i))))
 		(setq s (substring dest i)
 		      r-column (length s)
@@ -384,17 +291,13 @@
 		(when (setq ret (ew-encode-rword-1 r-column rwl))
 		  (setq dest r-dest
 			column r-column)
-		  (throw 'success t)
-		  ))
-	      (setq ret (ew-encode-rword-1 column rwl 'must-output))
-	      )))
+		  (throw 'success t)))
+	      (setq ret (ew-encode-rword-1 column rwl 'must-output)))))
       (setq str (car ret))
       (setq dest (concat dest str))
       (setq column (nth 1 ret)
-	    rwl (nth 2 ret))
-      )
-    (list dest column)
-    ))
+	    rwl (nth 2 ret)))
+    (list dest column)))
 
 
 ;;; @ converter
@@ -410,65 +313,44 @@
 	     (setq dest
 		   (append dest
 			   (list
-			    (let ((ret (ew-find-charset-rule
-					(find-charset-string str))))
+			    (let ((ret (ew-find-string-rule str)))
 			      (make-ew-rword
-			       str (car ret)(nth 1 ret) 'phrase)
-			      )
-			    )))
-	     )
+			       str (car ret)(nth 1 ret) 'phrase))))))
 	    ((eq type 'comment)
 	     (setq dest
 		   (append dest
 			   '(("(" nil nil special))
-			   (tm-eword::words-to-ruled-words
-			    (eword-encode-charset-words-to-words
-			     (eword-encode-divide-into-charset-words
-			      (cdr token)))
-			    'comment)
-			   '((")" nil nil special))
-			   ))
-	     )
+			   (tm-eword::string-to-ruled-words
+			    (cdr token) 'comment)
+			   '((")" nil nil special)))))
 	    (t
 	     (setq dest
 		   (append dest
-			   (tm-eword::words-to-ruled-words
-			    (eword-encode-charset-words-to-words
-			     (eword-encode-divide-into-charset-words
-			      (cdr token))
-			     ) 'phrase)))
-	     ))
-      (setq phrase (cdr phrase))
-      )
-    (ew-space-process dest)
-    ))
+			   (tm-eword::string-to-ruled-words
+			    (cdr token) 'phrase)))))
+      (setq phrase (cdr phrase)))
+    (ew-space-process dest)))
 
 (defun eword-encode-addr-seq-to-rword-list (seq)
   (let (dest pname)
     (while seq
       (let* ((token (car seq))
-	     (name (car token))
-	     )
+	     (name (car token)))
 	(cond ((eq name 'spaces)
-	       (setq dest (nconc dest (list (list (cdr token) nil nil))))
-	       )
+	       (setq dest (nconc dest (list (list (cdr token) nil nil)))))
 	      ((eq name 'comment)
 	       (setq dest
 		     (nconc
 		      dest
 		      (list (list "(" nil nil))
 		      (eword-encode-split-string (cdr token) 'comment)
-		      (list (list ")" nil nil))
-		      ))
-	       )
+		      (list (list ")" nil nil)))))
 	      ((eq name 'quoted-string)
 	       (setq dest
 		     (nconc
 		      dest
 		      (list
-		       (list (concat "\"" (cdr token) "\"") nil nil)
-		       )))
-	       )
+		       (list (concat "\"" (cdr token) "\"") nil nil)))))
 	      (t
 	       (setq dest
 		     (if (or (eq pname 'spaces)
@@ -479,11 +361,9 @@
 			      (list
 			       (list (concat (car (car (last dest)))
 					     (cdr token))
-				     nil nil)))))
-	       ))
+				     nil nil)))))))
 	(setq seq (cdr seq)
-	      pname name))
-      )
+	      pname name)))
     dest))
 
 (defun eword-encode-phrase-route-addr-to-rword-list (phrase-route-addr)
@@ -496,36 +376,31 @@
         ;;   )
 	(setq dest (eword-encode-phrase-to-rword-list phrase))
 	(if dest
-	    (setq dest (append dest '((" " nil nil))))
-	  )
+	    (setq dest (append dest '((" " nil nil)))))
 	(append
 	 dest
 	 (eword-encode-addr-seq-to-rword-list
 	  (append '((specials . "<"))
 		  route
-		  '((specials . ">"))))
-	 ))))
+		  '((specials . ">"))))))))
 
 (defun eword-encode-addr-spec-to-rword-list (addr-spec)
   (if (eq (car addr-spec) 'addr-spec)
-      (eword-encode-addr-seq-to-rword-list (cdr addr-spec))
-    ))
+      (eword-encode-addr-seq-to-rword-list (cdr addr-spec))))
 
 (defun eword-encode-mailbox-to-rword-list (mbox)
   (let ((addr (nth 1 mbox))
 	(comment (nth 2 mbox))
 	dest)
     (setq dest (or (eword-encode-phrase-route-addr-to-rword-list addr)
-		   (eword-encode-addr-spec-to-rword-list addr)
-		   ))
+		   (eword-encode-addr-spec-to-rword-list addr)))
     (if comment
 	(setq dest
 	      (append dest
 		      '((" " nil nil)
 			("(" nil nil))
 		      (eword-encode-split-string comment 'comment)
-		      (list '(")" nil nil))
-		      )))
+		      (list '(")" nil nil)))))
     dest))
 
 (defsubst eword-encode-mailboxes-to-rword-list (mboxes)
@@ -577,8 +452,7 @@
 		    (let ((elt (car in-reply-to)))
 		      (if (eq (car elt) 'phrase)
 			  (eword-encode-phrase-to-rword-list (cdr elt))
-			(eword-encode-msg-id-to-rword-list elt)
-			))))
+			(eword-encode-msg-id-to-rword-list elt)))))
       (setq in-reply-to (cdr in-reply-to)))
     dest))
 
@@ -586,6 +460,9 @@
 ;;; @ application interfaces
 ;;;
 
+(provide 'eword-encode)
+(require 'mime-parse)
+
 (defvar eword-encode-default-start-column 10
   "Default start column if it is omitted.")
 
@@ -604,8 +481,7 @@
   (car (eword-encode-rword-list
 	(or column eword-encode-default-start-column)
 	(eword-encode-addresses-to-rword-list
-	 (std11-parse-addresses-string string))
-	)))
+	 (std11-parse-addresses-string string)))))
 
 (defun eword-encode-in-reply-to (string &optional column)
   "Encode header field STRING as In-Reply-To field, and return the result.
@@ -620,8 +496,7 @@
 Optional argument COLUMN is start-position of the field."
   (car (eword-encode-rword-list
 	(or column eword-encode-default-start-column)
-	(eword-encode-addr-seq-to-rword-list (std11-lexical-analyze string))
-	)))
+	(eword-encode-addr-seq-to-rword-list (std11-lexical-analyze string)))))
 
 (defun eword-encode-unstructured-field-body (string &optional column)
   "Encode header field STRING as unstructured field, and return the result.
@@ -630,6 +505,81 @@
 	(or column eword-encode-default-start-column)
 	(eword-encode-split-string string 'text))))
 
+(defun eword-encode-Content-Type-field-body (field-body &optional _column)
+  "Encode FIELD-BODY with MIME Parameter-Value Extensions, if necessary.
+Optional second arg COLUMN is ignored."
+  (let ((tokens (mime-lexical-analyze field-body))
+	primary-type)
+    (unless (eq (car (car tokens)) 'mime-token)
+      (error "Invalid Content-Type value: %s" field-body))
+    (setq primary-type (downcase (cdr (car tokens)))
+	  tokens (cdr tokens))
+    (unless (and (eq (car (car tokens)) 'tspecials)
+		 (string= (cdr (car tokens)) "/")
+		 (setq tokens (cdr tokens))
+		 (eq (car (car tokens)) 'mime-token))
+      (error "Invalid Content-Type value: %s" field-body))
+    (concat " " primary-type "/" (downcase (cdr (car tokens)))
+            (mapconcat
+             (lambda (param)
+               (concat ";\n " (car param) "=" (cdr param)))
+             (mime-encode-parameters
+	      (mime-parse-parameters (cdr tokens)))
+             ""))))
+
+(defun eword-encode-Content-Disposition-field-body
+    (field-body &optional _column)
+  "Encode FIELD-BODY with MIME Parameter-Value Extensions, if necessary.
+Optional second arg COLUMN is ignored."
+  (let ((tokens (mime-lexical-analyze field-body)))
+    (unless (eq (car (car tokens)) 'mime-token)
+      (error "Invalid Content-Disposition value: %s" field-body))
+    (concat " " (cdr (car tokens))
+            (mapconcat
+             (lambda (param)
+               (concat ";\n " (car param) "=" (cdr param)))
+             (mime-encode-parameters
+	      (mime-parse-parameters (cdr tokens)))
+             ""))))
+
+(defun eword-encode-Content-Type-field-body-broken-mime
+  (field-body &optional _column)
+  "Encode FIELD-BODY compatibly with Outlook, if necessary.
+Optional second arg COLUMN is ignored."
+  (let ((tokens (mime-lexical-analyze field-body))
+	primary-type)
+    (unless (eq (car (car tokens)) 'mime-token)
+      (error "Invalid Content-Type value: %s" field-body))
+    (setq primary-type (downcase (cdr (car tokens)))
+	  tokens (cdr tokens))
+    (unless (and (eq (car (car tokens)) 'tspecials)
+		 (string= (cdr (car tokens)) "/")
+		 (setq tokens (cdr tokens))
+		 (eq (car (car tokens)) 'mime-token))
+      (error "Invalid Content-Type value: %s" field-body))
+    (concat " " primary-type "/" (downcase (cdr (car tokens)))
+            (mapconcat
+             (lambda (param)
+               (concat ";\n " (car param) "=\"" (cdr param) "\""))
+             (mime-encode-parameters-broken-mime
+	      (mime-parse-parameters (cdr tokens)))
+             ""))))
+
+(defun eword-encode-Content-Disposition-field-body-broken-mime
+  (field-body &optional _column)
+  "Encode FIELD-BODY compatibly with Outlook, if necessary.
+Optional second arg COLUMN is ignored."
+  (let ((tokens (mime-lexical-analyze field-body)))
+    (unless (eq (car (car tokens)) 'mime-token)
+      (error "Invalid Content-Disposition value: %s" field-body))
+    (concat " " (cdr (car tokens))
+            (mapconcat
+             (lambda (param)
+               (concat ";\n " (car param) "=\"" (cdr param) "\""))
+             (mime-encode-parameters-broken-mime
+	      (mime-parse-parameters (cdr tokens)))
+             ""))))
+
 ;;;###autoload
 (defun mime-encode-field-body (field-body field-name)
   "Encode FIELD-BODY as FIELD-NAME, and return the result.
@@ -655,13 +605,13 @@
 	(setq method-alist (cdr method-alist)))
       ret)))
 (defalias 'eword-encode-field-body 'mime-encode-field-body)
-(make-obsolete 'eword-encode-field-body 'mime-encode-field-body)
+(make-obsolete 'eword-encode-field-body 'mime-encode-field-body "19 Dec 2000")
 
 (defun eword-in-subject-p ()
   (let ((str (std11-field-body "Subject")))
     (if (and str (string-match eword-encoded-word-regexp str))
 	str)))
-(make-obsolete 'eword-in-subject-p "Don't use it.")
+(make-obsolete 'eword-in-subject-p "Don't use it." "19 Dec 2000")
 
 (defsubst eword-find-field-encoding-method (field-name)
   (setq field-name (downcase field-name))
@@ -672,11 +622,9 @@
 	       (str (car pair)))
 	  (if (and (stringp str)
 		   (string= field-name (downcase str)))
-	      (throw 'found (cdr pair))
-	    ))
+	      (throw 'found (cdr pair))))
 	(setq alist (cdr alist)))
-      (cdr (assq t mime-field-encoding-method-alist))
-      )))
+      (cdr (assq t mime-field-encoding-method-alist)))))
 
 ;;;###autoload
 (defun mime-encode-header-in-buffer (&optional code-conversion)
@@ -715,7 +663,8 @@
 				   default-cs)))
 			  (encode-coding-region bbeg end cs)))))))))))
 (defalias 'eword-encode-header 'mime-encode-header-in-buffer)
-(make-obsolete 'eword-encode-header 'mime-encode-header-in-buffer)
+(make-obsolete 'eword-encode-header
+	       'mime-encode-header-in-buffer "19 Dec 2000")
 
 
 ;;; @ end
