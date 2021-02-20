$NetBSD: patch-hw_alpha_dp264.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Because we're using CLIPPER IRQ mappings, the minimum PCI device
IdSel is 1.  Pass that to typhoon_init().

Set bit 6 in trap_arg2 to tell the PALcode that the -nographic option
was specified.  This is used by the PALcode to initialize the CTB for
serial console.

--- hw/alpha/dp264.c.orig	2020-08-11 19:17:14.000000000 +0000
+++ hw/alpha/dp264.c	2020-10-02 15:52:10.654767858 +0000
@@ -72,13 +72,25 @@ static void clipper_init(MachineState *m
         cpus[i] = ALPHA_CPU(cpu_create(machine->cpu_type));
     }
 
+    /* arg0 -> memory size
+       arg1 -> kernel entry point
+       arg2 -> config word
+
+       Config word: bits 0-5 -> ncpus
+		    bit  6   -> nographics option (for HWRPB CTB)
+
+       See init_hwrpb() in the PALcode.  */
+
     cpus[0]->env.trap_arg0 = ram_size;
     cpus[0]->env.trap_arg1 = 0;
     cpus[0]->env.trap_arg2 = smp_cpus;
+    if (!machine->enable_graphics)
+      cpus[0]->env.trap_arg2 |= (1 << 6);
 
-    /* Init the chipset.  */
+    /* Init the chipset.  Because we're using CLIPPER IRQ mappings,
+       the minimum PCI device IdSel is 1.  */
     pci_bus = typhoon_init(machine->ram, &isa_bus, &rtc_irq, cpus,
-                           clipper_pci_map_irq);
+                           clipper_pci_map_irq, PCI_DEVFN(1, 0));
 
     /* Since we have an SRM-compatible PALcode, use the SRM epoch.  */
     mc146818_rtc_init(isa_bus, 1900, rtc_irq);
