$NetBSD: patch-lisp_emacspeak-bookshare.el,v 1.1 2024/03/13 05:48:36 wiz Exp $

* Fix references to the build directory.

--- lisp/emacspeak-bookshare.el.orig	2022-04-18 20:56:41.000000000 +0000
+++ lisp/emacspeak-bookshare.el
@@ -115,7 +115,7 @@ See http://developer.bookshare.org/docs 
   "Bookshare user Id.")
 
 (defcustom emacspeak-bookshare-directory
-  (eval-when-compile (expand-file-name "~/books/book-share"))
+  (file-name-as-directory "~/books/book-share")
   "Customize this to the root of where books are organized."
   :type 'directory
   :group 'emacspeak-bookshare)
