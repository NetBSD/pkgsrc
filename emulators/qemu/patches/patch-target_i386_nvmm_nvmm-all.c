$NetBSD: patch-target_i386_nvmm_nvmm-all.c,v 1.6 2024/02/20 14:16:58 imil Exp $

Permit using older nvmm version.

--- target/i386/nvmm/nvmm-all.c.orig	2024-01-29 19:13:22.000000000 +0000
+++ target/i386/nvmm/nvmm-all.c
@@ -1171,14 +1171,10 @@ nvmm_accel_init(MachineState *ms)
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
