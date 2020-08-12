$NetBSD: patch-include_sysemu_hw__accel.h,v 1.2 2020/08/12 18:31:27 ryoon Exp $

Add NVMM support.

--- include/sysemu/hw_accel.h.orig	2020-08-11 19:17:15.000000000 +0000
+++ include/sysemu/hw_accel.h
@@ -16,6 +16,7 @@
 #include "sysemu/kvm.h"
 #include "sysemu/hvf.h"
 #include "sysemu/whpx.h"
+#include "sysemu/nvmm.h"
 
 static inline void cpu_synchronize_state(CPUState *cpu)
 {
@@ -31,6 +32,9 @@ static inline void cpu_synchronize_state
     if (whpx_enabled()) {
         whpx_cpu_synchronize_state(cpu);
     }
+    if (nvmm_enabled()) {
+        nvmm_cpu_synchronize_state(cpu);
+    }
 }
 
 static inline void cpu_synchronize_post_reset(CPUState *cpu)
@@ -47,6 +51,10 @@ static inline void cpu_synchronize_post_
     if (whpx_enabled()) {
         whpx_cpu_synchronize_post_reset(cpu);
     }
+    if (nvmm_enabled()) {
+        nvmm_cpu_synchronize_post_reset(cpu);
+    }
+
 }
 
 static inline void cpu_synchronize_post_init(CPUState *cpu)
@@ -63,6 +71,9 @@ static inline void cpu_synchronize_post_
     if (whpx_enabled()) {
         whpx_cpu_synchronize_post_init(cpu);
     }
+    if (nvmm_enabled()) {
+        nvmm_cpu_synchronize_post_init(cpu);
+    }
 }
 
 static inline void cpu_synchronize_pre_loadvm(CPUState *cpu)
@@ -79,6 +90,9 @@ static inline void cpu_synchronize_pre_l
     if (whpx_enabled()) {
         whpx_cpu_synchronize_pre_loadvm(cpu);
     }
+    if (nvmm_enabled()) {
+        nvmm_cpu_synchronize_pre_loadvm(cpu);
+    }
 }
 
 #endif /* QEMU_HW_ACCEL_H */
