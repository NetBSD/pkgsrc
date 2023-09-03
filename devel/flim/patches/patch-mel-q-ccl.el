$NetBSD: patch-mel-q-ccl.el,v 1.1 2023/09/03 14:58:38 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/mel-q-ccl.el	2006-06-13 00:10:02.000000000 +0900
+++ ./mel-q-ccl.el	2023-08-31 08:29:38.597755481 +0900
@@ -1,4 +1,4 @@
-;;; mel-q-ccl.el --- Quoted-Printable encoder/decoder using CCL.
+;;; mel-q-ccl.el --- Quoted-Printable encoder/decoder using CCL.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1998,1999 Tanaka Akira
 
@@ -67,7 +67,7 @@
       0   1   2   3   4   5   6   7   8   9 nil nil nil nil nil nil
     nil  10  11  12  13  14  15 nil nil nil nil nil nil nil nil nil
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
-    nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
+    nil  10  11  12  13  14  15 nil nil nil nil nil nil nil nil nil
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
@@ -79,12 +79,12 @@
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil))
 
 (defconst mel-ccl-16-to-256-table
-  (mapcar 'char-int "0123456789ABCDEF"))
+  (string-to-list "0123456789ABCDEF"))
 
 (defconst mel-ccl-high-table
   (vconcat
    (mapcar
-    (lambda (v) (nth (lsh v -4) mel-ccl-16-to-256-table))
+    (lambda (v) (nth (ash v -4) mel-ccl-16-to-256-table))
     mel-ccl-256-table)))
 
 (defconst mel-ccl-low-table
@@ -95,23 +95,21 @@
 
 (defconst mel-ccl-u-raw
   (mapcar
-   'char-int
+   'identity
    "0123456789\
 ABCDEFGHIJKLMNOPQRSTUVWXYZ\
 abcdefghijklmnopqrstuvwxyz\
 !@#$%&'()*+,-./:;<>@[\\]^`{|}~"))
 
 (defconst mel-ccl-c-raw
-  (mapcar
-   'char-int
+  (string-to-list
    "0123456789\
 ABCDEFGHIJKLMNOPQRSTUVWXYZ\
 abcdefghijklmnopqrstuvwxyz\
 !@#$%&'*+,-./:;<>@[]^`{|}~"))
 
 (defconst mel-ccl-p-raw
-  (mapcar
-   'char-int
+  (string-to-list
    "0123456789\
 ABCDEFGHIJKLMNOPQRSTUVWXYZ\
 abcdefghijklmnopqrstuvwxyz\
@@ -133,9 +131,7 @@
    enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc
    enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc
    enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc
-   enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc])
-
-)
+   enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc]))
 
 
 ;;; @ CCL programs
@@ -146,14 +142,15 @@
 (define-ccl-program mel-ccl-decode-q
   `(1
     ((loop
-      (read-branch
-       r0
+      (read r0)
+      (branch
+       (r0 & 255)
        ,@(mapcar
           (lambda (r0)
             (cond
-             ((= r0 (char-int ?_))
-              `(write-repeat ? ))
-             ((= r0 (char-int ?=))
+             ((= r0 ?_)
+              `(write-repeat ?\s))
+             ((= r0 ?=)
               `((loop
                  (read-branch
                   r1
@@ -172,7 +169,7 @@
                            `((write r0 ,(vconcat
                                          (mapcar
                                           (lambda (r0)
-                                            (logior (lsh r0 4) v))
+                                            (logior (ash r0 4) v))
                                           mel-ccl-16-table)))
                              (break))
                          '(repeat)))
@@ -188,7 +185,9 @@
   `(3
     (loop
      (loop
-      (read-branch
+      (read r0)
+      (r0 &= 255)
+      (branch
        r0
        ,@(mapcar
           (lambda (r0)
@@ -214,9 +213,7 @@
 	    (if (or (= r1 32) (member r1 raw))
 		'((r0 += 1) (repeat))
 	      '((r0 += 3) (repeat))))
-	  mel-ccl-256-table))))))
-
-)
+	  mel-ccl-256-table)))))))
 
 (define-ccl-program mel-ccl-encode-uq
   (mel-ccl-encode-q-generic mel-ccl-u-raw))
@@ -243,9 +240,7 @@
     (unless p
       (setq p (cons branch (length eof-block-branches))
 	    eof-block-branches (cons p eof-block-branches)))
