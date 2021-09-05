$NetBSD: patch-src_cpus_cpu__arm__instr__dpi.c,v 1.1 2021/09/05 07:27:13 skrll Exp $

--- src/cpus/cpu_arm_instr_dpi.c.orig	2021-04-22 18:04:18.000000000 +0000
+++ src/cpus/cpu_arm_instr_dpi.c
@@ -255,7 +255,7 @@ void A__NAME(struct cpu *cpu, struct arm
 
 #if defined(A__CMP) || defined(A__RSB) || defined(A__SUB) || \
     defined(A__RSC) || defined(A__SBC)
-	if ((uint32_t)a >= (uint32_t)b)
+	if (c32 == c64)
 		cpu->cd.arm.flags |= ARM_F_C;
 #else
 #if defined(A__ADC) || defined(A__ADD) || defined(A__CMN)
