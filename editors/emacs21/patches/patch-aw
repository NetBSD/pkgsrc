$NetBSD: patch-aw,v 1.1 2008/06/03 22:17:00 markd Exp $

--- lisp/fast-lock.el.orig	2001-07-16 04:15:34.000000000 +1200
+++ lisp/fast-lock.el
@@ -278,7 +278,7 @@ for buffers in Rmail mode, and size is i
 				      (integer :tag "size")))))
   :group 'fast-lock)
 
-(defcustom fast-lock-cache-directories '("." "~/.emacs-flc")
+(defcustom fast-lock-cache-directories '("~/.emacs-flc")
 ; - `internal', keep each file's Font Lock cache file in the same file.
 ; - `external', keep each file's Font Lock cache file in the same directory.
   "*Directories in which Font Lock cache files are saved and read.
@@ -296,13 +296,18 @@ For example:
  ((\"^/your/true/home/directory/\" . \".\") \"~/.emacs-flc\")
 
 would cause a file's current directory to be used if the file is under your
-home directory hierarchy, or otherwise the absolute directory `~/.emacs-flc'."
+home directory hierarchy, or otherwise the absolute directory `~/.emacs-flc'.
+For security reasons, it is not advisable to use the file's current directory
+to avoid the possibility of using the cache of another user."
   :type '(repeat (radio (directory :tag "directory")
 			(cons :tag "Matching"
 			      (regexp :tag "regexp")
 			      (directory :tag "directory"))))
   :group 'fast-lock)
 
+;;;###autoload
+(put 'fast-lock-cache-directories 'risky-local-variable t)
+
 (defcustom fast-lock-save-events '(kill-buffer kill-emacs)
   "*Events under which caches will be saved.
 Valid events are `save-buffer', `kill-buffer' and `kill-emacs'.
