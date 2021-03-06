$NetBSD: patch-target_i386_helper.c,v 1.3 2021/03/06 11:19:34 reinoud Exp $

--- target/i386/helper.c.orig	2020-12-08 16:59:44.000000000 +0000
+++ target/i386/helper.c
@@ -1008,7 +1008,7 @@ void cpu_report_tpr_access(CPUX86State *
     X86CPU *cpu = env_archcpu(env);
     CPUState *cs = env_cpu(env);
 
-    if (kvm_enabled() || whpx_enabled()) {
+    if (kvm_enabled() || whpx_enabled() || nvmm_enabled()) {
         env->tpr_access_type = access;
 
         cpu_interrupt(cs, CPU_INTERRUPT_TPR);