-    `(,eof-block-reg = ,(cdr p))))
-
-)
+    `(,eof-block-reg = ,(cdr p)))))
 
 (eval-when-compile
 
@@ -265,9 +260,7 @@
     `(,(mel-ccl-set-eof-block crlf-eof)
       (read-if (,reg == ?\n)
 	,succ
-	,crlf-fail))))
-
-)
+	,crlf-fail)))))
 
 (eval-when-compile
 
@@ -281,12 +274,10 @@
 	(after-wsp 'r5)
 	(column 'r6)
 	(type 'r3)
-	(current 'r0)
 	(type-raw 0)
 	(type-enc 1)
 	(type-wsp 2)
-	(type-brk 3)
-	)
+	(type-brk 3))
     `(4
       ((,column = 0)
        (,after-wsp = 0)
@@ -295,13 +286,14 @@
        (loop	; invariant: column <= 75
 	(loop
 	 (loop
+	  (r0 &= 255)
 	  (branch
 	   r0
 	   ,@(mapcar
 	      (lambda (r0)
 		(let ((tmp (aref mel-ccl-qp-table r0)))
 		  (cond
-		   ((eq r0 (char-int ?F))
+		   ((eq r0 ?F)
 		    `(if (,column == 0)
 			 (,(mel-ccl-set-eof-block '((write "F") (end)))
 			  (read-if (r0 == ?r)
@@ -310,7 +302,7 @@
 			       (,(mel-ccl-set-eof-block '((write "Fro") (end)))
 				(read-if (r0 == ?m)
 				  (,(mel-ccl-set-eof-block '((write "From") (end)))
-				   (read-if (r0 == ? )
+				   (read-if (r0 == ?\s)
 				     ((,column = 7)
 				      (,after-wsp = 1)
 				      ,(mel-ccl-set-eof-block '((write "From=20") (end)))
@@ -326,7 +318,7 @@
 			     (write-repeat "F"))))
 		       ((,type = ,type-raw) (break)) ; RAW
 		       ))
-		   ((eq r0 (char-int ?.))
+		   ((eq r0 ?.)
 		    `(if (,column == 0)
 			 ,(mel-ccl-try-to-read-crlf
 			    input-crlf 'r0
@@ -359,8 +351,7 @@
 		   ((eq tmp 'cr) `((,type = ,(if input-crlf type-brk type-enc))
 				   (break)))
 		   ((eq tmp 'lf) `((,type = ,(if input-crlf type-enc type-brk))
-				   (break)))
-		   )))
+				   (break))))))
 	      mel-ccl-256-table)))
 	 ;; r0:type{raw,enc,wsp,brk}
 	 (branch
@@ -580,8 +571,7 @@
 		 (,column = 0)
 		 ,@(if output-crlf '((write ?\r)) '())
 		 ,(mel-ccl-set-eof-block `(end))
-		 (write-read-repeat r0)))
-	     )))))
+		 (write-read-repeat r0))))))))
       (branch
        ,eof-block-reg
        ,@(reverse (mapcar 'car eof-block-branches))))))
@@ -591,13 +581,13 @@
     ((read r0)
      (loop
       (branch
-       r0
+       (r0 & 255)
        ,@(mapcar
           (lambda (r0)
             (let ((tmp (aref mel-ccl-qp-table r0)))
               (cond
                ((eq tmp 'raw) `(write-read-repeat r0))
-               ((eq tmp 'wsp) (if (eq r0 (char-int ? ))
+               ((eq tmp 'wsp) (if (eq r0 ?\s)
                                   `(r1 = 1)
                                 `(r1 = 0)))
                ((eq tmp 'cr)
@@ -634,12 +624,12 @@
                       '((write ?\r)
                         (write-read-repeat r0))
                     '(write-read-repeat r0))))
-               ((eq r0 (char-int ?=))
+               ((eq r0 ?=)
                 ;; r0='='
                 `((read r0)
                   ;; '=' r0
                   (r1 = (r0 == ?\t))
-                  (if ((r0 == ? ) | r1)
+                  (if ((r0 == ?\s) | r1)
                       ;; '=' r0:[\t ]
                       ;; Skip transport-padding.
                       ;; It should check CR LF after
@@ -647,7 +637,7 @@
                       (loop
                        (read-if (r0 == ?\t)
                                 (repeat)
-                                (if (r0 == ? )
+                                (if (r0 == ?\s)
                                     (repeat)
                                   (break)))))
                   ;; '=' [\t ]* r0:[^\t ]
@@ -656,7 +646,7 @@
                    ,@(mapcar
                       (lambda (r0)
                         (cond
-                         ((eq r0 (char-int ?\r))
+                         ((eq r0 ?\r)
                           (if input-crlf
                               ;; '=' [\t ]* r0='\r'
                               `((read r0)
@@ -677,7 +667,7 @@
                             `((write ?=)
                               (read r0)
                               (repeat))))
-                         ((eq r0 (char-int ?\n))
+                         ((eq r0 ?\n)
                           (if input-crlf
                               ;; '=' [\t ]* r0='\n'
                               ;; invalid input (bare LF found) -> 
@@ -713,7 +703,7 @@
                               ,(vconcat
                                 (mapcar
                                  (lambda (r0)
-                                   (logior (lsh r0 4) tmp))
+                                   (logior (ash r0 4) tmp))
                                  mel-ccl-16-table)))
                           ;; '=' [\t ]* r1:r0:[0-9A-F] r2:[^0-9A-F]
                           ;; invalid input
@@ -729,9 +719,8 @@
                (t
                 ;; r0:[^\t\r -~]
                 ;; invalid character found.
-                ;; -> ignore.
-                `((read r0)
-                  (repeat))))))
+                ;; -> output as is.
+                `((write-read-repeat r0))))))
           mel-ccl-256-table))
       ;; r1[0]:[\t ]
       (loop
@@ -756,7 +745,7 @@
 				(break))))))
 		     `((read r0)
 		       (if (r0 == ?\ )
-			   (,reg |= ,(lsh 1 bit))
+			   (,reg |= ,(ash 1 bit))
 			 (if (r0 != ?\t)
 			     ((r6 = ,(+ (* regnum 28) bit))
 			      (break)))))))
@@ -800,17 +789,14 @@
 	       'append
 	       (mapcar
 		(lambda (bit)
-		  `((if (,reg & ,(lsh 1 bit))
+		  `((if (,reg & ,(ash 1 bit))
 			(write ?\ )
 		      (write ?\t))
 		    (if (r6 == ,(+ (* regnum 28) bit 1))
 			(repeat))))
 		mel-ccl-28-table))))
 	  '(0 1 2 3 4)))
-      (repeat)
-      ))))
-
-)
+      (repeat))))))
 
 (define-ccl-program mel-ccl-encode-quoted-printable-crlf-crlf
   (mel-ccl-encode-quoted-printable-generic t t))
