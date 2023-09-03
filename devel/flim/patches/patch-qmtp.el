$NetBSD: patch-qmtp.el,v 1.1 2023/09/03 14:58:39 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/qmtp.el	2005-07-06 11:09:05.000000000 +0900
+++ ./qmtp.el	2023-08-31 08:29:38.616972354 +0900
@@ -1,4 +1,4 @@
-;;; qmtp.el --- basic functions to send mail with QMTP server
+;;; qmtp.el --- basic functions to send mail with QMTP server  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 2000 Free Software Foundation, Inc.
 
@@ -112,14 +112,12 @@
 	t)
     (error)))
 
-(make-obsolete 'qmtp-via-qmtp "It's old API.")
+(make-obsolete 'qmtp-via-qmtp "It's old API." "05 Nov 2000")
 
 ;;;###autoload
 (defun qmtp-send-buffer (sender recipients buffer)
-  (save-excursion
-    (set-buffer
-     (get-buffer-create
-      (format "*trace of QMTP session to %s*" qmtp-server)))
+  (with-current-buffer (get-buffer-create
+			(format "*trace of QMTP session to %s*" qmtp-server))
     (buffer-disable-undo)
     (erase-buffer)
     (make-local-variable 'qmtp-read-point)
