$NetBSD: patch-target_i386_nvmm_nvmm-all.c,v 1.8 2024/12/09 13:54:17 ryoon Exp $

Permit using older nvmm version.

--- target/i386/nvmm/nvmm-all.c.orig	2024-11-20 22:48:05.000000000 +0000
+++ target/i386/nvmm/nvmm-all.c
@@ -1057,7 +1057,11 @@ nvmm_process_section(MemoryRegionSection
     unsigned int delta;
     uintptr_t hva;
 
-    if (!memory_region_is_ram(mr)) {
+    /*
+     * Don't exclude ROMD memory; for example, it's used to map UEFI firmware
+     * (if=pflash) and should be mapped for guest.
+     */
+    if (!memory_region_is_ram(mr) && !memory_region_is_romd(mr)) {
         return;
     }
 
@@ -1170,14 +1174,10 @@ nvmm_accel_init(MachineState *ms)
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
