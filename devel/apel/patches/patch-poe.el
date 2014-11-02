$NetBSD: patch-poe.el,v 1.1 2014/11/02 16:08:33 ryoon Exp $

--- poe.el.orig	2008-09-06 15:16:14.000000000 +0000
+++ poe.el
@@ -1667,7 +1667,7 @@ See `walk-windows' for the meaning of MI
                      )))
       ;; arglist: (prefix &optional dir-flag suffix)
       (cond
-       ((not arglist)
+       ((or (not arglist) (not (listp arglist)))
         ;; `make-temp-file' is a built-in; expects 3-args.
         (put 'make-temp-file 'defun-maybe '3-args))
        ((> (length arglist) 3)
