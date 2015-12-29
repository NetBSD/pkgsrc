$NetBSD: patch-src_os_bsd_arm_callNativeEABI.S,v 1.2 2015/12/29 23:34:48 dholland Exp $

Use unified asm syntax.

--- src/os/bsd/arm/callNativeEABI.S.orig	2015-03-27 13:37:56.000000000 +0000
+++ src/os/bsd/arm/callNativeEABI.S
@@ -63,7 +63,7 @@ scan_sig:
 
 skip_brackets:
         cmp     r3, #91                 /* '[' */
-        ldreqb  r3, [r5], #1
+        ldrbeq  r3, [r5], #1
         beq     skip_brackets
 
         cmp     r3, #76                 /* 'L' */
