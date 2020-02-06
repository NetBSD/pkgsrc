$NetBSD: patch-include_sysemu_hw__accel.h,v 1.1 2020/02/06 16:46:17 kamil Exp $

Add NVMM support.

--- include/sysemu/hw_accel.h.orig	2019-12-12 18:20:48.000000000 +0000
+++ include/sysemu/hw_accel.h
@@ -15,6 +15,7 @@
 #include "sysemu/hax.h"
 #include "sysemu/kvm.h"
 #include "sysemu/whpx.h"
+#include "sysemu/nvmm.h"
 
 static inline void cpu_synchronize_state(CPUState *cpu)
 {
@@ -27,6 +28,9 @@ static inline void cpu_synchronize_state
     if (whpx_enabled()) {
         whpx_cpu_synchronize_state(cpu);
     }
+    if (nvmm_enabled()) {
+        nvmm_cpu_synchronize_state(cpu);
+    }
 }
 
 static inline void cpu_synchronize_post_reset(CPUState *cpu)
@@ -40,6 +44,10 @@ static inline void cpu_synchronize_post_
     if (whpx_enabled()) {
         whpx_cpu_synchronize_post_reset(cpu);
     }
+    if (nvmm_enabled()) {
+        nvmm_cpu_synchronize_post_reset(cpu);
+    }
+
 }
 
 static inline void cpu_synchronize_post_init(CPUState *cpu)
@@ -53,6 +61,9 @@ static inline void cpu_synchronize_post_
     if (whpx_enabled()) {
         whpx_cpu_synchronize_post_init(cpu);
     }
+    if (nvmm_enabled()) {
+        nvmm_cpu_synchronize_post_init(cpu);
+    }
 }
 
 static inline void cpu_synchronize_pre_loadvm(CPUState *cpu)
@@ -66,6 +77,9 @@ static inline void cpu_synchronize_pre_l
     if (whpx_enabled()) {
         whpx_cpu_synchronize_pre_loadvm(cpu);
     }
+    if (nvmm_enabled()) {
+        nvmm_cpu_synchronize_pre_loadvm(cpu);
+    }
 }
 
 #endif /* QEMU_HW_ACCEL_H */
