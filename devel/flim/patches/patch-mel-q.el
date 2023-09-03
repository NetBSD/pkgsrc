$NetBSD: patch-mel-q.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mel-q.el	2005-07-06 11:09:04.000000000 +0900
+++ ./mel-q.el	2023-08-31 08:29:38.599294148 +0900
@@ -1,4 +1,4 @@
-;;; mel-q.el --- Quoted-Printable encoder/decoder.
+;;; mel-q.el --- Quoted-Printable encoder/decoder.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1995,96,97,98,99,2000,2001 Free Software Foundation, Inc.
 
@@ -26,12 +26,7 @@
 ;;; Code:
 
 (require 'mime-def)
-(require 'path-util)
-(eval-when-compile
-  ;; XXX: should provide char-list instead of string-to-char-list.
-  ;; XXx: and also the macro `as-binary-process' should be provided
-  ;; XXx: by the module "pces" which will be loaded by way of "poem".
-  (require 'poem))
+(require 'pces)
 
 
 ;;; @ Quoted-Printable encoder
@@ -40,7 +35,8 @@
 (defsubst quoted-printable-quote-char (character)
   (concat
    "="
-   (char-to-string (aref quoted-printable-hex-chars (ash character -4)))
+   (char-to-string (aref quoted-printable-hex-chars
+			 (ash (logand character 255) -4)))
    (char-to-string (aref quoted-printable-hex-chars (logand character 15)))))
 
 (defun quoted-printable-internal-encode-region (start end)
@@ -58,9 +54,9 @@
 	    (forward-char)
 	    (setq col 0))
 	   (t
-	    (setq chr (char-after (point)))
+	    (setq chr (logand (following-char) 255))
 	    (cond
-	     ((and (memq chr '(?  ?\t))	; encode WSP char before CRLF.
+	     ((and (memq chr '(?\s ?\t))	; encode WSP char before CRLF.
 		   (eq (char-after (1+ (point))) ?\n))
 	      (forward-char)
 	      (insert "=\n")
@@ -71,7 +67,7 @@
 		   (eq (char-after (1+  (point))) ?r)
 		   (eq (char-after (+ 2 (point))) ?o)
 		   (eq (char-after (+ 3 (point))) ?m)
-		   (eq (char-after (+ 4 (point))) ? ))
+		   (eq (char-after (+ 4 (point))) ?\s))
 	      (delete-region (point)(1+ (point)))
 	      (insert "=46")		; moved to ?r.
 	      (forward-char 4)		; skip "rom ".
@@ -112,9 +108,11 @@
 	(replace-match "")))))
 
 
+(declare-function exec-installed-p "path-util"
+		  (file &optional paths suffixes))
+
 (defvar quoted-printable-internal-encoding-limit
-  (if (and (featurep 'xemacs)(featurep 'mule))
-      0
+  (progn
     (require 'path-util)
     (if (exec-installed-p "mmencode")
 	1000
@@ -173,8 +171,20 @@
 (defsubst quoted-printable-hex-char-to-num (chr)
   (cond ((<= ?a chr) (+ (- chr ?a) 10))
 	((<= ?A chr) (+ (- chr ?A) 10))
-	((<= ?0 chr) (- chr ?0))
-	))
+	((<= ?0 chr) (- chr ?0))))
+
+(eval-and-compile
+  (if (eval-when-compile
+	(> (string-to-char (string-as-multibyte "\200")) 128))
+      (defsubst quoted-printable-num-to-raw-byte-char (chr)
+	(if (and chr
+		 (> chr 127))
+	    (logior chr
+		    (eval-when-compile
+		      (- (string-to-char (string-as-multibyte "\200")) 128)))
+	  chr))
+    (defsubst quoted-printable-num-to-raw-byte-char (chr)
+      chr)))
 
 (defun quoted-printable-internal-decode-region (start end)
   (save-excursion
@@ -186,20 +196,21 @@
 	 ((eolp)
 	  ;; unfold soft line break.
 	  (delete-region (1- (point))(1+ (point))))
-	 ((and (memq (char-after (point))
+	 ((and (memq (following-char)
 		     (eval-when-compile
 		       ;; XXX: should provide char-list instead.
-		       (string-to-char-list quoted-printable-hex-chars)))
+		       (string-to-list quoted-printable-hex-chars)))
 	       (memq (char-after (1+ (point)))
 		     (eval-when-compile
 		       ;; XXX: should provide char-list instead.
-		       (string-to-char-list quoted-printable-hex-chars))))
+		       (string-to-list quoted-printable-hex-chars))))
 	  ;; encoded char.
 	  (insert
 	   (prog1
-	       (logior
-		(ash (quoted-printable-hex-char-to-num (char-after (point))) 4)
-		(quoted-printable-hex-char-to-num (char-after (1+ (point)))))
+	       (quoted-printable-num-to-raw-byte-char
+		(logior
+		 (ash (quoted-printable-hex-char-to-num (following-char)) 4)
+		 (quoted-printable-hex-char-to-num (char-after (1+ (point))))))
 	     (delete-region (1- (point))(+ 2 (point))))))
 	 (t
 	  ;; invalid encoding.
@@ -295,33 +306,33 @@
 `phrase'."
   (let ((specials (cdr (or (assq mode q-encoding-special-chars-alist)
 			   (assq 'phrase q-encoding-special-chars-alist)))))
-    (mapconcat (function
-		(lambda (chr)
-		  (cond ((eq chr ? ) "_")
-			((or (< chr 32) (< 126 chr)
-			     (memq chr specials))
-			 (quoted-printable-quote-char chr))
-			(t
-			 (char-to-string chr)))))
+    (mapconcat (lambda (chr)
+		 (cond ((eq chr ?\s) "_")
+		       ((or (< chr 32) (< 126 chr)
+			    (memq chr specials))
+			(quoted-printable-quote-char chr))
+		       (t
+			(char-to-string chr))))
 	       string "")))
 
 (defun q-encoding-decode-string (string)
   "Decode STRING which is encoded in Q-encoding and return the result."
   (let (q h l)
-    (mapconcat (function
-		(lambda (chr)
-		  (cond ((eq chr ?_) " ")
-			((eq chr ?=)
-			 (setq q t)
-			 "")
-			(q (setq h (quoted-printable-hex-char-to-num chr))
-			   (setq q nil)
-			   "")
-			(h (setq l (quoted-printable-hex-char-to-num chr))
-			   (prog1
-			       (char-to-string (logior (ash h 4) l))
-			     (setq h nil)))
-			(t (char-to-string chr)))))
+    (mapconcat (lambda (chr)
+		 (cond ((eq chr ?_) " ")
+		       ((eq chr ?=)
+			(setq q t)
+			"")
+		       (q (setq h (quoted-printable-hex-char-to-num chr))
+			  (setq q nil)
+			  "")
+		       (h (setq l (quoted-printable-hex-char-to-num chr))
+			  (prog1
+			      (char-to-string
+			       (quoted-printable-num-to-raw-byte-char
+				(logior (ash h 4) l)))
+			    (setq h nil)))
+		       (t (char-to-string chr))))
 	       string "")))
 
 (mel-define-method-function (encoded-text-encode-string string (nil "Q"))
