$NetBSD: patch-std11.el,v 1.1 2023/09/03 14:58:39 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/std11.el	2005-11-13 10:04:36.000000000 +0900
+++ ./std11.el	2023-08-31 08:29:38.624627921 +0900
@@ -1,4 +1,4 @@
-;;; std11.el --- STD 11 functions for GNU Emacs
+;;; std11.el --- STD 11 functions for GNU Emacs  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1995,96,97,98,99,2000,01,02 Free Software Foundation, Inc.
 
@@ -24,8 +24,8 @@
 
 ;;; Code:
 
-(require 'custom)			; std11-lexical-analyzer
-
+(require 'pccl)
+(require 'static)
 
 ;;; @ fetch
 ;;;
@@ -54,21 +54,18 @@
     (goto-char (point-min))
     (let ((case-fold-search t))
       (if (re-search-forward (concat "^" name ":[ \t]*") nil t)
-	  (buffer-substring-no-properties (match-end 0) (std11-field-end))
-	))))
+	  (buffer-substring-no-properties (match-end 0) (std11-field-end))))))
 
 ;;;###autoload
 (defun std11-narrow-to-header (&optional boundary)
-  "Narrow to the message header.
+  "Narrow to the message header when needed.
 If BOUNDARY is not nil, it is used as message header separator."
-  (narrow-to-region
-   (goto-char (point-min))
-   (if (re-search-forward
-	(concat "^\\(" (regexp-quote (or boundary "")) "\\)?$")
-	nil t)
-       (match-beginning 0)
-     (point-max)
-     )))
+  (goto-char (point-min))
+  (when (re-search-forward
+	 (if boundary (concat "^\\(" (regexp-quote boundary) "\\)?$")
+	   "^$")
+	 nil t)
+    (narrow-to-region (point-min) (match-beginning 0))))
 
 ;;;###autoload
 (defun std11-field-body (name &optional boundary)
@@ -77,8 +74,7 @@
   (save-excursion
     (save-restriction
       (inline (std11-narrow-to-header boundary)
-	      (std11-fetch-field name))
-      )))
+	      (std11-fetch-field name)))))
 
 (defun std11-find-field-body (field-names &optional boundary)
   "Return the first found field-body specified by FIELD-NAMES
@@ -90,15 +86,13 @@
       (let ((case-fold-search t)
 	    field-name)
 	(catch 'tag
+	  (goto-char (point-min))
 	  (while (setq field-name (car field-names))
-	    (goto-char (point-min))
 	    (if (re-search-forward (concat "^" field-name ":[ \t]*") nil t)
 		(throw 'tag
 		       (buffer-substring-no-properties
-			(match-end 0) (std11-field-end)))
-	      )
-	    (setq field-names (cdr field-names))
-	    ))))))
+			(match-end 0) (std11-field-end))))
+	    (setq field-names (cdr field-names))))))))
 
 (defun std11-field-bodies (field-names &optional default-value boundary)
   "Return list of each field-bodies of FIELD-NAMES of the message header
@@ -117,11 +111,9 @@
 	  (if (re-search-forward (concat "^" field-name ":[ \t]*") nil t)
 	      (setcar d-rest
 		      (buffer-substring-no-properties
-		       (match-end 0) (std11-field-end)))
-	    )
+		       (match-end 0) (std11-field-end))))
 	  (setq s-rest (cdr s-rest)
-		d-rest (cdr d-rest))
-	  )
+		d-rest (cdr d-rest)))
 	dest))))
 
 (defun std11-header-string (regexp &optional boundary)
@@ -136,11 +128,9 @@
 	  (while (re-search-forward std11-field-head-regexp nil t)
 	    (setq field
 		  (buffer-substring (match-beginning 0) (std11-field-end)))
-	    (if (string-match regexp field)
-		(setq header (concat header field "\n"))
-	      ))
-	  header)
-	))))
+	    (when (string-match regexp field)
+	      (setq header (cons "\n" (cons field header)))))
+	  (apply 'concat (nreverse header)))))))
 
 (defun std11-header-string-except (regexp &optional boundary)
   "Return string of message header fields not matched by REGEXP.
@@ -155,10 +145,8 @@
 	    (setq field
 		  (buffer-substring (match-beginning 0) (std11-field-end)))
 	    (if (not (string-match regexp field))
-		(setq header (concat header field "\n"))
-	      ))
-	  header)
-	))))
+		(setq header (cons "\n" (cons field header)))))
+	  (apply 'concat (nreverse header)))))))
 
 (defun std11-collect-field-names (&optional boundary)
   "Return list of all field-names of the message header in current buffer.
@@ -172,30 +160,34 @@
 	  (setq name (buffer-substring-no-properties
 		      (match-beginning 0)(1- (match-end 0))))
 	  (or (member name dest)
-	      (setq dest (cons name dest))
-	      )
-	  )
+	      (setq dest (cons name dest))))
 	dest))))
 
 
 ;;; @ unfolding
 ;;;
 
