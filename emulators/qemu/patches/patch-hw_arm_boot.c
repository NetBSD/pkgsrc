$NetBSD: patch-hw_arm_boot.c,v 1.1 2018/11/05 07:27:59 skrll Exp $

--- hw/arm/boot.c.orig	2018-11-04 17:27:47.000000000 +0000
+++ hw/arm/boot.c
@@ -29,8 +29,9 @@
  * Documentation/arm/Booting and Documentation/arm64/booting.txt
  * They have different preferred image load offsets from system RAM base.
  */
-#define KERNEL_ARGS_ADDR 0x100
-#define KERNEL_LOAD_ADDR 0x00010000
+#define KERNEL_ARGS_ADDR   0x100
+#define KERNEL_NOLOAD_ADDR 0x00000000
+#define KERNEL_LOAD_ADDR   0x00010000
 #define KERNEL64_LOAD_ADDR 0x00080000
 
 #define ARM64_TEXT_OFFSET_OFFSET    8
@@ -1049,7 +1050,8 @@ void arm_load_kernel(ARMCPU *cpu, struct
     }
     entry = elf_entry;
     if (kernel_size < 0) {
-        kernel_size = load_uimage_as(info->kernel_filename, &entry, NULL,
+        uint64_t loadaddr = info->loader_start + KERNEL_NOLOAD_ADDR;
+        kernel_size = load_uimage_as(info->kernel_filename, &entry, &loadaddr,
                                      &is_linux, NULL, NULL, as);
     }
     if (arm_feature(&cpu->env, ARM_FEATURE_AARCH64) && kernel_size < 0) {
