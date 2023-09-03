$NetBSD: patch-mel.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mel.el	2007-06-18 19:58:54.000000000 +0900
+++ ./mel.el	2023-08-31 08:29:38.601973143 +0900
@@ -1,4 +1,4 @@
-;;; mel.el --- A MIME encoding/decoding library.
+;;; mel.el --- A MIME encoding/decoding library.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1995,1996,1997,1998,1999,2000 Free Software Foundation, Inc.
 
@@ -27,6 +27,7 @@
 
 (require 'mime-def)
 (require 'alist)
+(require 'pces)
 
 (defcustom mime-encoding-list
   '("7bit" "8bit" "binary" "base64" "quoted-printable")
@@ -42,8 +43,7 @@
       (let (dest)
 	(mapatoms (lambda (sym)
 		    (or (eq sym nil)
-			(setq dest (cons (symbol-name sym) dest)))
-		    )
+			(setq dest (cons (symbol-name sym) dest))))
 		  (symbol-value (intern (format "%s-obarray" service))))
 	(let ((rest mel-encoding-module-alist)
 	      pair)
@@ -52,8 +52,7 @@
 	      (or (member key dest)
 		  (<= (length key) 1)
 		  (setq dest (cons key dest))))
-	    (setq rest (cdr rest)))
-	  )
+	    (setq rest (cdr rest))))
 	dest)
     mime-encoding-list))
 
@@ -73,6 +72,9 @@
   (mel-find-function-from-obarray
    (symbol-value (intern (format "%s-obarray" service))) encoding))
 
+(defun mel-prompt-for-encoding (&optional service)
+  (completing-read "Encoding: (default base64) "
+		   (mime-encoding-alist service) nil t nil nil "base64"))
 
 ;;; @ setting for modules
 ;;;
