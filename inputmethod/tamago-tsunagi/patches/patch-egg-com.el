$NetBSD: patch-egg-com.el,v 1.1 2023/09/09 13:04:29 mef Exp $

make-coding-system is obsolete function:
thanks: 
https://raw.githubusercontent.com/qbilinux/qbilinux/x86_dev/qbilinux/04_xapps/emacs.txz/tamago_tsunagi/emacs28-make-coding-system.patch
or FreeBSD ports

diff -ru tamago-tsunagi-5.0.7.1/egg-com.el tamago-tsunagi-5.0.7.1/egg-com.el
--- tamago-tsunagi-5.0.7.1/egg-com.el	2015-02-02 22:22:57.000000000 -0000
+++ ./egg-com.el	2023-06-25 19:12:38.798416049 -0000
@@ -97,131 +97,34 @@
     (prog1 (- (point) pos)
       (goto-char pos))))
 
-(if (and (fboundp 'make-coding-system)
-         (null (get 'make-coding-system 'byte-obsolete-info)))
-;; since Emacs 23.1, make-coding-system has been marked as obsolete. 
-    (eval-and-compile
-	(define-ccl-program ccl-decode-fixed-euc-jp
-	  `(2
-	    ((r2 = ,(charset-id 'japanese-jisx0208))
-	     (r3 = ,(charset-id 'japanese-jisx0212))
-	     (r4 = ,(charset-id 'katakana-jisx0201))
-	     (read r0)
-	     (loop
-	      (read r1)
-	      (if (r0 < ?\x80)
-		  ((r0 = r1)
-		   (if (r1 < ?\x80)
-		       (write-read-repeat r0))
-		   (write r4)
-		   (write-read-repeat r0))
-		((if (r1 > ?\x80)
-		     ((write r2 r0)
-		      (r0 = r1)
-		      (write-read-repeat r0))
-		   ((write r3 r0)
-		    (r0 = (r1 | ?\x80))
-		    (write-read-repeat r0)))))))))
-
-	(define-ccl-program ccl-encode-fixed-euc-jp
-	  `(2
-	    ((read r0)
-	     (loop
-	      (if (r0 == ,(charset-id 'latin-jisx0201))                   ; Unify
-		  ((read r0)
-		   (r0 &= ?\x7f)))
-	      (if (r0 < ?\x80)                                            ;G0
-		  ((write 0)
-		   (write-read-repeat r0)))
-	      (r6 = (r0 == ,(charset-id 'japanese-jisx0208)))
-	      (r6 |= (r0 == ,(charset-id 'japanese-jisx0208-1978)))
-	      (if r6                                                      ;G1
-		  ((read r0)
-		   (write r0)
-		   (read r0)
-		   (write-read-repeat r0)))
-	      (if (r0 == ,(charset-id 'katakana-jisx0201))                ;G2
-		  ((read r0)
-		   (write 0)
-		   (write-read-repeat r0)))
-	      (if (r0 == ,(charset-id 'japanese-jisx0212))                ;G3
-		  ((read r0)
-		   (write r0)
-		   (read r0)
-		   (r0 &= ?\x7f)
-		   (write-read-repeat r0)))
-	      (read r0)
-	      (repeat)))))
-	(make-coding-system 'fixed-euc-jp 4 ?W "Coding System for fixed EUC Japanese"
-			    (cons ccl-decode-fixed-euc-jp ccl-encode-fixed-euc-jp))
-	)
-    (eval-and-compile
-    ;; since Emacs 23.1, make-coding-system has been marked as obsolete. 
-    ;; From Handa-san. [mule-ja : No.09414]
-    (define-charset 'fixed-euc-jp
-      "Fixed EUC Japanese"
-      :dimension 2
-      :superset '(ascii
-		  (katakana-jisx0201 . #x80)
-		  (japanese-jisx0208 . #x8080)
-		  (japanese-jisx0212 . #x8000)))
-    (define-coding-system 'fixed-euc-jp
-      "Coding System for fixed EUC Japanese"
-      :mnemonic ?W
-      :coding-type 'charset
-      :charset-list '(fixed-euc-jp))
-    )
+(eval-and-compile
+  (define-charset 'fixed-euc-jp
+    "Fixed EUC Japanese"
+    :dimension 2
+    :superset '(ascii
+		(katakana-jisx0201 . #x80)
+		(japanese-jisx0208 . #x8080)
+		(japanese-jisx0212 . #x8000)))
+  (define-coding-system 'fixed-euc-jp
+    "Coding System for fixed EUC Japanese"
+    :mnemonic ?W
+    :coding-type 'charset
+    :charset-list '(fixed-euc-jp))
   )
 
 ;; Korean
-
-(if (and (fboundp 'make-coding-system)
-         (null (get 'make-coding-system 'byte-obsolete-info)))
-;; since Emacs 23.1, make-coding-system has been marked as obsolete. 
-    (eval-and-compile
-(define-ccl-program ccl-decode-fixed-euc-kr
-  `(2
-    ((r2 = ,(charset-id 'korean-ksc5601))
-     (read r0)
-     (loop
-      (read r1)
-      (if (r0 < ?\x80)
-	  (r0 = r1 & ?\x7f)
-	((write r2 r0)
-	 (r0 = r1 | ?\x80)))
-      (write-read-repeat r0)))))
-
-(define-ccl-program ccl-encode-fixed-euc-kr
-  `(2
-    ((read r0)
-     (loop
-      (if (r0 < ?\x80)
-	  ((write 0)
-	   (write-read-repeat r0)))
-      (if (r0 == ,(charset-id 'korean-ksc5601))
-	  ((read r0)
-	   (write r0)
-	   (read r0)
-	   (write-read-repeat r0)))
-      (read r0)
-      (repeat)))))
-(make-coding-system 'fixed-euc-kr 4 ?W "Coding System for fixed EUC Korean"
-		    (cons ccl-decode-fixed-euc-kr ccl-encode-fixed-euc-kr)))
-    (eval-and-compile
-    ;; since Emacs 23.1, make-coding-system has been marked as obsolete. 
-    (define-charset 'fixed-euc-kr
-      "Fixed EUC Korean"
-      :dimension 2
-      :superset '(ascii
-		  (korean-ksc5601 . #x8080)))
-    (define-coding-system 'fixed-euc-kr
-      "Coding System for fixed EUC Korean"
-      :mnemonic ?W
-      :coding-type 'charset
-      :charset-list '(fixed-euc-kr))
-    )
-)
-
+(eval-and-compile
+  (define-charset 'fixed-euc-kr
+    "Fixed EUC Korean"
+    :dimension 2
+    :superset '(ascii
+		(korean-ksc5601 . #x8080)))
+  (define-coding-system 'fixed-euc-kr
+    "Coding System for fixed EUC Korean"
+    :mnemonic ?W
+    :coding-type 'charset
+    :charset-list '(fixed-euc-kr))
+  )
 
 ;; Chinese
 ;;
@@ -685,29 +588,33 @@
 (defun post-read-decode-euc-zy-tw (len)
   (post-read-decode-fixed-euc-china len 'tw t))
 
-(make-coding-system 'fixed-euc-py-cn 0 ?W
-		    "Coding System for fixed EUC Chinese-gb2312")
+(define-coding-system
+  'fixed-euc-py-cn "Coding System for fixed EUC Chinese-gb2312"
+  :mnemonic ?W :coding-type 'emacs-mule)
 (coding-system-put 'fixed-euc-py-cn
 		   'pre-write-conversion 'pre-write-encode-euc-cn)
 (coding-system-put 'fixed-euc-py-cn
 		   'post-read-conversion 'post-read-decode-euc-py-cn)
 
-(make-coding-system 'fixed-euc-zy-cn 0 ?W
-		    "Coding System for fixed EUC Chinese-gb2312")
+(define-coding-system
+  'fixed-euc-zy-cn "Coding System for fixed EUC Chinese-gb2312"
+  :mnemonic ?W :coding-type 'emacs-mule)
 (coding-system-put 'fixed-euc-zy-cn
 		   'pre-write-conversion 'pre-write-encode-euc-cn)
 (coding-system-put 'fixed-euc-zy-cn
 		   'post-read-conversion 'post-read-decode-euc-zy-cn)
 
-(make-coding-system 'fixed-euc-py-tw 0 ?W
-		    "Coding System for fixed EUC Chinese-cns11643")
+(define-coding-system
+  'fixed-euc-py-tw "Coding System for fixed EUC Chinese-cns11643"
+  :mnemonic ?W :coding-type 'emacs-mule)
 (coding-system-put 'fixed-euc-py-tw
 		   'pre-write-conversion 'pre-write-encode-euc-tw)
 (coding-system-put 'fixed-euc-py-tw
 		   'post-read-conversion 'post-read-decode-euc-py-tw)
 
-(make-coding-system 'fixed-euc-zy-tw 0 ?W
-		    "Coding System for fixed EUC Chinese-cns11643")
+(define-coding-system
+  'fixed-euc-zy-tw "Coding System for fixed EUC Chinese-cns11643"
+  :mnemonic ?W :coding-type 'emacs-mule)
 (coding-system-put 'fixed-euc-zy-tw
 		   'pre-write-conversion 'pre-write-encode-euc-tw)
 (coding-system-put 'fixed-euc-zy-tw
@@ -733,8 +640,9 @@
 	   (r0 = 0)))
       (write-read-repeat r0))))))
 
-(make-coding-system 'egg-binary 4 ?W "Coding System for binary data"
-		    (cons ccl-decode-egg-binary ccl-encode-egg-binary))
+(define-coding-system 'egg-binary "Coding System for binary data"
+  :mnemonic ?W :coding-type 'ccl :ccl-decoder ccl-decode-egg-binary
+  :ccl-encoder ccl-encode-egg-binary)
 
 
 (defun comm-format-u32c (uint32c)
