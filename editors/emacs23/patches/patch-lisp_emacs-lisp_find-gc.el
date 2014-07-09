$NetBSD: patch-lisp_emacs-lisp_find-gc.el,v 1.1 2014/07/09 03:18:44 taca Exp $

Fix for CVE-2014-3422.

--- lisp/emacs-lisp/find-gc.el.orig	2012-01-11 12:35:01.000000000 +0000
+++ lisp/emacs-lisp/find-gc.el
@@ -24,14 +24,15 @@
 
 ;; Produce in find-gc-unsafe-list the set of all functions that may invoke GC.
 ;; This expects the Emacs sources to live in find-gc-source-directory.
-;; It creates a temporary working directory /tmp/esrc.
 
 ;;; Code:
 
 (defvar find-gc-unsafe-list nil
   "The list of unsafe functions is placed here by `find-gc-unsafe'.")
 
-(defvar find-gc-source-directory)
+(defvar find-gc-source-directory
+  (file-name-as-directory (expand-file-name "src" source-directory))
+  "Directory containing Emacs C sources.")
 
 (defvar find-gc-subrs-callers nil
   "Alist of users of subrs, from GC testing.
@@ -60,14 +61,14 @@ Each entry has the form (FUNCTION . FUNC
     "indent.c" "search.c" "regex.c" "undo.c"
     "alloc.c" "data.c" "doc.c" "editfns.c"
     "callint.c" "eval.c" "fns.c" "print.c" "lread.c"
-    "abbrev.c" "syntax.c" "unexec.c"
+    "syntax.c" "unexec.c"
     "bytecode.c" "process.c" "callproc.c" "doprnt.c"
-    "x11term.c" "x11fns.c"))
+    "xterm.c" "xfns.c"))
 
 
 (defun find-gc-unsafe ()
   "Return a list of unsafe functions--that is, which can call GC.
-Also store it in `find-gc-unsafe'."
+Also store it in `find-gc-unsafe-list'."
   (trace-call-tree nil)
   (trace-use-tree)
   (find-unsafe-funcs 'Fgarbage_collect)
@@ -103,47 +104,38 @@ Also store it in `find-gc-unsafe'."
 
 
 
-(defun trace-call-tree (&optional already-setup)
+(defun trace-call-tree (&optional ignored)
   (message "Setting up directories...")
-  (or already-setup
-      (progn
-	;; Gee, wouldn't a built-in "system" function be handy here.
-	(call-process "csh" nil nil nil "-c" "rm -rf /tmp/esrc")
-	(call-process "csh" nil nil nil "-c" "mkdir /tmp/esrc")
-	(call-process "csh" nil nil nil "-c"
-		      (format "ln -s %s/*.[ch] /tmp/esrc"
-			      find-gc-source-directory))))
-  (with-current-buffer (get-buffer-create "*Trace Call Tree*")
-    (setq find-gc-subrs-called nil)
-    (let ((case-fold-search nil)
-	  (files find-gc-source-files)
-	  name entry)
-      (while files
-	(message "Compiling %s..." (car files))
-	(call-process "csh" nil nil nil "-c"
-		      (format "gcc -dr -c /tmp/esrc/%s -o /dev/null"
-			      (car files)))
-	(erase-buffer)
-	(insert-file-contents (concat "/tmp/esrc/" (car files) ".rtl"))
-	(while (re-search-forward ";; Function \\|(call_insn " nil t)
-	  (if (= (char-after (- (point) 3)) ?o)
-	      (progn
-		(looking-at "[a-zA-Z0-9_]+")
-		(setq name (intern (buffer-substring (match-beginning 0)
-						     (match-end 0))))
-		(message "%s : %s" (car files) name)
-		(setq entry (list name)
-		      find-gc-subrs-called (cons entry find-gc-subrs-called)))
-	    (if (looking-at ".*\n?.*\"\\([A-Za-z0-9_]+\\)\"")
+  (setq find-gc-subrs-called nil)
+  (let ((case-fold-search nil)
+	(default-directory find-gc-source-directory)
+	(files find-gc-source-files)
+	name entry rtlfile)
+    (dolist (file files)
+      (message "Compiling %s..." file)
+      (call-process "gcc" nil nil nil "-I" "." "-I" "../lib"
+		    "-fdump-rtl-expand" "-o" null-device "-c" file)
+      (setq rtlfile
+	    (file-expand-wildcards (format "%s.*.expand" file) t))
+      (if (/= 1 (length rtlfile))
+	  (message "Error compiling `%s'?" file)
+	(with-temp-buffer
+	  (insert-file-contents (setq rtlfile (car rtlfile)))
+	  (delete-file rtlfile)
+	  (while (re-search-forward ";; Function \\|(call_insn " nil t)
+	    (if (= (char-after (- (point) 3)) ?o)
 		(progn
-		  (setq name (intern (buffer-substring (match-beginning 1)
-						       (match-end 1))))
-		  (or (memq name (cdr entry))
-		      (setcdr entry (cons name (cdr entry))))))))
-	(delete-file (concat "/tmp/esrc/" (car files) ".rtl"))
-	(setq files (cdr files)))))
-)
-
+		  (looking-at "[a-zA-Z0-9_]+")
+		  (setq name (intern (match-string 0)))
+		  (message "%s : %s" (car files) name)
+		  (setq entry (list name)
+			find-gc-subrs-called
+			(cons entry find-gc-subrs-called)))
+	      (if (looking-at ".*\n?.*\"\\([A-Za-z0-9_]+\\)\"")
+		  (progn
+		    (setq name (intern (match-string 1)))
+		    (or (memq name (cdr entry))
+			(setcdr entry (cons name (cdr entry)))))))))))))
 
 (defun trace-use-tree ()
   (setq find-gc-subrs-callers (mapcar 'list (mapcar 'car find-gc-subrs-called)))
