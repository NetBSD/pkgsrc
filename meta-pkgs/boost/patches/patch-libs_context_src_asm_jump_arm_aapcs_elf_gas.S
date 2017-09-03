$NetBSD: patch-libs_context_src_asm_jump_arm_aapcs_elf_gas.S,v 1.2 2017/09/03 01:41:00 jakllsch Exp $

Work-around for NetBSD earmv6hf toolchain failing to assemble
v(ld|st)mia instruction if it's not explicitly told there's an FPU.

--- libs/context/src/asm/jump_arm_aapcs_elf_gas.S.orig	2017-08-19 16:49:40.000000000 +0000
+++ libs/context/src/asm/jump_arm_aapcs_elf_gas.S
@@ -39,6 +39,9 @@
  *******************************************************/
 
 .text
+#if (defined(__VFP_FP__) && !defined(__SOFTFP__))
+.fpu vfp
+#endif
 .globl jump_fcontext
 .align 2
 .type jump_fcontext,%function
