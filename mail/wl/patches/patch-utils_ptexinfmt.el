$NetBSD: patch-utils_ptexinfmt.el,v 1.1 2013/06/14 03:46:30 mef Exp $

Loading `/usr/pkgsrc/mail/wl/work/wl-2.14.0/utils/ptexinfmt.el': old-style backquotes detected!
Wrong number of arguments: put, 2
INFODIR is /usr/pkgsrc/mail/wl/work/.destdir/usr/pkg/info

*** [info] Error code 255

--- utils/ptexinfmt.el.orig	2005-02-24 17:16:41.000000000 +0900
+++ utils/ptexinfmt.el	2013-06-14 11:50:27.000000000 +0900
@@ -509,7 +509,7 @@
   (goto-char texinfo-command-start))
 
 ;; @,{c}	==>	c,	cedilla accent
-(put ', 'texinfo-format 'texinfo-format-cedilla-accent)
+(put '\, 'texinfo-format 'texinfo-format-cedilla-accent)
 (ptexinfmt-defun-if-void texinfo-format-cedilla-accent ()
   (insert (texinfo-parse-arg-discard) ",")
   (goto-char texinfo-command-start))
