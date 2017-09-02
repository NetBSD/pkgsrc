$NetBSD: patch-libs_context_src_asm_ontop_arm_aapcs_elf_gas.S,v 1.1 2017/09/02 10:42:12 bouyer Exp $

--- libs/context/src/asm/ontop_arm_aapcs_elf_gas.S.orig	2017-08-27 12:57:18.888935619 +0200
+++ libs/context/src/asm/ontop_arm_aapcs_elf_gas.S	2017-08-27 12:58:25.812105545 +0200
@@ -39,6 +39,9 @@
  *******************************************************/
 
 .text
+#if (defined(__VFP_FP__) && !defined(__SOFTFP__))
+.fpu vfpv3
+#endif
 .globl ontop_fcontext
 .align 2
 .type ontop_fcontext,%function
