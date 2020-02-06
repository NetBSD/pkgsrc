$NetBSD: patch-target_i386_helper.c,v 1.1 2020/02/06 16:46:17 kamil Exp $

Add NVMM support.

--- target/i386/helper.c.orig	2019-12-12 18:20:48.000000000 +0000
+++ target/i386/helper.c
@@ -981,7 +981,7 @@ void cpu_report_tpr_access(CPUX86State *
     X86CPU *cpu = env_archcpu(env);
     CPUState *cs = env_cpu(env);
 
-    if (kvm_enabled() || whpx_enabled()) {
+    if (kvm_enabled() || whpx_enabled() || nvmm_enabled()) {
         env->tpr_access_type = access;
 
         cpu_interrupt(cs, CPU_INTERRUPT_TPR);
