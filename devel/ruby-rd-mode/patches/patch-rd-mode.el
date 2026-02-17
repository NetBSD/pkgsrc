$NetBSD: patch-rd-mode.el,v 1.1 2026/02/17 14:34:52 taca Exp $

* use rd-font-lock-keywords after defvar it.
* insert-buffer is for interactive use only.
* inser-string is obsolete since emacs 22.1.

--- rd-mode.el.orig	2026-02-17 14:12:15.501651638 +0000
+++ rd-mode.el
@@ -43,31 +43,6 @@
 (defvar rd-mode-hook nil
   "Hooks run when entering `rd-mode' major mode")
 
-(define-derived-mode rd-mode text-mode "RD"
-  "Major mode for RD editing.
-\\{rd-mode-map}"
-  (make-local-variable 'paragraph-separate)
-  (setq paragraph-separate "=+\\|\\++\\|[ \t\n\^L]*$")
-  (make-local-variable 'paragraph-start)
-  (setq paragraph-start "=+\\|\\++\\|[ \t\n\^L]")
-  (make-local-variable 'require-final-newline)  
-  (setq require-final-newline t)
-  (make-local-variable 'font-lock-defaults)
-  (setq font-lock-defaults '((rd-font-lock-keywords) t nil))
-  (make-local-variable 'font-lock-keywords)
-  (setq font-lock-keywords rd-font-lock-keywords)
-  (make-local-variable 'outline-regexp)
-  (setq outline-regexp "^\\(=+\\)")
-  (outline-minor-mode t)
-  (add-hook (make-local-variable 'write-contents-hooks) 'rd-strip-cr-on-top)
-  (add-hook (make-local-variable 'after-save-hook) 'rd-rehide-endline)
-  (rd-hide-other-block-all)
-  (rd-setup-keys)
-  (setq indent-tabs-mode nil)
-  (setq imenu-create-index-function 'rd-imenu-create-index)
-  (run-hooks 'rd-mode-hook)
-)
-
 (defvar rd-heading1-face 'font-lock-keyword-face)
 (defvar rd-heading2-face 'font-lock-type-face)
 (defvar rd-heading3-face 'font-lock-variable-name-face)
@@ -112,6 +87,31 @@
      0 rd-description-face)
    ))
 
+(define-derived-mode rd-mode text-mode "RD"
+  "Major mode for RD editing.
+\\{rd-mode-map}"
+  (make-local-variable 'paragraph-separate)
+  (setq paragraph-separate "=+\\|\\++\\|[ \t\n\^L]*$")
+  (make-local-variable 'paragraph-start)
+  (setq paragraph-start "=+\\|\\++\\|[ \t\n\^L]")
+  (make-local-variable 'require-final-newline)  
+  (setq require-final-newline t)
+  (make-local-variable 'font-lock-defaults)
+  (setq font-lock-defaults '((rd-font-lock-keywords) t nil))
+  (make-local-variable 'font-lock-keywords)
+  (setq font-lock-keywords rd-font-lock-keywords)
+  (make-local-variable 'outline-regexp)
+  (setq outline-regexp "^\\(=+\\)")
+  (outline-minor-mode t)
+  (add-hook (make-local-variable 'write-contents-hooks) 'rd-strip-cr-on-top)
+  (add-hook (make-local-variable 'after-save-hook) 'rd-rehide-endline)
+  (rd-hide-other-block-all)
+  (rd-setup-keys)
+  (setq indent-tabs-mode nil)
+  (setq imenu-create-index-function 'rd-imenu-create-index)
+  (run-hooks 'rd-mode-hook)
+)
+
 (defun rd-setup-keys ()
   (interactive)
   (define-key rd-mode-map "\t" 'rd-indent-line)
@@ -381,7 +381,7 @@
 
 (defun rd-insert-buffer-as-verbatim (buf)
   (interactive "bInsert buffer (verb): ")
-  (insert-buffer buf)
+  (insert-buffer-substring buf)
   (rd-cite-region (point)(mark)))
 
 
@@ -415,7 +415,7 @@
           )
     (end-of-line)
     (newline)
-    (if item (insert-string item) )
+    (if item (insert item))
     )
   )
 
