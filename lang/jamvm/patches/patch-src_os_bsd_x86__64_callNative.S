$NetBSD: patch-src_os_bsd_x86__64_callNative.S,v 1.2 2015/12/29 23:34:48 dholland Exp $

Fix assembler syntax.

--- src/os/bsd/x86_64/callNative.S.orig	2013-02-25 20:16:25.000000000 +0000
+++ src/os/bsd/x86_64/callNative.S
@@ -24,7 +24,7 @@
 .text
 .align  2
 .global callJNIMethod
-.type   callJNIMethod,function
+.type   callJNIMethod,@function
 
 /*
  * Arguments passed in:
