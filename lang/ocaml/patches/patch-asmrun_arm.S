$NetBSD: patch-asmrun_arm.S,v 1.2 2015/01/20 14:12:25 jaapb Exp $

pkgsrc_runtime flag
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
 
