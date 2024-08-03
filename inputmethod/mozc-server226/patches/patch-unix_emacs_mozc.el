$NetBSD: patch-unix_emacs_mozc.el,v 1.1 2024/08/03 14:49:34 tsutsui Exp $

- pull upstream changes to avoid warnings on newer emacs versions
  https://github.com/google/mozc/commits/master/src/unix/emacs/mozc.el
- appease various "Warning: docstring has wrong usage of unescaped
  single quotes" messages

--- unix/emacs/mozc.el.orig	2021-02-15 05:04:34.000000000 +0000
+++ unix/emacs/mozc.el
@@ -3,6 +3,7 @@
 ;; Copyright 2010-2021, Google Inc. All rights reserved.
 
 ;; Keywords: mule, multilingual, input method
+;; Package-Requires: ((emacs "24.3"))
 
 ;; Redistribution and use in source and binary forms, with or without
 ;; modification, are permitted provided that the following conditions are
@@ -120,7 +121,7 @@
 
 
 (eval-when-compile
-  (require 'cl))
+  (require 'cl-lib))
 
 
 
@@ -220,10 +221,10 @@ the server side.  Clients, including moz
 have many user settings on their side.
 
 You can change a variety of user settings through a GUI command
-line tool 'mozc_tool' which must be shipped with the mozc server.
+line tool `mozc_tool' which must be shipped with the mozc server.
 The command line tool may be installed to /usr/lib/mozc or /usr/lib
 directory.
-You need a command line option '--mode=config_dialog' as the
+You need a command line option `--mode=config_dialog' as the
 following.
 
   $ /usr/lib/mozc/mozc_tool --mode=config_dialog
@@ -391,41 +392,41 @@ Key code and symbols are renamed so that
   (let ((basic-type (event-basic-type event))
         (modifiers (event-modifiers event)))
     ;; Rename special keys to ones the helper process understands.
-    (let ((key (case basic-type
+    (let ((key (cl-case basic-type
                  (?\b 'backspace)
                  (?\s 'space)
                  (?\d 'backspace)
-                 ('eisu-toggle 'eisu)
-                 ('hiragana-katakana 'kana)
-                 ('next 'pagedown)
-                 ('prior 'pageup)
-                 ('kp-decimal 'decimal)
-                 ('kp-0 'numpad0)
-                 ('kp-1 'numpad1)
-                 ('kp-2 'numpad2)
-                 ('kp-3 'numpad3)
-                 ('kp-4 'numpad4)
-                 ('kp-5 'numpad5)
-                 ('kp-6 'numpad6)
-                 ('kp-7 'numpad7)
-                 ('kp-8 'numpad8)
-                 ('kp-9 'numpad9)
-                 ('kp-delete 'delete)  ; .
-                 ('kp-insert 'insert)  ; 0
-                 ('kp-end 'end)        ; 1
-                 ('kp-down 'down)      ; 2
-                 ('kp-next 'pagedown)  ; 3
-                 ('kp-left 'left)      ; 4
-                 ('kp-begin 'clear)    ; 5
-                 ('kp-right 'right)    ; 6
-                 ('kp-home 'home)      ; 7
-                 ('kp-up 'up)          ; 8
-                 ('kp-prior 'pageup)   ; 9
-                 ('kp-add 'add)
-                 ('kp-subtract 'subtract)
-                 ('kp-multiply 'multiply)
-                 ('kp-divide 'divide)
-                 ('kp-enter 'enter)
+                 (eisu-toggle 'eisu)
+                 (hiragana-katakana 'kana)
+                 (next 'pagedown)
+                 (prior 'pageup)
+                 (kp-decimal 'decimal)
+                 (kp-0 'numpad0)
+                 (kp-1 'numpad1)
+                 (kp-2 'numpad2)
+                 (kp-3 'numpad3)
+                 (kp-4 'numpad4)
+                 (kp-5 'numpad5)
+                 (kp-6 'numpad6)
+                 (kp-7 'numpad7)
+                 (kp-8 'numpad8)
+                 (kp-9 'numpad9)
+                 (kp-delete 'delete)  ; .
+                 (kp-insert 'insert)  ; 0
+                 (kp-end 'end)        ; 1
+                 (kp-down 'down)      ; 2
+                 (kp-next 'pagedown)  ; 3
+                 (kp-left 'left)      ; 4
+                 (kp-begin 'clear)    ; 5
+                 (kp-right 'right)    ; 6
+                 (kp-home 'home)      ; 7
+                 (kp-up 'up)          ; 8
+                 (kp-prior 'pageup)   ; 9
+                 (kp-add 'add)
+                 (kp-subtract 'subtract)
+                 (kp-multiply 'multiply)
+                 (kp-divide 'divide)
+                 (kp-enter 'enter)
                  (t basic-type))))
       (cond
        ;; kana + shift + rest => katakana + rest
@@ -589,11 +590,11 @@ at the previous point when it's on a ter
 of a wrapped line, this function returns the position information exactly
 at the point.
 
-For example, suppose the following line in the buffer and the point is at 'd'
-\(the beginning of character 'd'),
+For example, suppose the following line in the buffer and the point is at \='d'
+\(the beginning of character \='d'),
     ....... abc[wrap]
     def...
-\(cdr (posn-actual-col-row (posn-at-point AT_D))) is the same number at 'c' on
+\(cdr (posn-actual-col-row (posn-at-point AT_D))) is the same number at \='c' on
 a terminal.
 
 In a word, this function is a fixed version of `posn-at-point'."
@@ -661,7 +662,7 @@ This hack could be moved to mozc-posn-at
   "Return the width of WINDOW in pixel.
 WINDOW defaults to the selected window."
   (let ((rect (window-inside-pixel-edges window)))
-    (- (third rect) (first rect))))
+    (- (nth 2 rect) (nth 0 rect))))
 
 (defun mozc-header-line-height ()
   "Return the height of the header line.
@@ -823,7 +824,7 @@ Non-nil SEPARATOR is inserted between ea
          (mapconcat
           (lambda (segment)
             (apply #'propertize (mozc-protobuf-get segment 'value)
-                   (case (mozc-protobuf-get segment 'annotation)
+                   (cl-case (mozc-protobuf-get segment 'annotation)
                      (highlight
                       '(face mozc-preedit-selected-face))
                      (t
@@ -874,8 +875,8 @@ Symbol `overlay' and `echo-area' are cur
 
 overlay   - Shows a candidate window in box style close to the point.
 echo-area - Shows a candidate list in the echo area."
-  :type '(choice (symbol :tag "overlaid box style" 'overlay)
-                 (symbol :tag "single line in echo area" 'echo-area))
+  :type '(choice (symbol :tag "overlaid box style" overlay)
+                 (symbol :tag "single line in echo area" echo-area))
   :group 'mozc)
 
 (defvar mozc-candidate-dispatch-table
@@ -1254,7 +1255,7 @@ The function returns non-nil on success,
                 ;; work as expected if the point is off the screen.
                 (vertical-motion -1)
                 (scroll-up 1))
-              (incf scrolled-lines))
+              (cl-incf scrolled-lines))
             (let ((content (car contents)))
               (let ((left-text (car content))
                     (right-text (cadr content))
@@ -1425,7 +1426,7 @@ conversion status in each buffer.")
 Using this ID, the program recognizes which response corresponds to
 a certain request avoiding cross talk.
 
-This sequence number is called 'event-id' in the helper process,
+This sequence number is called `event-id' in the helper process,
 which doesn't have to be a *sequence* number.")
 
 (defun mozc-session-create (&optional forcep)
@@ -1465,8 +1466,8 @@ create a new session."
 The resulting protocol buffer, which is represented as alist, is
 mozc::commands::Output in C++.  Return nil on error.
 
-KEY-LIST is a list of a key code (97 = ?a), key symbols ('space, 'shift,
-'meta and so on), and/or a string which represents the preedit to be
+KEY-LIST is a list of a key code (97 = ?a), key symbols (\='space, \='shift,
+\='meta and so on), and/or a string which represents the preedit to be
 inserted (\"\\u3061\")."
   (when (mozc-session-create)
     (apply #'mozc-session-execute-command 'SendKey key-list)))
@@ -1640,7 +1641,7 @@ version           -- should be version s
   "Invalidate variable `mozc-helper-process' if PROC is not running normally.
 Current implementation throws MESSAGE away."
   (when (eq proc mozc-helper-process)
-    (case (process-status proc)
+    (cl-case (process-status proc)
       (run)  ; Do nothing.
       (t  ; Invalidate mozc-helper-process.
        (setq mozc-helper-process nil)))))
@@ -1689,8 +1690,8 @@ A returned object is alist on success.  
       (condition-case nil
           (let ((obj-index
                  (read-from-string response)))  ; may signal end-of-file.
-            (if (mozc-string-match-p "^[ \t\n\v\f\r]*$"
-                                     (substring response (cdr obj-index)))
+            (if (string-match-p "^[ \t\n\v\f\r]*$"
+                                (substring response (cdr obj-index)))
                 ;; Only white spaces remain.
                 (car obj-index)
               ;; Unexpected characters remain at the end.
@@ -1722,10 +1723,10 @@ If timed out, return nil."
 Return a found value, or nil if not found.
 KEY and KEYS can be a symbol or integer.
 
-For example, (mozc-protobuf-get protobuf 'key1 2 'key3) is equivalent to
-  (cdr (assq 'key3
+For example, (mozc-protobuf-get protobuf \='key1 2 \='key3) is equivalent to
+  (cdr (assq \='key3
              (nth 2
-                  (cdr (assq 'key1
+                  (cdr (assq \='key1
                              protobuf)))))
 except for error handling.  This is similar to
   protobuf.key1(2).key3()
@@ -1753,16 +1754,6 @@ and LIST.  The default value of N is 1."
       (setcdr pre-boundary nil)  ; Drop the rest of list.
       (cons list post-boundary))))
 
-(defun mozc-string-match-p (regexp string &optional start)
-  "Same as `string-match' except this function never change the match data.
-REGEXP, STRING and optional START are the same as for `string-match'.
-
-This function is equivalent to `string-match-p', which is available since
-Emacs 23."
-  (let ((inhibit-changing-match-data t))
-    (string-match regexp string start)))
-
-
 
 ;;;; Custom keymap
 
@@ -1783,56 +1774,54 @@ The preedit method is taken from the ser
                       (symbol-value keymap-name))))
     (and (hash-table-p keymap) keymap)))
 
+;; Utility functions to configure keymaps
 ;;;###autoload
-(defun mozc-keymap-make-keymap ()
-  "Create a new empty keymap and return it."
-  (make-hash-table :size 128 :test #'eq))
+(progn  ; Put the function definitions into the autoload file.
+  (defun mozc-keymap-make-keymap ()
+    "Create a new empty keymap and return it."
+    (make-hash-table :size 128 :test #'eq))
 
-;;;###autoload
-(defun mozc-keymap-make-keymap-from-flat-list (list)
-  "Create a new keymap and fill it with entries in LIST.
+  (defun mozc-keymap-make-keymap-from-flat-list (list)
+    "Create a new keymap and fill it with entries in LIST.
 LIST must be a flat list which contains keys and mapped strings alternately."
-  (mozc-keymap-fill-entries-from-flat-list (mozc-keymap-make-keymap) list))
+    (mozc-keymap-fill-entries-from-flat-list (mozc-keymap-make-keymap) list))
 
-;;;###autoload
-(defun mozc-keymap-fill-entries-from-flat-list (keymap list)
-  "Fill KEYMAP with entries in LIST and return KEYMAP.
+  (defun mozc-keymap-fill-entries-from-flat-list (keymap list)
+    "Fill KEYMAP with entries in LIST and return KEYMAP.
 KEYMAP must be a key table from keycodes to mapped strings.
 LIST must be a flat list which contains keys and mapped strings alternately."
-  (if (not (and (car list) (cadr list)))
-      keymap  ; Return the keymap.
-    (mozc-keymap-put-entry keymap (car list) (cadr list))
-    (mozc-keymap-fill-entries-from-flat-list keymap (cddr list))))
+    (if (not (and (car list) (cadr list)))
+        keymap  ; Return the keymap.
+      (mozc-keymap-put-entry keymap (car list) (cadr list))
+      (mozc-keymap-fill-entries-from-flat-list keymap (cddr list))))
 
-;;;###autoload
-(defun mozc-keymap-get-entry (keymap keycode &optional default)
-  "Return a mapped string if the entry for the keycode exists.
+  (defun mozc-keymap-get-entry (keymap keycode &optional default)
+    "Return a mapped string if the entry for the keycode exists.
 Otherwise, the default value, which must be a string.
 KEYMAP must be a key table from keycodes to mapped strings.
 KEYCODE must be an integer representing a key code to look up.
 DEFAULT is returned if it's a string and no entry for KEYCODE is found."
-  (let ((value (and (hash-table-p keymap)
-                    (gethash keycode keymap default))))
-    (and (stringp value) value)))
+    (let ((value (and (hash-table-p keymap)
+                      (gethash keycode keymap default))))
+      (and (stringp value) value)))
 
-;;;###autoload
-(defun mozc-keymap-put-entry (keymap keycode mapped-string)
-  "Add a new key mapping to a keymap.
+  (defun mozc-keymap-put-entry (keymap keycode mapped-string)
+    "Add a new key mapping to a keymap.
 KEYMAP must be a key table from keycodes to mapped strings.
 KEYCODE must be an integer representing a key code.
 MAPPED-STRING must be a string representing a preedit string to be inserted."
-  (when (and (hash-table-p keymap)
-             (integerp keycode) (stringp mapped-string))
-    (puthash keycode mapped-string keymap)
-    (cons keycode mapped-string)))
+    (when (and (hash-table-p keymap)
+               (integerp keycode) (stringp mapped-string))
+      (puthash keycode mapped-string keymap)
+      (cons keycode mapped-string)))
 
-;;;###autoload
-(defun mozc-keymap-remove-entry (keymap keycode)
-  "Remove an entry from a keymap.  If no entry for keycode exists, do nothing.
+  (defun mozc-keymap-remove-entry (keymap keycode)
+    "Remove an entry from a keymap.  If no entry for keycode exists, do nothing.
 KEYMAP must be a key table from keycodes to mapped strings.
 KEYCODE must be an integer representing a key code to remove."
-  (when (hash-table-p keymap)
-    (remhash keycode keymap)))
+    (when (hash-table-p keymap)
+      (remhash keycode keymap)))
+  )
 
 ;;;###autoload
 (defvar mozc-keymap-kana-106jp
@@ -1961,46 +1950,41 @@ CONDITIONS is a list of error conditions
 
 (require 'mule nil t)
 
-(defun mozc-leim-activate (input-method)
-  "Activate function `mozc-mode' via LEIM.
-INPUT-METHOD is not used."
-  (let ((new 'deactivate-current-input-method-function)
-        (old 'inactivate-current-input-method-function))
-    ;; `inactivate-current-input-method-function' is deprecated
-    ;; since Emacs 24.3.
-    (set (if (boundp new) new old) #'mozc-leim-deactivate))
-  (mozc-mode t))
-
-(defun mozc-leim-deactivate ()
-  "Deactivate function `mozc-mode' via LEIM."
-  (mozc-mode nil))
-
-(defcustom mozc-leim-title "[Mozc]"
-  "Mode line string shown when function `mozc-mode' is enabled.
+;;;###autoload
+(progn  ; Put the program code into the autoload file.
+  (defcustom mozc-leim-title "[Mozc]"
+    "Mode line string shown when function `mozc-mode' is enabled.
 This indicator is not shown when you don't use LEIM."
-  :type '(choice (const :tag "No indicator" nil)
-                 (string :tag "Show an indicator"))
-  :group 'mozc)
+    :type '(choice (const :tag "No indicator" nil)
+                   (string :tag "Show an indicator"))
+    :group 'mozc)
 
-(defun mozc-leim-register-input-method ()
-  "Register function `mozc-mode' as an input method of LEIM.
+  (defun mozc-leim-register-input-method ()
+    "Register function `mozc-mode' as an input method of LEIM.
 Do nothing if LEIM is not available."
-  (if (fboundp #'register-input-method)
-      (register-input-method
-       "japanese-mozc"
-       "Japanese"
-       #'mozc-leim-activate
-       mozc-leim-title
-       "Japanese input method with Mozc.")))
-
-;; Register mozc-mode as an input method after the init file has been read
-;; so the user has a chance to specify `mozc-leim-title' in the init file
-;; after loading this file.
-(add-hook 'emacs-startup-hook #'mozc-leim-register-input-method)
-;; In the case that `emacs-startup-hook' has already been run, especially
-;; when the user loads this file interactively, register immediately.
-(mozc-leim-register-input-method)
-
+    (if (fboundp #'register-input-method)
+        (register-input-method
+         "japanese-mozc"
+         "Japanese"
+         (lambda (input-method)
+           ;; `inactivate-current-input-method-function' is deprecated
+           ;; since Emacs 24.3.
+           (let ((new 'deactivate-current-input-method-function)
+                 (old 'inactivate-current-input-method-function))
+             (set (if (boundp new) new old)
+                  (lambda () (mozc-mode nil))))
+           (mozc-mode t))
+         mozc-leim-title
+         "Japanese input method with Mozc.")))
+
+  ;; Register mozc-mode as an input method after the init file has been read
+  ;; so the user has a chance to specify `mozc-leim-title' in the init file
+  ;; after loading this file.
+  (add-hook 'emacs-startup-hook #'mozc-leim-register-input-method)
+  ;; In the case that `emacs-startup-hook' has already been run, especially
+  ;; when the user loads this file interactively, register immediately.
+  (mozc-leim-register-input-method)
+  )
 
 
 (provide 'mozc)
