$NetBSD: patch-hw-mips-mipssim.c,v 1.5 2024/04/24 07:20:59 adam Exp $

--- hw/mips/mipssim.c.orig	2024-04-10 17:43:25.000000000 +0000
+++ hw/mips/mipssim.c
@@ -36,6 +36,7 @@
 #include "sysemu/sysemu.h"
 #include "hw/boards.h"
 #include "hw/loader.h"
+#include "hw/or-irq.h"
 #include "elf.h"
 #include "hw/sysbus.h"
 #include "hw/qdev-properties.h"
@@ -136,7 +137,7 @@ static void mipsnet_init(int base, qemu_
                                 sysbus_mmio_get_region(s, 0));
 }
 
-static void
+void
 mips_mipssim_init(MachineState *machine)
 {
     const char *kernel_filename = machine->kernel_filename;
@@ -147,6 +148,7 @@ mips_mipssim_init(MachineState *machine)
     MemoryRegion *isa = g_new(MemoryRegion, 1);
     MemoryRegion *bios = g_new(MemoryRegion, 1);
     Clock *cpuclk;
+    DeviceState *virtio_orgate;
     MIPSCPU *cpu;
     CPUMIPSState *env;
     ResetData *reset_info;
@@ -233,6 +235,23 @@ mips_mipssim_init(MachineState *machine)
 
     /* MIPSnet uses the MIPS CPU INT0, which is interrupt 2. */
     mipsnet_init(0x4200, env->irq[2]);
+
+    /*
+     * virtio extention; register 32 virtio devices just after the ISA space
+     * at 0x1fd10000 with stride of 512 bytes as per i386s microvm target.
+     * register these devices in reverse order (see comments in hw/arm/virt.c)
+     */
+    virtio_orgate = DEVICE(object_new(TYPE_OR_IRQ));
+    object_property_set_int(OBJECT(virtio_orgate),
+         "num-lines", 32 /*NUM_VIRTIO_TRANSPORTS*/, &error_fatal);
+    qdev_realize_and_unref(virtio_orgate, NULL, &error_fatal);
+
+    for (int i = 31 /*NUM_VIRTIO_TRANSPORTS - 1*/; i >= 0; i--) {
+        sysbus_create_simple("virtio-mmio",
+            0x1fd10000 + i * 512,
+            qdev_get_gpio_in(virtio_orgate, i));
+    }
+    qdev_connect_gpio_out(DEVICE(virtio_orgate), 0, env->irq[3]);
 }
 
 static void mips_mipssim_machine_init(MachineClass *mc)
