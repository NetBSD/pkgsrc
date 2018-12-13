$NetBSD: patch-libs_context_src_asm_jump_arm_aapcs_elf_gas.S,v 1.3 2018/12/13 19:22:57 adam Exp $

Work-around for NetBSD earmv6hf toolchain failing to assemble
v(ld|st)mia instruction if it's not explicitly told there's an FPU.

--- libs/context/src/asm/jump_arm_aapcs_elf_gas.S.orig	2018-12-05 19:58:16.000000000 +0000
+++ libs/context/src/asm/jump_arm_aapcs_elf_gas.S
@@ -40,6 +40,9 @@
 
 .file "jump_arm_aapcs_elf_gas.S"
 .text
+#if (defined(__VFP_FP__) && !defined(__SOFTFP__))
+.fpu vfp
+#endif
 .globl jump_fcontext
 .align 2
 .type jump_fcontext,%function
