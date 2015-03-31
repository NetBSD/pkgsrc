$NetBSD: patch-src_os_bsd_arm_callNativeEABI.S,v 1.1 2015/03/31 15:43:34 joerg Exp $

--- src/os/bsd/arm/callNativeEABI.S.orig	2015-03-27 13:37:56.000000000 +0000
+++ src/os/bsd/arm/callNativeEABI.S
@@ -63,7 +63,7 @@ scan_sig:
 
 skip_brackets:
         cmp     r3, #91                 /* '[' */
-        ldreqb  r3, [r5], #1
+        ldrbeq  r3, [r5], #1
         beq     skip_brackets
 
         cmp     r3, #76                 /* 'L' */
