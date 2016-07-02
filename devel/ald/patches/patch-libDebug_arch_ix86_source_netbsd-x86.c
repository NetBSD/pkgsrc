$NetBSD: patch-libDebug_arch_ix86_source_netbsd-x86.c,v 1.1 2016/07/02 14:41:59 joerg Exp $

--- libDebug/arch/ix86/source/netbsd-x86.c.orig	2016-07-02 09:20:24.000000000 +0000
+++ libDebug/arch/ix86/source/netbsd-x86.c
@@ -20,7 +20,12 @@
 #include <string.h>
 #include <signal.h>
 #include <machine/reg.h>
+#include <sys/param.h>
+#if __NetBSD_Version__ >= 700000000
+#include <x86/fpu.h>
+#else
 #include <machine/npx.h>
+#endif
 
 /*
  * Top-level includes
@@ -261,6 +266,20 @@ x86readFPUDebug(struct debugWorkspace *w
 
   fpframe = (struct save87 *) &(ws->regContents.fpRegs);
 
+#if __NetBSD_Version__ >= 700000000
+  fpuState->fctrl = fpframe->s87_cw;
+  fpuState->fstat = fpframe->s87_sw;
+  fpuState->ftag = fpframe->s87_tw;
+  fpuState->fip = fpframe->s87_ip.fa_32.fa_off;
+  fpuState->fcs = fpframe->s87_ip.fa_32.fa_seg;
+  fpuState->fopcode = fpframe->s87_ip.fa_32.fa_opcode;
+  fpuState->fooff = fpframe->s87_ip.fa_32.fa_off;
+  fpuState->foseg = fpframe->s87_ip.fa_32.fa_seg;
+
+  memcpy(fpuState->stptr,
+         fpframe->s87_ac,
+         FPU_NUM_DATA_REGS * FPU_DATA_REG_SIZE);
+#else
   fpuState->fctrl = fpframe->sv_env.en_cw;
   fpuState->fstat = fpframe->sv_env.en_sw;
   fpuState->ftag = fpframe->sv_env.en_tw;
@@ -273,6 +292,7 @@ x86readFPUDebug(struct debugWorkspace *w
   memcpy(fpuState->stptr,
          fpframe->sv_ac,
          FPU_NUM_DATA_REGS * FPU_DATA_REG_SIZE);
+#endif
 
 #if 0
   fpuState->fctrl = *((unsigned short *) x86Registers[REG_FCTRL].valptr);
