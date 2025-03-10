$NetBSD: patch-target_i386_nvmm_nvmm-all.c,v 1.10 2025/03/10 13:46:26 wiz Exp $

emulators/qemu: Fix NVMM for UEFI (OVMF)

* From DragonFly BSD's Redmine's issue 3110 to fix memory error
  when UEFI boot.

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
 
