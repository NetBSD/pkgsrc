$NetBSD: patch-hw-mips-mipssim.c,v 1.4 2021/08/27 03:32:37 ryoon Exp $

--- hw/mips/mipssim.c.orig	2021-08-04 16:29:07.000000000 +0000
+++ hw/mips/mipssim.c
@@ -39,12 +39,20 @@
 #include "hw/boards.h"
 #include "hw/mips/bios.h"
 #include "hw/loader.h"
+#include "hw/or-irq.h"
 #include "elf.h"
 #include "hw/sysbus.h"
 #include "hw/qdev-properties.h"
 #include "qemu/error-report.h"
 #include "sysemu/qtest.h"
 #include "sysemu/reset.h"
+#include "hw/virtio/virtio-mmio.h"
+
+#define NUM_VIRTIO_TRANSPORTS	32
+
+#define DEV_SPACING		0x10000		/* space devices every 64k */
+#define ISA_BASE		0x1fd00000
+#define	VIRTIO_MMIO_BASE	(ISA_BASE + DEV_SPACING)
 
 static struct _loaderparams {
     int ram_size;
@@ -135,7 +143,7 @@ static void mipsnet_init(int base, qemu_
                                 sysbus_mmio_get_region(s, 0));
 }
 
-static void
+void
 mips_mipssim_init(MachineState *machine)
 {
     const char *kernel_filename = machine->kernel_filename;
@@ -146,6 +154,7 @@ mips_mipssim_init(MachineState *machine)
     MemoryRegion *isa = g_new(MemoryRegion, 1);
     MemoryRegion *bios = g_new(MemoryRegion, 1);
     Clock *cpuclk;
+    DeviceState *virtio_orgate;
     MIPSCPU *cpu;
     CPUMIPSState *env;
     ResetData *reset_info;
@@ -208,7 +217,7 @@ mips_mipssim_init(MachineState *machine)
     /* Register 64 KB of ISA IO space at 0x1fd00000. */
     memory_region_init_alias(isa, NULL, "isa_mmio",
                              get_system_io(), 0, 0x00010000);
-    memory_region_add_subregion(get_system_memory(), 0x1fd00000, isa);
+    memory_region_add_subregion(get_system_memory(), ISA_BASE, isa);
 
     /*
      * A single 16450 sits at offset 0x3f8. It is attached to
@@ -229,6 +238,23 @@ mips_mipssim_init(MachineState *machine)
     if (nd_table[0].used)
         /* MIPSnet uses the MIPS CPU INT0, which is interrupt 2. */
         mipsnet_init(0x4200, env->irq[2], &nd_table[0]);
+
+    /*
+     * virtio extention; register 32 virtio devices just after the ISA space
+     * at 0x1fd10000 with stride of 512 bytes as per i386s microvm target.
+     * register these devices in reverse order (see comments in hw/arm/virt.c)
+     */
+    virtio_orgate = DEVICE(object_new(TYPE_OR_IRQ));
+    object_property_set_int(OBJECT(virtio_orgate),
+         "num-lines", NUM_VIRTIO_TRANSPORTS, &error_fatal);
+    qdev_realize_and_unref(virtio_orgate, NULL, &error_fatal);
+
+    for (int i = NUM_VIRTIO_TRANSPORTS - 1; i >= 0; i--) {
+        sysbus_create_simple("virtio-mmio",
+            0x1fd10000 + i * 512,
+            qdev_get_gpio_in(virtio_orgate, i));
+    }
+    qdev_connect_gpio_out(DEVICE(virtio_orgate), 0, env->irq[3]);
 }
 
 static void mips_mipssim_machine_init(MachineClass *mc)
