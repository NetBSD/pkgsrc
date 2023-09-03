$NetBSD: patch-sasl-scram.el,v 1.1 2023/09/03 14:58:39 mef Exp $

 flim-1_14-wl branch at 2023-08-08

--- /tmp/W/devel/flim/work/flim-1.14.9/sasl-scram.el	2005-07-06 11:09:05.000000000 +0900
+++ ./sasl-scram.el	2023-08-31 08:29:38.617749986 +0900
@@ -1,4 +1,4 @@
-;;; sasl-scram.el --- Compute SCRAM-MD5.
+;;; sasl-scram.el --- Compute SCRAM-MD5.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1999 Shuhei KOBAYASHI
 
@@ -88,9 +88,9 @@
     (if no-security-layer
 	(aset csecinfo 0 (logior (aref csecinfo 0) 1))
       (aset csecinfo 1
-	    (lsh (logand buffer-size (lsh 255 16)) -16))
+	    (ash (logand buffer-size (ash 255 16)) -16))
       (aset csecinfo 2
-	    (lsh (logand buffer-size (lsh 255 8)) -8))
+	    (ash (logand buffer-size (ash 255 8)) -8))
       (aset csecinfo 3 (logand buffer-size 255)))
     csecinfo))
 
@@ -204,7 +204,7 @@
       (fillarray server-salt 0)
       (fillarray buff 0))))
 
-(defun sasl-scram-md5-response-1 (client step)
+(defun sasl-scram-md5-response-1 (client _step)
   (sasl-client-set-property
    client 'client-msg-1
    (sasl-scram-md5-make-client-msg-1