+(defcustom std11-unfold-strip-leading-tab t
+  "When non-nil, `std11-unfold-string' strips leading TAB, which is
+mainly added by incorrect folding."
+  :group 'news
+  :group 'mail
+  :type 'boolean)
+
 ;;;###autoload
 (defun std11-unfold-string (string)
   "Unfold STRING as message header field."
-  (let ((dest "")
+  (let (dest
 	(p 0))
-    (while (string-match "\n\\([ \t]\\)" string p)
-      (setq dest (concat dest
-                         (substring string p (match-beginning 0))
-                         (substring string
-				    (match-beginning 1)
-				    (setq p (match-end 0)))
-                         ))
-      )
-    (concat dest (substring string p))
-    ))
+    (while (string-match "\\( ?\\)\n\\([ \t]\\)" string p)
+      (setq dest (cons (unless (and std11-unfold-strip-leading-tab
+				    (< (match-beginning 0) (match-end 1))
+				    (eq (aref string (match-beginning 2)) ?\t))
+			 (match-string 2 string))
+		       (cons (substring string p (match-end 1))
+			     dest))
+	    p (match-end 0)))
+    (apply 'concat (nreverse (cons (substring string p) dest)))))
 
 
 ;;; @ quoted-string
@@ -205,18 +197,13 @@
   (let (dest
 	(i 0)
 	(b 0)
-	(len (length string))
-	)
+	(len (length string)))
     (while (< i len)
-      (let ((chr (aref string i)))
-	(if (memq chr specials)
-	    (setq dest (concat dest (substring string b i) "\\")
-		  b i)
-	  ))
-      (setq i (1+ i))
-      )
-    (concat dest (substring string b))
-    ))
+      (if (memq (aref string i) specials)
+	  (setq dest (cons "\\" (cons (substring string b i) dest))
+		b i))
+      (setq i (1+ i)))
+    (apply 'concat (nreverse (cons (substring string b) dest)))))
 
 (defconst std11-non-qtext-char-list '(?\" ?\\ ?\r ?\n))
 
@@ -231,18 +218,14 @@
   (let (dest
 	(b 0)
 	(i 0)
-	(len (length string))
-	)
+	(len (length string)))
     (while (< i len)
-      (let ((chr (aref string i)))
-	(if (eq chr ?\\)
-	    (setq dest (concat dest (substring string b i))
-		  b (1+ i)
-		  i (+ i 2))
-	  (setq i (1+ i))
-	  )))
-    (concat dest (substring string b))
-    ))
+      (if (eq (aref string i) ?\\)
+	  (setq dest (cons (substring string b i) dest)
+		b (1+ i)
+		i (+ i 2))
+	(setq i (1+ i))))
+    (apply 'concat (nreverse (cons (substring string b) dest)))))
 
 (defun std11-strip-quoted-string (string)
   "Strip quoted-string STRING."
@@ -251,14 +234,144 @@
 	     (let ((max (1- len)))
 	       (and (eq (aref string 0) ?\")
 		    (eq (aref string max) ?\")
-		    (std11-strip-quoted-pair (substring string 1 max))
-		    )))
+		    (std11-strip-quoted-pair (substring string 1 max)))))
 	string)))
 
 
 ;;; @ lexical analyze
 ;;;
 
