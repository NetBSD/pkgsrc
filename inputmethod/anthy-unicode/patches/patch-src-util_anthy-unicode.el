$NetBSD: patch-src-util_anthy-unicode.el,v 1.1 2026/08/28 11:30:25 wiz Exp $

Fix the coding system on the pipe to the agent, keep each buffer's saved undo
list to itself, and let the file work on the older Emacs versions pkgsrc
still carries.

The first two are not about old Emacs at all.  anthy-agent-unicode speaks
UTF-8 and nothing else, but nothing sets the coding system on the pipe, so
Emacs uses default-process-coding-system, which follows the user's locale.
Under a ja_JP.eucJP or ja_JP.SJIS locale the conversion comes back as
mojibake on Emacs 22.3 through 31.1 alike.  utf-8-unix is set explicitly;
the -unix matters, because plain utf-8 leaves the end-of-line undecided and
the decoding side settles on utf-8-dos.

anthy stops undo while a preedit is open and puts the buffer's undo list
aside until the text is committed.  The flag saying it did so is
anthy-deflocalvar, that is per buffer, but the list itself was an undeclared
global shared by every buffer, so opening a preedit in a second buffer
overwrote what the first one had put aside, and the first buffer got the
second one's undo history when it committed.

anthy-restore-undo-list is dead: the two places that set the variable it
reads and its one call site are all commented out, as they already were in
anthy 9100h.  It is commented out too rather than deleted, the same way its
callers are, so that taking the semicolons off brings it back.

The rest is the older Emacs versions.  Each name is picked once at load time
and called through a variable:

  set-face-underline              Emacs 20 has only set-face-underline-p, and
                                  until 24.3 that is the current spelling.
                                  The call is at top level, so on Emacs 20 the
                                  file does not load and only 4 of the 6 .elc
                                  files get built.
  set-process-query-on-exit-flag  new in 22.1.  It is called from
                                  anthy-check-agent, so Emacs 21 and XEmacs
                                  build and load and then die at the first
                                  conversion.
  deactivate-input-method,
  deactivate-current-input-method-function
                                  renamed from inactivate-* in 24.3.  Emacs 22
                                  and 23 convert and then cannot leave the
                                  input method: void-function nil, because the
                                  variable they read stays nil.
  mapc                            new in Emacs 21; 9100h used mapcar here.

Writing the old name in an else branch would work, but a current Emacs then
reports it as not known to be defined, so this goes through a variable.  The
XEmacs-only names in anthy-last-command-char get the same treatment, and a
lexical-binding cookie is added, which together take Emacs 24 and later from
nine byte-compile warnings to none.

Emacs 20, 21 and XEmacs 21.4 have no utf-8 coding system that covers CJK, so
Mule-UCS is required there, inside condition-case so that nothing happens
where it is not installed and nothing at all happens from Emacs 22 on.
XEmacs takes a coding system object rather than a symbol, so the value goes
through find-coding-system there.

Measured on NetBSD 11.0/amd64 with Emacs 20.7, 21.4, 22.3, 23.4, 24.5, 25.3,
26.3, 27.2, 28.2, 29.4, 30.2, 31.1 and XEmacs 21.4.25, typing nihongo,
converting, committing and switching the input method off again.

Sent upstream as fujiwarat/anthy-unicode#21; this can be dropped once a
release includes it.

--- src-util/anthy-unicode.el.orig
+++ src-util/anthy-unicode.el
@@ -1,4 +1,4 @@
-;;; anthy-unicode.el -- Anthy
+;;; anthy-unicode.el -- Anthy  -*- lexical-binding: nil -*-
 
 ;; Copyright (C) 2001 - 2007 KMC(Kyoto University Micro Computer Club)
 ;; Copyright (C) 2021 Takao Fujiwara <takao.fujiwara1@gmail.com>
@@ -70,12 +70,73 @@
 (defvar anthy-agent-unicode-command-list '("anthy-agent-unicode")
   "anthy-agent-unicodeのPATH 名")
 