@@ -902,7 +888,7 @@
      (decode-coding-string
       (with-temp-buffer
 	(set-buffer-multibyte nil)
-	(insert-file-contents-as-binary filename)
+	(insert-file-contents-literally filename)
 	(buffer-string))
       'mel-ccl-quoted-printable-lf-lf-rev)))
 
@@ -914,8 +900,7 @@
    'quoted-printable-ccl-encode-region)
   (mel-define-method-function
    (mime-insert-encoded-file filename (nil "quoted-printable"))
-   'quoted-printable-ccl-insert-encoded-file)
-  )
+   'quoted-printable-ccl-insert-encoded-file))
 
 (defun quoted-printable-ccl-decode-string (string)
   "Decode quoted-printable encoded STRING."
@@ -932,7 +917,11 @@
 (defun quoted-printable-ccl-write-decoded-region (start end filename)
   "Decode quoted-printable encoded current region and write out to FILENAME."
   (interactive "*r\nFWrite decoded region to file: ")
-  (let ((coding-system-for-write 'mel-ccl-quoted-printable-lf-lf-rev)
+  (defvar jam-zcat-filename-list)
+  (let ((coding-system-for-write
+	 (if (coding-system-p 'mel-ccl-quoted-printable-lf-lf-rev-unix)
+	     'mel-ccl-quoted-printable-lf-lf-rev-unix
+	   'mel-ccl-quoted-printable-lf-lf-rev))
 	jka-compr-compression-info-list jam-zcat-filename-list)
     (write-region start end filename)))
 
@@ -967,19 +956,16 @@
    string
    'mel-ccl-uq-rev))
 
-(unless (featurep 'xemacs)
-  (defun q-encoding-ccl-encoded-length (string &optional mode)
-    (let ((status [nil nil nil nil nil nil nil nil nil]))
-      (fillarray status nil)		; XXX: Is this necessary?
-      (ccl-execute-on-string
-       (cond
-	((eq mode 'text) 'mel-ccl-count-uq)
-	((eq mode 'comment) 'mel-ccl-count-cq)
-	(t 'mel-ccl-count-pq))
-       status
-       string)
-      (aref status 0)))
-  )
+(defun q-encoding-ccl-encoded-length (string &optional mode)
+  (let ((status (make-vector 9 nil)))
+    (ccl-execute-on-string
+     (cond
+      ((eq mode 'text) 'mel-ccl-count-uq)
+      ((eq mode 'comment) 'mel-ccl-count-cq)
+      (t 'mel-ccl-count-pq))
+     status
+     string)
+    (aref status 0)))
 
 (mel-define-method-function (encoded-text-encode-string string (nil "Q"))
 			    'q-encoding-ccl-encode-string)
