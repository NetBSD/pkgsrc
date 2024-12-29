$NetBSD: patch-libs_context_src_asm_ontop_arm_aapcs_elf_gas.S,v 1.4 2024/12/29 14:53:14 adam Exp $

Work-around for NetBSD earmv6hf toolchain failing to assemble
v(ld|st)mia instruction if it's not explicitly told there's an FPU.

--- libs/context/src/asm/ontop_arm_aapcs_elf_gas.S.orig	2024-12-05 00:53:30.000000000 +0000
+++ libs/context/src/asm/ontop_arm_aapcs_elf_gas.S
@@ -40,6 +40,9 @@
 
 .file "ontop_arm_aapcs_elf_gas.S"
 .text
+#if (defined(__VFP_FP__) && !defined(__SOFTFP__))
+.fpu vfp
+#endif
 .globl ontop_fcontext
 .hidden ontop_fcontext
 .align 2
