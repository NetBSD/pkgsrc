$NetBSD: patch-target_i386_nvmm_nvmm-all.c,v 1.12 2026/02/15 07:37:37 adam Exp $

emulators/qemu: Fix NVMM for UEFI (OVMF)

* From DragonFly BSD's Redmine's issue 3310 to fix memory error
  when UEFI boot.

--- target/i386/nvmm/nvmm-all.c.orig	2025-08-26 18:32:38.000000000 +0000
+++ target/i386/nvmm/nvmm-all.c
@@ -1059,7 +1059,11 @@ nvmm_process_section(MemoryRegionSection
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
 
