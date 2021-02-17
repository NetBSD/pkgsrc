$NetBSD: patch-hw-mips-mipssim.c,v 1.2 2021/02/17 17:16:01 reinoud Exp $

--- hw/mips/mipssim.c.orig	2020-08-11 19:17:15.000000000 +0000
+++ hw/mips/mipssim.c
@@ -46,6 +46,8 @@
 #include "sysemu/qtest.h"
 #include "sysemu/reset.h"
 
+void mips_mipssim_init(MachineState *);
+
 static struct _loaderparams {
     int ram_size;
     const char *kernel_filename;
@@ -140,8 +142,7 @@ static void mipsnet_init(int base, qemu_
                                 sysbus_mmio_get_region(s, 0));
 }
 
-static void
-mips_mipssim_init(MachineState *machine)
+void mips_mipssim_init(MachineState *machine)
 {
     const char *kernel_filename = machine->kernel_filename;
     const char *kernel_cmdline = machine->kernel_cmdline;
