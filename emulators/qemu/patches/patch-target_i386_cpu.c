$NetBSD: patch-target_i386_cpu.c,v 1.3 2023/12/28 17:15:39 adam Exp $

Permit to use `-cpu host' with NVMM.

--- target/i386/cpu.c.orig	2023-12-19 21:24:34.000000000 +0000
+++ target/i386/cpu.c
@@ -26,6 +26,7 @@
 #include "tcg/helper-tcg.h"
 #include "sysemu/reset.h"
 #include "sysemu/hvf.h"
+#include "sysemu/nvmm.h"
 #include "hvf/hvf-i386.h"
 #include "kvm/kvm_i386.h"
 #include "sev.h"
@@ -1643,7 +1644,7 @@ uint32_t xsave_area_size(uint64_t mask,
 
 static inline bool accel_uses_host_cpuid(void)
 {
-    return kvm_enabled() || hvf_enabled();
+    return kvm_enabled() || hvf_enabled() || nvmm_enabled();
 }
 
 static inline uint64_t x86_cpu_xsave_xcr0_components(X86CPU *cpu)
@@ -7314,7 +7315,8 @@ static void x86_cpu_realizefn(DeviceStat
 
     if (xcc->host_cpuid_required && !accel_uses_host_cpuid()) {
         g_autofree char *name = x86_cpu_class_get_model_name(xcc);
-        error_setg(&local_err, "CPU model '%s' requires KVM or HVF", name);
+        error_setg(&local_err,
+		   "CPU model '%s' requires KVM or HVF or NVMM", name);
         goto out;
     }
 
