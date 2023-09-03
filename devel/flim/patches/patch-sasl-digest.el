$NetBSD: patch-sasl-digest.el,v 1.1 2023/09/03 14:58:39 mef Exp $

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./sasl-digest.el	2005-07-06 11:09:05.000000000 +0900
+++ ././sasl-digest.el	2020-09-05 16:02:39.901792159 +0900
@@ -1,4 +1,4 @@
-;;; sasl-digest.el --- DIGEST-MD5 module for the SASL client framework
+;;; sasl-digest.el --- DIGEST-MD5 module for the SASL client framework  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 2000 Free Software Foundation, Inc.
 
@@ -34,6 +34,7 @@
 
 (require 'sasl)
 (require 'hmac-md5)
+(require 'hex-util)
 
 (defvar sasl-digest-md5-nonce-count 1)
 (defvar sasl-digest-md5-unique-id-function
