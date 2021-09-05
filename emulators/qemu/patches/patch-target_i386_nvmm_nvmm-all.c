$NetBSD: patch-target_i386_nvmm_nvmm-all.c,v 1.4 2021/09/05 20:58:16 nia Exp $

Re-add NetBSD 9 support.

--- target/i386/nvmm/nvmm-all.c.orig	2021-08-24 17:35:41.000000000 +0000
+++ target/i386/nvmm/nvmm-all.c
@@ -750,7 +750,11 @@ nvmm_vcpu_loop(CPUState *cpu)
         nvmm_vcpu_pre_run(cpu);
 
         if (qatomic_read(&cpu->exit_request)) {
+#if NVMM_USER_VERSION >= 2
             nvmm_vcpu_stop(vcpu);
+#else
+            qemu_cpu_kick_self();
+#endif
         }
 
         /* Read exit_request before the kernel reads the immediate exit flag */
@@ -767,6 +771,7 @@ nvmm_vcpu_loop(CPUState *cpu)
         switch (exit->reason) {
         case NVMM_VCPU_EXIT_NONE:
             break;
+#if NVMM_USER_VERSION >= 2
         case NVMM_VCPU_EXIT_STOPPED:
             /*
              * The kernel cleared the immediate exit flag; cpu->exit_request
@@ -775,6 +780,7 @@ nvmm_vcpu_loop(CPUState *cpu)
             smp_wmb();
             qcpu->stop = true;
             break;
+#endif
         case NVMM_VCPU_EXIT_MEMORY:
             ret = nvmm_handle_mem(mach, vcpu);
             break;
@@ -888,8 +894,12 @@ nvmm_ipi_signal(int sigcpu)
 {
     if (current_cpu) {
         struct qemu_vcpu *qcpu = get_qemu_vcpu(current_cpu);
+#if NVMM_USER_VERSION >= 2
         struct nvmm_vcpu *vcpu = &qcpu->vcpu;
         nvmm_vcpu_stop(vcpu);
+#else
+        qcpu->stop = true;
+#endif
     }
 }
 
