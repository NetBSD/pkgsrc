$NetBSD: patch-target_i386_cpu.c,v 1.2 2022/09/17 09:54:56 tnn Exp $

Permit to use `-cpu host' with NVMM.

--- target/i386/cpu.c.orig	2022-08-30 16:41:57.000000000 +0000
+++ target/i386/cpu.c
@@ -26,6 +26,7 @@
 #include "tcg/helper-tcg.h"
 #include "sysemu/reset.h"
 #include "sysemu/hvf.h"
+#include "sysemu/nvmm.h"
 #include "kvm/kvm_i386.h"
 #include "sev.h"
 #include "qapi/error.h"
@@ -1486,7 +1487,7 @@ static uint32_t xsave_area_size(uint64_t
 
 static inline bool accel_uses_host_cpuid(void)
 {
-    return kvm_enabled() || hvf_enabled();
+    return kvm_enabled() || hvf_enabled() || nvmm_enabled();
 }
 
 static inline uint64_t x86_cpu_xsave_xcr0_components(X86CPU *cpu)
@@ -6476,7 +6477,8 @@ static void x86_cpu_realizefn(DeviceStat
 
     if (xcc->host_cpuid_required && !accel_uses_host_cpuid()) {
         g_autofree char *name = x86_cpu_class_get_model_name(xcc);
-        error_setg(&local_err, "CPU model '%s' requires KVM or HVF", name);
+        error_setg(&local_err,
+		   "CPU model '%s' requires KVM or HVF or NVMM", name);
         goto out;
     }
 
