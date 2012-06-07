$NetBSD: patch-hw_ppc__oldworld.c,v 1.1 2012/06/07 21:35:37 ryoon Exp $

Avoid conflicts with round_page() macro in DragonFly's <cpu/param.h>

--- hw/ppc_oldworld.c.orig	2011-08-08 18:28:42 +0000
+++ hw/ppc_oldworld.c
@@ -59,7 +59,7 @@ static uint64_t translate_kernel_address
     return (addr & 0x0fffffff) + KERNEL_LOAD_ADDR;
 }
 
-static target_phys_addr_t round_page(target_phys_addr_t addr)
+static target_phys_addr_t round_pageq(target_phys_addr_t addr)
 {
     return (addr + TARGET_PAGE_SIZE - 1) & TARGET_PAGE_MASK;
 }
@@ -162,7 +162,7 @@ static void ppc_heathrow_init (ram_addr_
         }
         /* load initrd */
         if (initrd_filename) {
-            initrd_base = round_page(kernel_base + kernel_size + KERNEL_GAP);
+            initrd_base = round_pageq(kernel_base + kernel_size + KERNEL_GAP);
             initrd_size = load_image_targphys(initrd_filename, initrd_base,
                                               ram_size - initrd_base);
             if (initrd_size < 0) {
@@ -170,11 +170,11 @@ static void ppc_heathrow_init (ram_addr_
                          initrd_filename);
                 exit(1);
             }
-            cmdline_base = round_page(initrd_base + initrd_size);
+            cmdline_base = round_pageq(initrd_base + initrd_size);
         } else {
             initrd_base = 0;
             initrd_size = 0;
-            cmdline_base = round_page(kernel_base + kernel_size + KERNEL_GAP);
+            cmdline_base = round_pageq(kernel_base + kernel_size + KERNEL_GAP);
         }
         ppc_boot_device = 'm';
     } else {
