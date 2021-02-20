$NetBSD: patch-hw_alpha_typhoon.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Allow callers of typhoon_init() to specify a minimum PCI devfn.

Add a minimal i82378 SIO PCI node so that NetBSD/alpha will find
and probe the ISA bus.

--- hw/alpha/typhoon.c.orig	2020-10-01 00:34:35.392982214 +0000
+++ hw/alpha/typhoon.c	2020-10-01 00:53:13.419539599 +0000
@@ -817,7 +817,8 @@ static void typhoon_alarm_timer(void *op
 }
 
 PCIBus *typhoon_init(MemoryRegion *ram, ISABus **isa_bus, qemu_irq *p_rtc_irq,
-                     AlphaCPU *cpus[4], pci_map_irq_fn sys_map_irq)
+                     AlphaCPU *cpus[4], pci_map_irq_fn sys_map_irq,
+                     uint8_t devfn_min)
 {
     MemoryRegion *addr_space = get_system_memory();
     DeviceState *dev;
@@ -887,7 +888,7 @@ PCIBus *typhoon_init(MemoryRegion *ram, 
     b = pci_register_root_bus(dev, "pci",
                               typhoon_set_irq, sys_map_irq, s,
                               &s->pchip.reg_mem, &s->pchip.reg_io,
-                              0, 64, TYPE_PCI_BUS);
+                              devfn_min, 64, TYPE_PCI_BUS);
     phb->bus = b;
     sysbus_realize_and_unref(SYS_BUS_DEVICE(dev), &error_fatal);
 
@@ -921,10 +922,21 @@ PCIBus *typhoon_init(MemoryRegion *ram, 
     /* Pchip1 PCI configuration, 0x802.FE00.0000, 16MB.  */
 
     /* Init the ISA bus.  */
-    /* ??? Technically there should be a cy82c693ub pci-isa bridge.  */
+    /* Init the PCI-ISA bridge.  Technically, this would have been
+       a cy82c693ub, but a i82378 SIO was also used on many Alpha
+       systems and is close enough.
+
+       ??? We are using a private, stripped down implementation of i82378
+       so that we can handle the way the ISA interrupts are wired up on
+       Tsunami-type systems.  We're leaving that (and the rest of the board
+       peripheral setup) untoucned; we merely need to instantiate the PCI
+       device node for the bridge, so that operating systems that expect
+       it to be there will see it.  */
     {
         qemu_irq *isa_irqs;
 
+        pci_create_simple(b, PCI_DEVFN(7, 0), "i82378-typhoon");
+
         *isa_bus = isa_bus_new(NULL, get_system_memory(), &s->pchip.reg_io,
                                &error_abort);
         isa_irqs = i8259_init(*isa_bus,
@@ -955,10 +967,96 @@ static const TypeInfo typhoon_iommu_memo
     .class_init = typhoon_iommu_memory_region_class_init,
 };
 
+/* The following was copied from hw/isa/i82378.c and modified to provide
+   only the minimal PCI device node.  */
+
+/*                            
+ * QEMU Intel i82378 emulation (PCI to ISA bridge) 
+ *                            
+ * Copyright (c) 2010-2011 Herv\xc3\xa9 Poussineau
+ *  
+ * This library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2 of the License, or (at your option) any later version.
+ *  
+ * This library is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *     
+ * You should have received a copy of the GNU Lesser General Public
+ * License along with this library; if not, see <http://www.gnu.org/licenses/>.
+ */    
+
+#include "migration/vmstate.h"
+
+#define TYPE_I82378 "i82378-typhoon"
+#define I82378(obj) \
+    OBJECT_CHECK(I82378State, (obj), TYPE_I82378)
+
+typedef struct I82378State {
+    PCIDevice parent_obj;
+} I82378State;
+
+static const VMStateDescription vmstate_i82378 = {
+    .name = "pci-i82378-typhoon",
+    .version_id = 0,
+    .minimum_version_id = 0,
+    .fields = (VMStateField[]) {
+        VMSTATE_PCI_DEVICE(parent_obj, I82378State), 
+        VMSTATE_END_OF_LIST()
+    },                        
+};                            
+
+static void i82378_realize(PCIDevice *pci, Error **errp)
+{
+    uint8_t *pci_conf;
+ 
+    pci_conf = pci->config;
+    pci_set_word(pci_conf + PCI_COMMAND,
+                 PCI_COMMAND_IO | PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER);
+    pci_set_word(pci_conf + PCI_STATUS,
+                 PCI_STATUS_DEVSEL_MEDIUM);
+ 
+    pci_config_set_interrupt_pin(pci_conf, 1); /* interrupt pin 0 */
+}
+
+static void i82378_init(Object *obj)
+{
+}      
+
+static void i82378_class_init(ObjectClass *klass, void *data)
+{   
+    PCIDeviceClass *k = PCI_DEVICE_CLASS(klass);
+    DeviceClass *dc = DEVICE_CLASS(klass);
+
+    k->realize = i82378_realize; 
+    k->vendor_id = PCI_VENDOR_ID_INTEL;
+    k->device_id = PCI_DEVICE_ID_INTEL_82378;
+    k->revision = 0x03;
+    k->class_id = PCI_CLASS_BRIDGE_ISA;
+    dc->vmsd = &vmstate_i82378;
+    set_bit(DEVICE_CATEGORY_BRIDGE, dc->categories);
+}                             
+
+static const TypeInfo i82378_typhoon_type_info = {
+    .name = TYPE_I82378,
+    .parent = TYPE_PCI_DEVICE,
+    .instance_size = sizeof(I82378State),
+    .instance_init = i82378_init,
+    .class_init = i82378_class_init,
+    .interfaces = (InterfaceInfo[]) {
+        { INTERFACE_CONVENTIONAL_PCI_DEVICE },
+        { },     
+    },
+};  
+
 static void typhoon_register_types(void)
 {
     type_register_static(&typhoon_pcihost_info);
     type_register_static(&typhoon_iommu_memory_region_info);
+    type_register_static(&i82378_typhoon_type_info);
 }
 
 type_init(typhoon_register_types)