+(unless-broken ccl-usable
+(define-ccl-program std11-default-ccl-lexical-analyzer
+  ;; r0 input
+  ;; r1 flag means any character exists.
+  ;; r2 in parse flag
+  ;;    1 atom, 2 spaces, 3 quoted string or domain literal, 4 comment
+  ;; r3 comment depth
+  (eval-when-compile
+    (let* ((wrt `(if (r0 == ?\") (write "\\\"")
+		   (if (r0 == ?\\) (write "\\\\")
+		     (write r0))))
+	   (atm `((branch r2
+			  ((r2 = 1)
+			   (write "(atom . \"")
+			   (write-read-repeat r0))
+			  (write-read-repeat r0)
+			  ((write "\")")
+			   (r2 = 1)
+			   (write "(atom . \"")
+			   (write-read-repeat r0)))))
+	   (spc `((if r2 ((write "\")") (r2 = 0)))
+		  (write "(specials . \"")
+		  ,wrt
+		  (write "\")")
+		  (read r0)
+		  (repeat)))
+	   (sp  `((branch r2
+			  ((r2 = 2)
+			   (write "(spaces . \"")
+			   (write-read-repeat r0))
+			  ((write "\")")
+			   (r2 = 2)
+			   (write "(spaces . \"")
+			   (write-read-repeat r0))
+			  (write-read-repeat r0))))
+	   (enc (lambda (name tag)
+		  `((if r2 ((write "\")")))
+		    (write ,(concat "(" name " . \""))
+		    (r2 = 3)
+		    (loop
+		     (read-branch
+		      r0
+		      ,@(let* ((count (1+ (max tag ?\\)))
+			       (result (make-vector count '(write-repeat r0))))
+			  (aset result ?\\ `((write "\\\\")
+					     (read r0)
+					     ,wrt
+					     (repeat)))
+			  (aset result ?\" '((write "\\\"")
+					     (repeat)))
+			  (aset result tag '(break))
+			  (mapcar 'identity result)))
+		     (write-repeat r0))
+		    (write "\")")
+		    (r2 = 0)
+		    (read r0)
+		    (repeat))))
+	   (qs (funcall enc "quoted-string" ?\"))
+	   (dl (funcall enc "domain-literal" ?\]))
+	   (cm  `((if r2 ((write "\")")))
+		  (write "(comment . \"")
+		  (r2 = 4)
+		  (r3 = 1)
+		  (loop
+		   (read-branch
+		    r0
+		    ,@(let* ((count (1+ (max ?\( ?\) ?\\)))
+			     (result (make-vector count '(write-repeat r0))))
+			(aset result ?\( '((r3 += 1) (write-repeat r0)))
+			(aset result ?\) '((r3 -= 1)
+					   (if (r3 < 1) (break)
+					     (write-repeat r0))))
+			(aset result ?\\ `((write "\\\\")
+					   (read r0)
+					   ,wrt
+					   (repeat)))
+			(aset result ?\"
+			      '((write "\\\"") (repeat)))
+			(mapcar 'identity result)))
+		   (write-repeat r0))
+		  (write "\")")
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
+		  ,@(mapcar (lambda (elt)
+			      (eval elt))
+			    '(atm atm atm atm atm atm atm atm
+				  atm sp  sp  atm atm atm atm atm
+				  atm atm atm atm atm atm atm atm
+				  atm atm atm atm atm atm atm atm
+				  sp  atm qs  atm atm atm atm atm
+				  cm  spc atm atm spc atm spc atm
+				  atm atm atm atm atm atm atm atm
+				  atm atm spc spc spc atm spc atm
+				  spc atm atm atm atm atm atm atm
+				  atm atm atm atm atm atm atm atm
+				  atm atm atm atm atm atm atm atm
+				  atm atm atm dl  spc spc)))
+	  ,@atm))
+	((branch r1
+		 (write "(nil . t)")
+		 (branch r2
+			 (write ") . t)")
+			 (write "\")) . t)")
+			 (write "\")) . t)")
+			 (write "\")))")
+			 (write "\")))")))))))))
+
+(defcustom std11-ccl-lexical-analyzer
+  (static-unless (or (broken-p 'ccl-execute-eof-block)
+		     (broken-p 'ccl-usable))
+    'std11-default-ccl-lexical-analyzer)
+  "Specify CCL-program symbol for `std11-lexical-analyze'.
+When nil, do not use CCL.
+
+CCL-program returns a string which expresses a cons.  When cons's
+cdr is non-nil, CCL-program succeeds in analyzing and car is
+analyzed result.  When cdr is nil, CCL-program fails in analyzing.
+If you modify `std11-lexical-analyzer', set this variable to nil
+or prepare corresponding CCL-program."
+  :group 'news
+  :group 'mail
+  :type '(choice symbol (const :tag "Do not use CCL." nil)))
+
 (defcustom std11-lexical-analyzer
   '(std11-analyze-quoted-string
     std11-analyze-domain-literal
@@ -279,12 +392,11 @@
   :type '(repeat function))
 
 (eval-and-compile
-  (defconst std11-space-char-list '(?  ?\t ?\n))
+  (defconst std11-space-char-list '(?\s ?\t ?\n))
   (defconst std11-special-char-list '(?\] ?\[
 					  ?\( ?\) ?< ?> ?@
 					  ?, ?\; ?: ?\\ ?\"
-					  ?.))
-  )
+					  ?.)))
 ;; (defconst std11-spaces-regexp
 ;;   (eval-when-compile (concat "[" std11-space-char-list "]+")))
 
@@ -304,16 +416,14 @@
       (let ((end (match-end 0)))
 	(cons (cons 'spaces (substring string start end))
 	      ;;(substring string end)
-	      end)
-	)))
+	      end))))
 
 (defun std11-analyze-special (string start)
   (if (and (> (length string) start)
 	   (memq (aref string start) std11-special-char-list))
       (cons (cons 'specials (substring string start (1+ start)))
 	    ;;(substring string 1)
-	    (1+ start))
-    ))
+	    (1+ start))))
 
 (defun std11-analyze-atom (string start)
   (if (string-match std11-non-atom-regexp string start)
@@ -334,8 +444,7 @@
 
 (defun std11-check-enclosure (string open close &optional recursive from)
   (let ((len (length string))
-	(i (or from 0))
-	)
+	(i (or from 0)))
     (if (and (> len i)
 	     (eq (aref string i) open))
 	(let (p chr)
@@ -346,97 +455,83 @@
 	      (cond ((eq chr ?\\)
 		     (setq i (1+ i))
 		     (if (>= i len)
-			 (throw 'tag nil)
-		       )
-		     (setq i (1+ i))
-		     )
+			 (throw 'tag nil))
+		     (setq i (1+ i)))
 		    ((eq chr close)
-		     (throw 'tag (1+ i))
-		     )
+		     (throw 'tag (1+ i)))
 		    ((eq chr open)
 		     (if (and recursive
 			      (setq p (std11-check-enclosure
-				       string open close recursive i))
-			      )
+				       string open close recursive i)))
 			 (setq i p)
-		       (throw 'tag nil)
-		       ))
+		       (throw 'tag nil)))
 		    (t
-		     (setq i (1+ i))
-		     ))
-	      ))))))
+		     (setq i (1+ i))))))))))
 
 (defun std11-analyze-quoted-string (string start)
   (let ((p (std11-check-enclosure string ?\" ?\" nil start)))
     (if p
 	(cons (cons 'quoted-string (substring string (1+ start) (1- p)))
 	      ;;(substring string p))
-	      p)
-      )))
+	      p))))
 
 (defun std11-analyze-domain-literal (string start)
   (let ((p (std11-check-enclosure string ?\[ ?\] nil start)))
     (if p
 	(cons (cons 'domain-literal (substring string (1+ start) (1- p)))
 	      ;;(substring string p))
-	      p)
-      )))
+	      p))))
 
 (defun std11-analyze-comment (string start)
   (let ((p (std11-check-enclosure string ?\( ?\) t start)))
     (if p
 	(cons (cons 'comment (substring string (1+ start) (1- p)))
 	      ;;(substring string p))
-	      p)
-      )))
+	      p))))
 
 ;;;###autoload
 (defun std11-lexical-analyze (string &optional analyzer start)
   "Analyze STRING as lexical tokens of STD 11."
-  (or analyzer
-      (setq analyzer std11-lexical-analyzer))
-  (or start
-      (setq start 0))
-  (let ((len (length string))
-	dest ret)
-    (while (< start len)
-      (setq ret
-	    (let ((rest analyzer)
-		  func r)
-	      (while (and (setq func (car rest))
-			  (null (setq r (funcall func string start))))
-		(setq rest (cdr rest)))
-	      (or r
-		  (cons (cons 'error (substring string start)) (1+ len)))
-	      ))
-      (setq dest (cons (car ret) dest)
-	    start (cdr ret))
-      )
-    (nreverse dest)
-    ))
+  (let (len dest ret)
+    (if (and std11-ccl-lexical-analyzer
+	     (null analyzer)
+	     (cdr (setq ret (read (ccl-execute-on-string
+				   std11-ccl-lexical-analyzer
+				   (make-vector 9 0)
+				   (if start (substring string start)
+				     (or string "")))))))
+	(car ret)
+      (setq len (length string)
+	    analyzer (or analyzer std11-lexical-analyzer)
+	    start (or start 0))
+      (while (< start len)
+	(setq ret
+	      (let ((rest analyzer)
+		    func r)
+		(while (and (setq func (car rest))
+			    (null (setq r (funcall func string start))))
+		  (setq rest (cdr rest)))
+		(or r
+		    (cons (cons 'error (substring string start)) (1+ len)))))
+	(setq dest (cons (car ret) dest)
+	      start (cdr ret)))
+      (nreverse dest))))
 
 
 ;;; @ parser
 ;;;
 
 (defun std11-ignored-token-p (token)
-  (let ((type (car token)))
-    (or (eq type 'spaces)(eq type 'comment))
-    ))
+  (memq (car token) '(spaces comment)))
 
 (defun std11-parse-token (lal)
   (let (token itl)
     (while (and lal
-		(progn
-		  (setq token (car lal))
-		  (std11-ignored-token-p token)
-		  ))
+		(std11-ignored-token-p (setq token (car lal))))
       (setq lal (cdr lal))
-      (setq itl (cons token itl))
-      )
+      (setq itl (cons token itl)))
     (cons (nreverse (cons token itl))
-	  (cdr lal))
-    ))
+	  (cdr lal))))
 
 (defun std11-parse-ascii-token (lal)
   (let (token itl parsed token-value)
@@ -445,69 +540,51 @@
 		(or (std11-ignored-token-p token)
 		    (if (and (setq token-value (cdr token))
 			     (delq 'ascii (find-charset-string token-value)))
-			(setq token nil)
-		      )))
+			(setq token nil))))
       (setq lal (cdr lal))
-      (setq itl (cons token itl))
-      )
+      (setq itl (cons token itl)))
     (if (and token
-	     (setq parsed (nreverse (cons token itl)))
-	     )
-	(cons parsed (cdr lal))
-      )))
+	     (setq parsed (nreverse (cons token itl))))
+	(cons parsed (cdr lal)))))
 
 (defun std11-parse-token-or-comment (lal)
   (let (token itl)
     (while (and lal
-		(progn
-		  (setq token (car lal))
-		  (eq (car token) 'spaces)
-		  ))
+		(eq (car (setq token (car lal))) 'spaces))
       (setq lal (cdr lal))
-      (setq itl (cons token itl))
-      )
+      (setq itl (cons token itl)))
     (cons (nreverse (cons token itl))
-	  (cdr lal))
-    ))
+	  (cdr lal))))
 
 (defun std11-parse-word (lal)
   (let ((ret (std11-parse-ascii-token lal)))
     (if ret
 	(let ((elt (car ret))
-	      (rest (cdr ret))
-	      )
+	      (rest (cdr ret)))
 	  (if (or (assq 'atom elt)
 		  (assq 'quoted-string elt))
-	      (cons (cons 'word elt) rest)
-	    )))))
+	      (cons (cons 'word elt) rest))))))
 
 (defun std11-parse-word-or-comment-or-period (lal)
   (let ((ret (std11-parse-token-or-comment lal)))
     (if ret
 	(let ((elt (car ret))
-	      (rest (cdr ret))
-	      )
+	      (rest (cdr ret)))
 	  (cond ((or (assq 'atom elt)
 		     (assq 'quoted-string elt))
-		 (cons (cons 'word elt) rest)
-		 )
+		 (cons (cons 'word elt) rest))
 		((assq 'comment elt)
-		 (cons (cons 'comment-word elt) rest)
-		 )
+		 (cons (cons 'comment-word elt) rest))
 		((string-equal (cdr (assq 'specials elt)) ".")
-		 (cons (cons 'period elt) rest)
-		 ))
-	  ))))
+		 (cons (cons 'period elt) rest)))))))
 
 (defun std11-parse-phrase (lal)
   (let (ret phrase)
     (while (setq ret (std11-parse-word-or-comment-or-period lal))
       (setq phrase (append phrase (cdr (car ret))))
-      (setq lal (cdr ret))
-      )
+      (setq lal (cdr ret)))
     (if phrase
-	(cons (cons 'phrase phrase) lal)
-      )))
+	(cons (cons 'phrase phrase) lal))))
 
 (defun std11-parse-local-part (lal)
   (let ((ret (std11-parse-word lal)))
@@ -519,24 +596,18 @@
 		      (string-equal (cdr (assq 'specials dot)) ".")
 		      (setq ret (std11-parse-word (cdr ret)))
 		      (setq local-part
-			    (append local-part dot (cdr (car ret)))
-			    )
-		      (setq lal (cdr ret))
-		      ))
-	  (cons (cons 'local-part local-part) lal)
-	  ))))
+			    (append local-part dot (cdr (car ret))))
+		      (setq lal (cdr ret))))
+	  (cons (cons 'local-part local-part) lal)))))
 
 (defun std11-parse-sub-domain (lal)
   (let ((ret (std11-parse-ascii-token lal)))
     (if ret
 	(let ((sub-domain (car ret)))
 	  (if (or (assq 'atom sub-domain)
-		  (assq 'domain-literal sub-domain)
-		  )
+		  (assq 'domain-literal sub-domain))
 	      (cons (cons 'sub-domain sub-domain)
-		    (cdr ret)
-		    )
-	    )))))
+		    (cdr ret)))))))
 
 (defun std11-parse-domain (lal)
   (let ((ret (std11-parse-sub-domain lal)))
@@ -548,23 +619,18 @@
 		      (string-equal (cdr (assq 'specials dot)) ".")
 		      (setq ret (std11-parse-sub-domain (cdr ret)))
 		      (setq domain
-			    (append domain dot (cdr (car ret)))
-			    )
-		      (setq lal (cdr ret))
-		      ))
-	  (cons (cons 'domain domain) lal)
-	  ))))
+			    (append domain dot (cdr (car ret))))
+		      (setq lal (cdr ret))))
+	  (cons (cons 'domain domain) lal)))))
 
 (defun std11-parse-at-domain (lal)
   (let ((ret (std11-parse-ascii-token lal)) at-sign)
     (if (and ret
 	     (setq at-sign (car ret))
 	     (string-equal (cdr (assq 'specials at-sign)) "@")
-	     (setq ret (std11-parse-domain (cdr ret)))
-	     )
+	     (setq ret (std11-parse-domain (cdr ret))))
 	(cons (cons 'at-domain (append at-sign (cdr (car ret))))
-	      (cdr ret))
-      )))
+	      (cdr ret)))))
 
 (defun std11-parse-addr-spec (lal)
   (let ((ret (std11-parse-local-part lal))
@@ -575,10 +641,8 @@
 	       (setq lal (cdr ret))
 	       (and (setq ret (std11-parse-at-domain lal))
 		    (setq addr (append addr (cdr (car ret))))
-		    (setq lal (cdr ret))
-		    )))
-	(cons (cons 'addr-spec addr) lal)
-      )))
+		    (setq lal (cdr ret)))))
+	(cons (cons 'addr-spec addr) lal))))
 
 (defun std11-parse-route (lal)
   (let ((ret (std11-parse-at-domain lal))
@@ -590,21 +654,15 @@
 	       (while (and (setq ret (std11-parse-ascii-token lal))
 			   (setq comma (car ret))
 			   (string-equal (cdr (assq 'specials comma)) ",")
-			   (setq ret (std11-parse-at-domain (cdr ret)))
-			   )
+			   (setq ret (std11-parse-at-domain (cdr ret))))
 		 (setq route (append route comma (cdr (car ret))))
-		 (setq lal (cdr ret))
-		 )
+		 (setq lal (cdr ret)))
 	       (and (setq ret (std11-parse-ascii-token lal))
 		    (setq colon (car ret))
 		    (string-equal (cdr (assq 'specials colon)) ":")
-		    (setq route (append route colon))
-		    )
-	       ))
+		    (setq route (append route colon)))))
 	(cons (cons 'route route)
-	      (cdr ret)
-	      )
-      )))
+	      (cdr ret)))))
 
 (defun std11-parse-route-addr (lal)
   (let ((ret (std11-parse-ascii-token lal))
@@ -615,34 +673,27 @@
 	     (setq lal (cdr ret))
 	     (progn (and (setq ret (std11-parse-route lal))
 			 (setq route (cdr (car ret)))
-			 (setq lal (cdr ret))
-			 )
-		    (setq ret (std11-parse-addr-spec lal))
-		    )
+			 (setq lal (cdr ret)))
+		    (setq ret (std11-parse-addr-spec lal)))
 	     (setq addr-spec (cdr (car ret)))
 	     (setq lal (cdr ret))
 	     (setq ret (std11-parse-ascii-token lal))
 	     (setq > (car ret))
-	     (string-equal (cdr (assq 'specials >)) ">")
-	     )
+	     (string-equal (cdr (assq 'specials >)) ">"))
 	(cons (cons 'route-addr (append route addr-spec))
-	      (cdr ret)
-	      )
-      )))
+	      (cdr ret)))))
 
 (defun std11-parse-phrase-route-addr (lal)
   (let ((ret (std11-parse-phrase lal)) phrase)
     (if ret
 	(progn
 	  (setq phrase (cdr (car ret)))
-	  (setq lal (cdr ret))
-	  ))
+	  (setq lal (cdr ret))))
     (if (setq ret (std11-parse-route-addr lal))
 	(cons (list 'phrase-route-addr
 		    phrase
 		    (cdr (car ret)))
-	      (cdr ret))
-      )))
+	      (cdr ret)))))
 
 (defun std11-parse-mailbox (lal)
   (let ((ret (or (std11-parse-phrase-route-addr lal)
@@ -653,13 +704,10 @@
 		 (setq mbox (car ret))
 	       (setq lal (cdr ret))
 	       (if (and (setq ret (std11-parse-token-or-comment lal))
-			(setq comment (cdr (assq 'comment (car ret))))
-			)
-		   (setq lal (cdr ret))
-		 )))
+			(setq comment (cdr (assq 'comment (car ret)))))
+		   (setq lal (cdr ret)))))
 	(cons (list 'mailbox mbox comment)
-	      lal)
-      )))
+	      lal))))
 
 (defun std11-parse-group (lal)
   (let ((ret (std11-parse-phrase lal))
@@ -675,30 +723,24 @@
 	       (and (setq ret (std11-parse-mailbox lal))
 		    (setq mbox (list (car ret)))
 		    (setq lal (cdr ret))
-		    (progn
-		      (while (and (setq ret (std11-parse-ascii-token lal))
-				  (setq comma (car ret))
-				  (string-equal
-				   (cdr (assq 'specials comma)) ",")
-				  (setq lal (cdr ret))
-				  (setq ret (std11-parse-mailbox lal))
-				  (setq mbox (cons (car ret) mbox))
-				  (setq lal (cdr ret))
-				  )
-			)))
+		    (while (and (setq ret (std11-parse-ascii-token lal))
+				(setq comma (car ret))
+				(string-equal
+				 (cdr (assq 'specials comma)) ",")
+				(setq lal (cdr ret))
+				(setq ret (std11-parse-mailbox lal))
+				(setq mbox (cons (car ret) mbox))
+				(setq lal (cdr ret)))))
 	       (and (setq ret (std11-parse-ascii-token lal))
 		    (setq semicolon (car ret))
 		    (string-equal (cdr (assq 'specials semicolon)) ";")
 		    )))
 	(cons (list 'group phrase (nreverse mbox))
-	      (cdr ret)
-	      )
-      )))
+	      (cdr ret)))))
 
 (defun std11-parse-address (lal)
   (or (std11-parse-group lal)
-      (std11-parse-mailbox lal)
-      ))
+      (std11-parse-mailbox lal)))
 
 (defun std11-parse-addresses (lal)
   (let ((ret (std11-parse-address lal)))
@@ -707,13 +749,10 @@
 	  (setq lal (cdr ret))
 	  (while (and (setq ret (std11-parse-ascii-token lal))
 		      (string-equal (cdr (assq 'specials (car ret))) ",")
-		      (setq ret (std11-parse-address (cdr ret)))
-		      )
+		      (setq ret (std11-parse-address (cdr ret))))
 	    (setq dest (cons (car ret) dest))
-	    (setq lal (cdr ret))
-	    )
-	  (nreverse dest)
-	  ))))
+	    (setq lal (cdr ret)))
+	  (nreverse dest)))))
 
 (defun std11-parse-msg-id (lal)
   (let ((ret (std11-parse-ascii-token lal))
@@ -727,11 +766,9 @@
 	     (setq lal (cdr ret))
 	     (setq ret (std11-parse-ascii-token lal))
 	     (setq > (car ret))
-	     (string-equal (cdr (assq 'specials >)) ">")
-	     )
+	     (string-equal (cdr (assq 'specials >)) ">"))
 	(cons (cons 'msg-id (cdr addr-spec))
-	      (cdr ret))
-      )))
+	      (cdr ret)))))
 
 (defun std11-parse-msg-ids (tokens)
   "Parse lexical TOKENS as `*(phrase / msg-id)', and return the result."
@@ -743,13 +780,11 @@
 	  (while (setq ret (or (std11-parse-msg-id tokens)
 			       (std11-parse-phrase tokens)))
 	    (setq dest (cons (car ret) dest))
-	    (setq tokens (cdr ret))
-	    )
-	  (nreverse dest)
-	  ))))
+	    (setq tokens (cdr ret)))
+	  (nreverse dest)))))
 
 (defalias 'std11-parse-in-reply-to 'std11-parse-msg-ids)