@@ -86,7 +88,7 @@
 
 (defun 8bit-write-decoded-region (start end filename)
   "Decode and write current region encoded by \"8bit\" into FILENAME."
-  (let ((coding-system-for-write 'raw-text)
+  (let ((coding-system-for-write 'no-conversion)
 	format-alist)
     (write-region start end filename)))
 
@@ -95,8 +97,8 @@
 			    'identity)
 (mel-define-method-function (mime-decode-string string (nil "8bit"))
 			    'identity)
-(mel-define-method mime-encode-region (start end (nil "8bit")))
-(mel-define-method mime-decode-region (start end (nil "8bit")))
+(mel-define-method mime-encode-region (_start _end (nil "8bit")))
+(mel-define-method mime-decode-region (_start _end (nil "8bit")))
 (mel-define-method-function (mime-insert-encoded-file filename (nil "8bit"))
 			    '8bit-insert-encoded-file)
 (mel-define-method-function (mime-write-decoded-region
@@ -112,6 +114,7 @@
 
 (defun binary-write-decoded-region (start end filename)
   "Decode and write current region encoded by \"binary\" into FILENAME."
+  (defvar jam-zcat-filename-list)
   (let ((coding-system-for-write 'binary)
 	jka-compr-compression-info-list jam-zcat-filename-list)
     (write-region start end filename)))
@@ -142,86 +145,134 @@
 			    'identity)
 (mel-define-method-function (mime-decode-string string (nil "binary"))
 			    'identity)
-(mel-define-method mime-encode-region (start end (nil "binary")))
-(mel-define-method mime-decode-region (start end (nil "binary")))
+(mel-define-method mime-encode-region (_start _end (nil "binary")))
+(mel-define-method mime-decode-region (_start _end (nil "binary")))
 (mel-define-method-function (mime-insert-encoded-file filename (nil "binary"))
 			    'binary-insert-encoded-file)
 (mel-define-method-function (mime-write-decoded-region
 			     start end filename (nil "binary"))
 			    'binary-write-decoded-region)
 
-(defvar mel-b-builtin
-   (and (fboundp 'base64-encode-string)
-        (subrp (symbol-function 'base64-encode-string))))
-
-(when mel-b-builtin
-  (mel-define-backend "base64")
-  (mel-define-method-function (mime-encode-string string (nil "base64"))
+(defvar mel-b-builtin t)
+
+(defcustom mel-b-builtin-garbage-strategy 'asis
+"When non-nil, base64 decoder functions handle non-encoded
+garbage.  When value is asis decoders keep garbage and when value
+is discard decoders delete garbage."
+  :group 'mime
+  :type '(choice (const :tag "Keep as is" asis)
+		 (const :tag "Discard" discard)
+		 (const :tag "Not handled" nil)))
+
+(defvar mel-b-builtin-encoded-line-regexp "^[A-Za-z0-9+/]+=*[\t ]*\r?\n?")
+
+(mel-define-backend "base64")
+(mel-define-method-function (mime-encode-string string (nil "base64"))
 			      'base64-encode-string)
-  (mel-define-method-function (mime-decode-string string (nil "base64"))
-			      'base64-decode-string)
-  (mel-define-method-function (mime-encode-region start end (nil "base64"))
-			      'base64-encode-region)
-  (mel-define-method-function (mime-decode-region start end (nil "base64"))
-			      'base64-decode-region)  
-  (mel-define-method mime-insert-encoded-file (filename (nil "base64"))
-    "Encode contents of file FILENAME to base64, and insert the result.
-It calls external base64 encoder specified by
-`base64-external-encoder'.  So you must install the program (maybe
-mmencode included in metamail or XEmacs package)."
-    (interactive "*fInsert encoded file: ")
-    (insert (base64-encode-string
-	     (with-temp-buffer
-	       (set-buffer-multibyte nil)
-	       (binary-insert-encoded-file filename)
-	       (buffer-string))))
-    (or (bolp) (insert ?\n)))
-  (mel-define-method mime-write-decoded-region (start end filename
-						      (nil "base64"))
-    "Decode the region from START to END and write out to FILENAME."
-    (interactive "*r\nFWrite decoded region to file: ")
-    (let ((str (buffer-substring start end)))
-      (with-temp-buffer
-	(insert str)
-	(base64-decode-region (point-min) (point-max))
-	(write-region-as-binary (point-min) (point-max) filename))))
-    
-  ;; (mel-define-method-function (encoded-text-encode-string string (nil "B"))
-  ;;                             'base64-encode-string)
-  (mel-define-method encoded-text-decode-string (string (nil "B"))
-    (if (string-match (eval-when-compile
-			(concat "\\`" B-encoded-text-regexp "\\'"))
-		      string)
+(defun mel-b-builtin-decode-string (string)
+  "Decode base64 encoded STRING with garbage handling.
+Garbage handling strategy is decided by `mel-b-builtin-garbage-strategy'.
+Return decoded string."
+  (if (null mel-b-builtin-garbage-strategy)
+      (base64-decode-string string)
+    (condition-case error
 	(base64-decode-string string)
-      (error "Invalid encoded-text %s" string)))
-  )
+      (error
+       (if (string-match mel-b-builtin-encoded-line-regexp string)
+	   (let ((start (match-beginning 0))
+		 end)
+	     (message "Base64 encoded string has garbage")
+	     (while (and (< (setq end (match-end 0)) (length string))
+			 (eq end
+			     (and (string-match
+				   mel-b-builtin-encoded-line-regexp
+				   string end)
+				  (match-beginning 0)))))
+	     (if (eq mel-b-builtin-garbage-strategy 'discard)
+		 (base64-decode-string (substring string start end))
+	       (concat (substring string 0 start)
+		       (base64-decode-string (substring string start end))
+		       (substring string end))))
+	 (signal (car error) (cdr error)))))))
+(mel-define-method-function (mime-decode-string string (nil "base64"))
+			    'mel-b-builtin-decode-string)
+(mel-define-method-function (mime-encode-region start end (nil "base64"))
+			    'base64-encode-region)
+(defun mel-b-builtin-decode-region (start end)
+  "Decode base64 encoded region between START and END with garbage handling.
+Garbage handling strategy is decided by `mel-b-builtin-garbage-strategy'."
+  (if (null mel-b-builtin-garbage-strategy)
+      (base64-decode-region start end)
+    (condition-case error
+	(base64-decode-region start end)
+      (error
+       (save-excursion
+	 (let ((start (min start end))
+	       (end (max start end))
+	       base64-start)
+	   (goto-char start)
+	   (if (re-search-forward mel-b-builtin-encoded-line-regexp end t)
+	       (progn
+		 (message "Base64 encoded region contains garbage")
+		 (setq base64-start (match-beginning 0))
+		 (while (eq (point)
+			    (and (re-search-forward
+				  mel-b-builtin-encoded-line-regexp end t)
+				 (match-beginning 0))))
+		 (when (eq mel-b-builtin-garbage-strategy 'discard)
+		   (delete-region (match-end 0) end))
+		 (base64-decode-region base64-start (point))
+		 (when (eq mel-b-builtin-garbage-strategy 'discard)
+		   (delete-region start base64-start)))
+	     (signal (car error) (cdr error)))))))))
+(mel-define-method-function (mime-decode-region start end (nil "base64"))
+			    'mel-b-builtin-decode-region)  
+(mel-define-method mime-insert-encoded-file (filename (nil "base64"))
+  "Encode contents of file FILENAME to base64, and insert the result."
+  (interactive "*fInsert encoded file: ")
+  ;; No need to make buffer unibyte if binary-insert-encoded-file only
+  ;; inserts single-byte characters.
+  (save-restriction
+    (narrow-to-region (point) (point))
+    (binary-insert-encoded-file filename)
+    (base64-encode-region (point-min) (point-max))
+    (goto-char (point-max)))
+  (or (bolp) (insert ?\n)))
+(mel-define-method mime-write-decoded-region (start end filename
+						    (nil "base64"))
+  "Decode the region from START to END and write out to FILENAME."
+  (interactive "*r\nFWrite decoded region to file: ")
+  (let ((buffer (current-buffer)))
+    (with-temp-buffer
+      (insert-buffer-substring buffer start end)
+      (mel-b-builtin-decode-region (point-min) (point-max))
+      (write-region-as-binary (point-min) (point-max) filename))))
+
+;; (mel-define-method-function (encoded-text-encode-string string (nil "B"))
+;;                             'base64-encode-string)
+(mel-define-method encoded-text-decode-string (string (nil "B"))
+  (if (string-match (eval-when-compile
+		      (concat "\\`" B-encoded-text-regexp "\\'"))
+		    string)
+      (base64-decode-string string)
+    (error "Invalid encoded-text %s" string)))
+
 
-(mel-use-module 'mel-b-el '("base64" "B"))
 (mel-use-module 'mel-q '("quoted-printable" "Q"))
 (mel-use-module 'mel-g '("x-gzip64"))
 (mel-use-module 'mel-u '("x-uue" "x-uuencode"))
 
-(defvar mel-b-ccl-module
-  (and (featurep 'mule)
-       (progn
-	 (require 'path-util)
-	 (module-installed-p 'mel-b-ccl))))
+(declare-function module-installed-p "path-util"
+		  (module &optional paths))
 
 (defvar mel-q-ccl-module
-  (and (featurep 'mule)
-       (progn
-	 (require 'path-util)
-	 (module-installed-p 'mel-q-ccl))))
-
-(when mel-b-ccl-module
-  (mel-use-module 'mel-b-ccl '("base64" "B")))
+  (progn
+    (require 'path-util)
+    (module-installed-p 'mel-q-ccl)))
 
 (when mel-q-ccl-module
   (mel-use-module 'mel-q-ccl '("quoted-printable" "Q")))
 
-(when base64-dl-module
-  (mel-use-module 'mel-b-dl '("base64" "B")))
-
 
 ;;; @ region
 ;;;
@@ -232,9 +283,7 @@
 ENCODING must be string."
   (interactive
    (list (region-beginning)(region-end)
-	 (completing-read "Encoding: "
-			  (mime-encoding-alist)
-			  nil t "base64")))
+	 (mel-prompt-for-encoding)))
   (funcall (mel-find-function 'mime-encode-region encoding) start end))
 
 
@@ -244,9 +293,7 @@
 ENCODING must be string."
   (interactive
    (list (region-beginning)(region-end)
-	 (completing-read "Encoding: "
-			  (mime-encoding-alist 'mime-decode-region)
-			  nil t "base64")))
+	 (mel-prompt-for-encoding 'mime-decode-region)))
   (funcall (mel-find-function 'mime-decode-region encoding)
 	   start end))
 
@@ -299,7 +346,7 @@
     (while (< i len)
       (setq chr (aref string i))
       (if (or (Q-encoding-printable-char-p chr mode)
-	      (eq chr ? ))
+	      (eq chr ?\s))
 	  (setq l (+ l 1))
 	(setq l (+ l 3)))
       (setq i (+ i 1)))
@@ -314,9 +361,7 @@
   "Insert file FILENAME encoded by ENCODING format."
   (interactive
    (list (read-file-name "Insert encoded file: ")
-	 (completing-read "Encoding: "
-			  (mime-encoding-alist)
-			  nil t "base64")))
+	 (mel-prompt-for-encoding)))
   (funcall (mel-find-function 'mime-insert-encoded-file encoding)
 	   filename))
 
@@ -328,9 +373,7 @@
   (interactive
    (list (region-beginning)(region-end)
 	 (read-file-name "Write decoded region to file: ")
-	 (completing-read "Encoding: "
-			  (mime-encoding-alist 'mime-write-decoded-region)
-			  nil t "base64")))
+	 (mel-prompt-for-encoding 'mime-write-decoded-region)))
   (funcall (mel-find-function 'mime-write-decoded-region encoding)
 	   start end filename))
 
