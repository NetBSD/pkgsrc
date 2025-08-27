$NetBSD: patch-target_i386_cpu.c,v 1.6 2025/08/27 06:27:03 adam Exp $

Permit to use `-cpu host' with NVMM.

--- target/i386/cpu.c.orig	2025-08-26 18:32:38.000000000 +0000
+++ target/i386/cpu.c
@@ -9326,7 +9326,8 @@ static void x86_cpu_realizefn(DeviceStat
 
     if (xcc->host_cpuid_required && !accel_uses_host_cpuid()) {
         g_autofree char *name = x86_cpu_class_get_model_name(xcc);
-        error_setg(&local_err, "CPU model '%s' requires KVM or HVF", name);
+        error_setg(&local_err,
+		   "CPU model '%s' requires KVM or HVF or NVMM", name);
         goto out;
     }
 
