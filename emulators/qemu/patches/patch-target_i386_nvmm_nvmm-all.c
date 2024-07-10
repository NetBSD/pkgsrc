$NetBSD: patch-target_i386_nvmm_nvmm-all.c,v 1.7 2024/07/10 06:52:48 triaxx Exp $

Permit using older nvmm version.

--- target/i386/nvmm/nvmm-all.c.orig	2024-06-10 18:35:25.000000000 +0000
+++ target/i386/nvmm/nvmm-all.c
@@ -1169,14 +1169,10 @@ nvmm_accel_init(MachineState *ms)
         error_report("NVMM: Unable to fetch capability, error=%d", errno);
         return -err;
     }
-    if (qemu_mach.cap.version < NVMM_KERN_VERSION) {
+    if (qemu_mach.cap.version > NVMM_USER_VERSION) {
         error_report("NVMM: Unsupported version %u", qemu_mach.cap.version);
         return -EPROGMISMATCH;
     }
-    if (qemu_mach.cap.state_size != sizeof(struct nvmm_x64_state)) {
-        error_report("NVMM: Wrong state size %u", qemu_mach.cap.state_size);
-        return -EPROGMISMATCH;
-    }
 
     ret = nvmm_machine_create(&qemu_mach.mach);
     if (ret == -1) {
