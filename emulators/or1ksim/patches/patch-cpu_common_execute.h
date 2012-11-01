$NetBSD: patch-cpu_common_execute.h,v 1.1 2012/11/01 19:47:17 joerg Exp $

--- cpu/common/execute.h.orig	2012-10-30 20:06:03.000000000 +0000
+++ cpu/common/execute.h
@@ -75,8 +75,8 @@ extern struct cpu_state cpu_state;
 /*extern machword eval_operand(char *srcoperand,int* breakpoint);
 extern void set_operand(char *dstoperand, unsigned long value,int* breakpoint);*/
 void dumpreg();
-inline void dump_exe_log();
-inline int cpu_clock ();
+void dump_exe_log();
+int cpu_clock ();
 void cpu_reset ();
 uorreg_t evalsim_reg(unsigned int regno);
 void setsim_reg(unsigned int regno, uorreg_t value);
