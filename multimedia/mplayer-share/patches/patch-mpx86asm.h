$NetBSD: patch-mpx86asm.h,v 1.1 2023/11/22 16:18:20 tsutsui Exp $

- fix asm constrains errors on gcc10 (NetBSD/i386 10.0)

--- mpx86asm.h.orig	2015-10-17 19:44:31.000000000 +0000
+++ mpx86asm.h
@@ -81,7 +81,7 @@ typedef int x86_reg;
 #endif
 
 #define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
-#define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
+#define HAVE_6REGS ARCH_X86_64
 
 #if ARCH_X86_64 && defined(PIC)
 #    define BROKEN_RELOCATIONS 1
