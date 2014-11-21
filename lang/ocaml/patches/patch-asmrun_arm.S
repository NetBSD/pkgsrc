$NetBSD: patch-asmrun_arm.S,v 1.1 2014/11/21 14:15:20 joerg Exp $

--- asmrun/arm.S.orig	2014-11-20 13:12:25.000000000 +0000
+++ asmrun/arm.S
@@ -44,7 +44,7 @@
         cmp     \reg, #0
         beq     \lbl
         .endm
-#elif defined(SYS_freebsd)
+#elif defined(SYS_freebsd) || defined(SYS_netbsd)
         .arch   armv6
         .arm
 
