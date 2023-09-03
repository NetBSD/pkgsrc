$NetBSD: patch-sasl-cram.el,v 1.1 2023/09/03 14:58:39 mef Exp $

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./sasl-cram.el	2005-07-06 11:09:05.000000000 +0900
+++ ././sasl-cram.el	2020-09-05 16:02:39.901715405 +0900
@@ -1,4 +1,4 @@
-;;; sasl-cram.el --- CRAM-MD5 module for the SASL client framework
+;;; sasl-cram.el --- CRAM-MD5 module for the SASL client framework  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 2000 Free Software Foundation, Inc.
 
@@ -27,6 +27,7 @@
 
 (require 'sasl)
 (require 'hmac-md5)
+(require 'hex-util)
 
 (defconst sasl-cram-md5-steps
   '(ignore				;no initial response
