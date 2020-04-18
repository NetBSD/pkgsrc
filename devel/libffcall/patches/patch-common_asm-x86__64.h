$NetBSD: patch-common_asm-x86__64.h,v 1.1 2020/04/18 22:00:40 joerg Exp $

--- common/asm-x86_64.h.orig	2020-03-11 16:04:30.072321269 +0000
+++ common/asm-x86_64.h
@@ -280,6 +280,6 @@
 #define EH_FRAME_SECTION .eh_frame,"aL",link=.text,@unwind
 #else
 // Linux/ELF
-#define EH_FRAME_SECTION .eh_frame,"aw",@progbits
+#define EH_FRAME_SECTION .eh_frame,"a",@progbits
 #endif
 #endif
