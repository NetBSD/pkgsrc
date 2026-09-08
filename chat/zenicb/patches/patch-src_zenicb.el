$NetBSD: patch-src_zenicb.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding
declare external variables
add code for /brick command
fix quoting in doc string
use with-current-buffer instead of save-excursion
remove xemacs compat to avoid undefined function
string-to-int has been replaced with string-to-number
fix argument count in function call

--- src/zenicb.el.orig	1998-07-19 22:37:51.000000000 +0000
+++ src/zenicb.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;;
 ;;;
 ;;; zenicb.el --- Waste time on International Citizen's Band (ZenICB client)
@@ -82,7 +84,7 @@
   "*Beep when I get a /beep if t.")
 
 (defvar zenicb-alert nil
-  "*Beep when I get a /m if set to 'personal.  If set to 'all, beep also
+  "*Beep when I get a /m if set to `personal'.  If set to `all', beep also
 when I see a public message.")
 
 (defvar zenicb-send-lines t
@@ -115,6 +117,7 @@ line separately.")
 
 (defvar zenicb-partialline)
 (defvar zenicb-process)
+(defvar zenicb-time-last-event)  ; defined in zenicb-stamp.el
 (defvar zenicb-debug-mainloop nil)
 (defvar zenicb-debug-commands nil)
 (defvar zenicb-bug-address "fn-zenicb@hungry.com")
@@ -143,6 +146,7 @@ line separately.")
 ;(defvar zenicb-command-bcount-hook 'zenicb-command-bcount) ; byte count
 (defvar zenicb-command-beep-hook 'zenicb-command-beep) ; beep someone
 (defvar zenicb-command-boot-hook 'zenicb-command-boot) ; boot off group
+(defvar zenicb-command-brick-hook 'zenicb-command-brick) ; brick someone
 (defvar zenicb-command-cancel-hook 'zenicb-command-cancel) ; cancel invite
 (defvar zenicb-command-drop-hook 'zenicb-command-drop) ; drop nick
 (defvar zenicb-command-echo-hook 'zenicb-command-echo) ; echoback
@@ -211,6 +215,9 @@ line separately.")
 	      (if (not zenicb-process)
 		  ()
 		(set-marker (process-mark zenicb-process) (point-max))
+		(if (fboundp 'set-buffer-multibyte) (set-buffer-multibyte nil))
+		(if (fboundp 'set-process-coding-system)
+		    (set-process-coding-system zenicb-process 'binary 'binary))
 		(set-process-buffer zenicb-process zenicb-buffer)
 		(set-process-filter zenicb-process 'zenicb-filter)
 		(set-process-sentinel zenicb-process 'zenicb-sentinel)
@@ -261,8 +268,7 @@ line separately.")
 ;;; Handle closing connection to server
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 (defun zenicb-sentinel (proc sentinel)
-  (save-excursion
-    (set-buffer (process-buffer proc))
+  (with-current-buffer (process-buffer proc)
     (setq zenicb-active nil)))
 
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
@@ -279,8 +285,12 @@ line separately.")
       (set-buffer orig-buffer)
       (store-match-data data))))
 
+(if (not (fboundp 'char-int))
+    (defun char-int (a)
+      a))
+
 (defun zenicb-parselines (proc string)
-  (while (let ((length (+ (aref string 0))))
+  (while (let ((length (+ (char-int (aref string 0)))))
 	   (and (> (length string) length)
 		(let ((type (aref string 1))
 		      (line (substring string 2 length)))
@@ -434,17 +444,13 @@ line separately.")
   (interactive)
   (if (= (point) (process-mark zenicb-process))
       (zenicb-send-msg-last-rec)
-    (if (string-match "Xemacs" emacs-version)
-	(insert last-command-char)
-      (insert (this-command-keys)))))
+    (insert (this-command-keys))))
 
 (defun zenicb-self-insert-or-send-msg-last-sent ()
   (interactive)
   (if (= (point) (process-mark zenicb-process))
       (zenicb-send-msg-last-sent)
-    (if (string-match "Xemacs" emacs-version)
-	(insert last-command-char)
-      (insert (this-command-keys)))))
+    (insert (this-command-keys))))
 
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ;;; Insert strings into the ZenICB buffer.
@@ -598,10 +604,10 @@ list of hooks to run in HOOK, then nothing is done.  S
 (defun zenicb-convert-date (seconds)
   (let (millions units high low)
     (if (string-match "\\(......\\)$" seconds)
-	(setq millions (string-to-int (substring seconds 0 (match-beginning 1)))
-	      units (string-to-int (substring seconds (match-beginning 1))))
+	(setq millions (string-to-number (substring seconds 0 (match-beginning 1)))
+	      units (string-to-number (substring seconds (match-beginning 1))))
       (setq millions 0
-	    units (string-to-int seconds)))
+	    units (string-to-number seconds)))
     (setq high (+ (* millions 15) (/ (* millions 265) 1024) (/ units 65536))
 	  low (+ (% (+ (* (% millions 4) 16384) (* millions 576)) 65536)
 		 (% units 65536)))
@@ -617,7 +623,7 @@ list of hooks to run in HOOK, then nothing is done.  S
 ;; Display the idle time in a nice format.
 ;;
 (defun zenicb-convert-time (seconds)
-  (let ((units (string-to-int seconds)))
+  (let ((units (string-to-number seconds)))
     (cond
      ((< units 90) "-")
      (t (format "%dm" (/ (+ units 30) 60))))))
@@ -753,7 +759,13 @@ list of hooks to run in HOOK, then nothing is done.  S
 ;;
 (defun zenicb-command-boot (proc parsedcmd)
   (zenicb-send-string proc ?h (concat "boot\C-a" (cdr parsedcmd))))
+;; 
+;; Brick someone
+;; /brick [victim]
 ;;
+(defun zenicb-command-brick (proc parsedcmd)
+  (zenicb-send-string proc ?h (concat "brick\C-a" (cdr parsedcmd))))
+;;
 ;; Cancel an invitation
 ;;
 (defun zenicb-command-cancel (proc parsedcmd)
@@ -863,7 +875,7 @@ list of hooks to run in HOOK, then nothing is done.  S
 ;; verbose - other people can't beep you, and you are informed of their attempt
 ;;
 (defun zenicb-command-nobeep (proc parsedcmd)
-  (zenicb-send-string proc ?h "nobeep\C-a" (cdr parsedcmd)))
+  (zenicb-send-string proc ?h (concat "nobeep\C-a" (cdr parsedcmd))))
 ;; Set autoregister
 ;; /nosecure
 ;;