+;; XEmacs にしか無い名前。anthy-xemacs が真のときしか呼ばないが、直接書くと
+;; GNU Emacs の byte compiler が "not known to be defined" と言う。
+(defvar anthy-event-matches-key-specifier-p-function
+  'event-matches-key-specifier-p)
+(defvar anthy-event-to-character-function 'event-to-character)
+(defvar anthy-char-to-int-function 'char-to-int)
+
+;; Emacs 22.1 から。Emacs 20/21 と XEmacs は process-kill-without-query。
+;; どちらも第二引数 nil で「終了時に問い合わせない」の意味になる。
+(defvar anthy-set-process-no-query-function
+  (if (fboundp 'set-process-query-on-exit-flag)
+      'set-process-query-on-exit-flag
+    'process-kill-without-query))
+
+;; Emacs 24.3 で inactivate-* から改名された。Emacs 20 から 23 と XEmacs は
+;; 旧名しか持たない。
+(defvar anthy-deactivate-input-method-function
+  (if (fboundp 'deactivate-input-method)
+      'deactivate-input-method
+    'inactivate-input-method))
+(defvar anthy-deactivate-current-input-method-variable
+  (if (boundp 'deactivate-current-input-method-function)
+      'deactivate-current-input-method-function
+    'inactivate-current-input-method-function))
+
+;; Emacs 21 から。Emacs 20 と XEmacs は set-face-underline-p のみ。24.3 までは
+;; -p の方が正で、こちらが obsolete。ここは top level なので、無い版では load
+;; そのものが失敗する。
+(defvar anthy-set-face-underline-function
+  (if (fboundp 'set-face-underline)
+      'set-face-underline
+    'set-face-underline-p))
+
+;; Emacs 21 から。Emacs 20 には無く、anthy 9100h はこの行で mapcar だった。
+;; 返り値は捨てるので、どちらでも同じ。
+(defvar anthy-mapc-function
+  (if (fboundp 'mapc)
+      'mapc
+    'mapcar))
+
+;; Emacs 20 と 21 の utf-8 は CJK を含まない (20 には utf-8 そのものが無い)。
+;; XEmacs 21.4 にも utf-8 が無い。agent は UTF-8 でしか話さないので、
+;; Mule-UCS があれば載せる。
+(if (and (or (featurep 'xemacs)
+	     (< emacs-major-version 22))
+	 (not (featurep 'un-define)))
+    (condition-case nil
+	(require 'un-define)
+      (error nil)))
+
+;; XEmacs の coding-system-p は symbol ではなく coding system オブジェクトを
+;; 取るので、find-coding-system を通す。
+(defvar anthy-agent-coding-system
+  (if (featurep 'xemacs)
+      (and (fboundp 'find-coding-system)
+	   (find-coding-system 'utf-8-unix))
+    (and (coding-system-p 'utf-8-unix)
+	 'utf-8-unix)))
+
 ;; face
 (defvar anthy-highlight-face nil)
 (defvar anthy-underline-face nil)
 (copy-face 'highlight 'anthy-highlight-face)
+;(if (not (featurep 'xemacs))
+;    (set-face-underline 'anthy-highlight-face t))
 (if (not (featurep 'xemacs))
-    (set-face-underline 'anthy-highlight-face t))
+    (funcall anthy-set-face-underline-function 'anthy-highlight-face t))
 (copy-face 'underline 'anthy-underline-face)
 
 ;;
@@ -202,6 +263,9 @@
 (anthy-deflocalvar anthy-current-rkmap "hiragana")
 ; undo
 (anthy-deflocalvar anthy-buffer-undo-list-saved nil)
+;; 待避した undo list そのもの。旗だけ buffer local で中身が global だったので、
+;; buffer を二つ使うと片方の履歴がもう片方のもので上書きされていた。
+(anthy-deflocalvar anthy-buffer-undo-list nil)
 
 ;;
 (defvar anthy-wide-space "　" "スペースを押した時に出て来る文字")
@@ -250,7 +314,8 @@
 	(delete-region start (+ start len))
 	(goto-char start)))
   (setq anthy-preedit "")
-  (mapc 'delete-overlay anthy-preedit-overlays)
+;  (mapc 'delete-overlay anthy-preedit-overlays)
+  (funcall anthy-mapc-function 'delete-overlay anthy-preedit-overlays)
   (setq anthy-preedit-overlays nil))
 
 (defun anthy-select-face-by-attr (attr)
@@ -546,14 +611,17 @@
 	  (char-to-string ch)
 	nil))))
 
-(defun anthy-restore-undo-list (commit-str)
-  (let* ((len (length commit-str))
-	 (beginning (point))
-	 (end (+ beginning len)))
-    (setq buffer-undo-list
-	  (cons (cons beginning end)
-		(cons nil anthy-saved-buffer-undo-list)))
-	 ))
+;; 呼び出し側も、anthy-saved-buffer-undo-list を設定する二箇所も、元から
+;; コメントアウトされている。この関数だけが生きていて、呼べば void-variable に
+;; なる。同じように閉じておく。
+;(defun anthy-restore-undo-list (commit-str)
+;  (let* ((len (length commit-str))
+;	 (beginning (point))
+;	 (end (+ beginning len)))
+;    (setq buffer-undo-list
+;	  (cons (cons beginning end)
+;		(cons nil anthy-saved-buffer-undo-list)))
+;	 ))
 
 (defun anthy-proc-agent-reply (repl)
   (let*
@@ -752,7 +820,13 @@
 	(if anthy-agent-unicode-process
 	    (kill-process anthy-agent-unicode-process))
 	(setq anthy-agent-unicode-process proc)
-	(set-process-query-on-exit-flag proc nil)
+;	(set-process-query-on-exit-flag proc nil)
+	(funcall anthy-set-process-no-query-function proc nil)
+;	(if (coding-system-p 'utf-8-unix)
+;	    (set-process-coding-system proc 'utf-8-unix 'utf-8-unix))
+	(if anthy-agent-coding-system
+	    (set-process-coding-system proc anthy-agent-coding-system
+				       anthy-agent-coding-system))
 ;;	(if anthy-xemacs
 ;;	    (if (coding-system-p (find-coding-system 'euc-japan))
 ;;		(set-process-coding-system proc 'euc-japan 'euc-japan))
@@ -871,7 +945,9 @@
 ;; leim の activate
 ;;
 (defun anthy-unicode-leim-activate (&optional name)
-  (setq deactivate-current-input-method-function 'anthy-unicode-leim-inactivate)
+;  (setq deactivate-current-input-method-function 'anthy-unicode-leim-inactivate)
+  (set anthy-deactivate-current-input-method-variable
+       'anthy-unicode-leim-inactivate)
   (setq anthy-leim-active-p t)
   (anthy-update-mode)
   (when (eq (selected-window) (minibuffer-window))
@@ -881,7 +957,8 @@
 ;; emacsのバグ避けらしいです
 ;;
 (defun anthy-unicode-leim-exit-from-minibuffer ()
-  (deactivate-input-method)
+;  (deactivate-input-method)
+  (funcall anthy-deactivate-input-method-function)
   (when (<= (minibuffer-depth) 1)
     (remove-hook 'minibuffer-exit-hook 'anthy-unicode-leim-exit-from-minibuffer)))
 
@@ -891,14 +968,24 @@
 ;;
 (defun anthy-last-command-char ()
   "最後の入力イベントを返す。XEmacs では int に変換する"
+;  (if anthy-xemacs
+;      (let ((event last-command-event))
+;	(cond
+;	 ((event-matches-key-specifier-p event 'left)      2)
+;	 ((event-matches-key-specifier-p event 'right)     6)
+;	 ((event-matches-key-specifier-p event 'backspace) 8)
+;	 (t
+;	  (char-to-int (event-to-character event)))))
+;    last-command-event))
   (if anthy-xemacs
       (let ((event last-command-event))
 	(cond
-	 ((event-matches-key-specifier-p event 'left)      2)
-	 ((event-matches-key-specifier-p event 'right)     6)
-	 ((event-matches-key-specifier-p event 'backspace) 8)
+	 ((funcall anthy-event-matches-key-specifier-p-function event 'left)      2)
+	 ((funcall anthy-event-matches-key-specifier-p-function event 'right)     6)
+	 ((funcall anthy-event-matches-key-specifier-p-function event 'backspace) 8)
 	 (t
-	  (char-to-int (event-to-character event)))))
+	  (funcall anthy-char-to-int-function
+		   (funcall anthy-event-to-character-function event)))))
     last-command-event))
 
 ;;