-(make-obsolete 'std11-parse-in-reply-to 'std11-parse-msg-ids)
+(make-obsolete 'std11-parse-in-reply-to 'std11-parse-msg-ids "23 Jan 1999")
 
 
 ;;; @ composer
@@ -758,20 +793,16 @@
 (defun std11-addr-to-string (seq)
   "Return string from lexical analyzed list SEQ
 represents addr-spec of RFC 822."
-  (mapconcat (function
-	      (lambda (token)
-		(let ((name (car token)))
-                  (cond
-                   ((eq name 'spaces) "")
-                   ((eq name 'comment) "")
-                   ((eq name 'quoted-string)
-                    (concat "\"" (cdr token) "\""))
-                   ((eq name 'domain-literal)
-                    (concat "[" (cdr token) "]"))
-                   (t (cdr token)))
-                  )))
-	     seq "")
-  )
+  (mapconcat (lambda (token)
+	       (let ((name (car token)))
+                 (cond
+                  ((memq name '(spaces comment)) nil)
+                  ((eq name 'quoted-string)
+                   (concat "\"" (cdr token) "\""))
+                  ((eq name 'domain-literal)
+                   (concat "[" (cdr token) "]"))
+                  (t (cdr token)))))
+	     seq nil))
 
 ;;;###autoload
 (defun std11-address-string (address)
@@ -779,45 +810,34 @@
   (cond ((eq (car address) 'group)
 	 (mapconcat (function std11-address-string)
 		    (nth 2 address)
-		    ", ")
-	 )
+		    ", "))
 	((eq (car address) 'mailbox)
 	 (let ((addr (nth 1 address)))
 	   (std11-addr-to-string
 	    (if (eq (car addr) 'phrase-route-addr)
 		(nth 2 addr)
-	      (cdr addr)
-	      )
-	    )))))
+	      (cdr addr)))))))
 
 (defun std11-comment-value-to-string (value)
   (if (stringp value)
       (std11-strip-quoted-pair value)
-    (let ((dest ""))
+    (let (dest)
       (while value
 	(setq dest
-	      (concat dest
-		      (if (stringp (car value))
-			  (car value)
-			(concat "("
-				(std11-comment-value-to-string
-				 (cdr (car value)))
-				")")
-			))
-	      value (cdr value))
-	)
-      dest)))
+	      (if (stringp (car value))
+		  (cons (car value) dest)
+		(cons ")"
+		      (cons (std11-comment-value-to-string
+			     (cdr (car value)))
+			    (cons "(" dest))))
+	      value (cdr value)))
+      (apply 'concat (nreverse dest)))))
 
 ;;;###autoload
 (defun std11-full-name-string (address)
   "Return string of full-name part from parsed ADDRESS of RFC 822."
   (cond ((eq (car address) 'group)
-	 (mapconcat (function
-		     (lambda (token)
-		       (cdr token)
-		       ))
-		    (nth 1 address) "")
-	 )
+	 (mapconcat 'cdr (nth 1 address) ""))
 	((eq (car address) 'mailbox)
 	 (let ((addr (nth 1 address))
 	       (comment (nth 2 address))
@@ -825,33 +845,25 @@
 	   (if (eq (car addr) 'phrase-route-addr)
 	       (setq phrase
 		     (mapconcat
-		      (function
-		       (lambda (token)
-			 (let ((type (car token)))
-			   (cond ((eq type 'quoted-string)
-				  (std11-strip-quoted-pair (cdr token))
-				  )
-				 ((eq type 'comment)
-				  (concat "("
-					  (std11-comment-value-to-string
-					   (cdr token))
-					  ")")
-				  )
-				 (t
-				  (cdr token)
-				  )))))
-		      (nth 1 addr) ""))
-	     )
+		      (lambda (token)
+			(let ((type (car token)))
+			  (cond ((eq type 'quoted-string)
+				 (std11-strip-quoted-pair (cdr token)))
+				((eq type 'comment)
+				 (concat "("
+					 (std11-comment-value-to-string
+					  (cdr token))
+					 ")"))
+				(t
+				 (cdr token)))))
+		      (nth 1 addr) "")))
 	   (cond ((> (length phrase) 0) phrase)
-		 (comment (std11-comment-value-to-string comment))
-		 )
-	   ))))
+		 (comment (std11-comment-value-to-string comment)))))))
 
 ;;;###autoload
 (defun std11-msg-id-string (msg-id)
   "Return string from parsed MSG-ID of RFC 822."
-  (concat "<" (std11-addr-to-string (cdr msg-id)) ">")
-  )
+  (concat "<" (std11-addr-to-string (cdr msg-id)) ">"))
 
 ;;;###autoload
 (defun std11-fill-msg-id-list-string (string &optional column)
@@ -866,14 +878,12 @@
 		 (len (length str)))
 	    (setq lal (cdr ret))
 	    (if (> (+ len column) 76)
-		(setq dest (concat dest "\n " str)
+		(setq dest (cons str (cons "\n " dest))
 		      column (1+ len))
 	      (setq dest str
-		    column (+ column len))
-	      ))
-	(setq dest (concat dest (cdr (car lal)))
-	      lal (cdr lal))
-	))
+		    column (+ column len))))
+	(setq dest (cons (cdr (car lal)) dest)
+	      lal (cdr lal))))
     (while lal
       (let ((ret (std11-parse-msg-id lal)))
 	(if ret
@@ -881,15 +891,13 @@
 		   (len (1+ (length str))))
 	      (setq lal (cdr ret))
 	      (if (> (+ len column) 76)
-		  (setq dest (concat dest "\n " str)
+		  (setq dest (cons str (cons "\n " dest))
 			column len)
-		(setq dest (concat dest " " str)
-		      column (+ column len))
-		))
-	  (setq dest (concat dest (cdr (car lal)))
-		lal (cdr lal))
-	  )))
-    dest))
+		(setq dest (cons str (cons " " dest))
+		      column (+ column len))))
+	  (setq dest (cons (cdr (car lal)) dest)
+		lal (cdr lal)))))
+    (apply 'concat (nreverse dest))))
 
 
 ;;; @ parser with lexical analyzer
@@ -898,26 +906,22 @@
 ;;;###autoload
 (defun std11-parse-address-string (string)
   "Parse STRING as mail address."
-  (std11-parse-address (std11-lexical-analyze string))
-  )
+  (std11-parse-address (std11-lexical-analyze string)))
 
 ;;;###autoload
 (defun std11-parse-addresses-string (string)
   "Parse STRING as mail address list."
-  (std11-parse-addresses (std11-lexical-analyze string))
-  )
+  (std11-parse-addresses (std11-lexical-analyze string)))
 
 ;;;###autoload
 (defun std11-parse-msg-id-string (string)
   "Parse STRING as msg-id."
-  (std11-parse-msg-id (std11-lexical-analyze string))
-  )
+  (std11-parse-msg-id (std11-lexical-analyze string)))
 
 ;;;###autoload
 (defun std11-parse-msg-ids-string (string)
   "Parse STRING as `*(phrase / msg-id)'."
-  (std11-parse-msg-ids (std11-lexical-analyze string))
-  )
+  (std11-parse-msg-ids (std11-lexical-analyze string)))
 
 ;;;###autoload
 (defun std11-extract-address-components (string)
@@ -927,10 +931,8 @@
   (let* ((structure (car (std11-parse-address-string
 			  (std11-unfold-string string))))
          (phrase  (std11-full-name-string structure))
-         (address (std11-address-string structure))
-         )
-    (list phrase address)
-    ))
+         (address (std11-address-string structure)))
+    (list phrase address)))
 
 
 ;;; @ end
