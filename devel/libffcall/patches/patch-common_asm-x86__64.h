$NetBSD: patch-common_asm-x86__64.h,v 1.2 2021/06/23 19:05:20 wiz Exp $

https://savannah.gnu.org/bugs/index.php?60815

--- common/asm-x86_64.h.orig	2021-04-15 00:58:54.000000000 +0000
+++ common/asm-x86_64.h
@@ -279,8 +279,8 @@
 // Solaris/ELF
 #define EH_FRAME_SECTION .eh_frame,"aL",link=.text,@unwind
 #else
-#if defined __FreeBSD__
-// FreeBSD/ELF
+#if defined __FreeBSD__ || defined __NetBSD__
+// FreeBSD or NetBSD/ELF
 #define EH_FRAME_SECTION .eh_frame,"a",@progbits
 #else
 // Linux/ELF
