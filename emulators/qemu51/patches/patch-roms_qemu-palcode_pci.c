$NetBSD: patch-roms_qemu-palcode_pci.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

- Move PCI_DEVFN(), PCI_BUS(), PCI_SLOT(), and PCI_FUNC() to pci.h.
- Improve debug/info messages.
- Only program a BAR as a 64-bit MEM BAR if it really is a 64-bit MEM BAR.
  Fixes an issue with the CMD646 IDE controller under NetBSD.
- Use system-specific information to program the interrupt line register
  with the interrupt mappings, which is what the SRM console does on real
  hardware; some operating systems (e.g. NetBSD) use this information
  rather than having interrupt mapping tables for every possible system
  variation.

--- roms/qemu-palcode/pci.c.orig	2020-10-04 16:41:22.923562768 +0000
+++ roms/qemu-palcode/pci.c	2020-10-04 16:41:58.183954279 +0000
@@ -29,12 +29,9 @@
 #include "protos.h"
 #include "pci.h"
 #include "pci_regs.h"
+#include SYSTEM_H
 
 
-#define PCI_DEVFN(slot, func)	((((slot) & 0x1f) << 3) | ((func) & 0x07))
-#define PCI_BUS(devfn)		((devfn) >> 8)
-#define PCI_SLOT(devfn)		(((devfn) >> 3) & 0x1f)
-#define PCI_FUNC(devfn)		((devfn) & 0x07)
 #define PCI_SLOT_MAX		32
 #define PCI_FUNC_MAX		8
 #define PCI_REGION_ROM		6
@@ -88,7 +85,7 @@ pci_setup_device(int bdf, uint32_t *p_io
   device_id = pci_config_readw(bdf, PCI_DEVICE_ID);
   class_id = pci_config_readw(bdf, PCI_CLASS_DEVICE);
 
-  printf("PCI: %02x:%02x:%x class %04x id %04x:%04x\r\n",
+  printf("PCI: %d:%d:%d class %04x id %04x:%04x\r\n",
 	 PCI_BUS(bdf), PCI_SLOT(bdf), PCI_FUNC(bdf),
          class_id, vendor_id, device_id);
 
@@ -122,9 +119,11 @@ pci_setup_device(int bdf, uint32_t *p_io
 	  *p_base = addr + size;
 	  pci_config_writel(bdf, ofs, addr);
 
-	  printf("PCI:   region %d: %08x\r\n", region, addr);
+	  printf("PCI:   region %d (BAR %02x): %08x\r\n",
+	         region, ofs, addr);
 
-	  if ((val & PCI_BASE_ADDRESS_MEM_TYPE_MASK)
+	  if ((old & PCI_BASE_ADDRESS_SPACE_IO) == 0 &&
+	      (old & PCI_BASE_ADDRESS_MEM_TYPE_MASK)
 	      == PCI_BASE_ADDRESS_MEM_TYPE_64)
 	    {
 	      pci_config_writel(bdf, ofs + 4, 0);
@@ -135,7 +134,25 @@ pci_setup_device(int bdf, uint32_t *p_io
 
   pci_config_maskw(bdf, PCI_COMMAND, 0, PCI_COMMAND_IO | PCI_COMMAND_MEMORY);
 
-  /* Map the interrupt.  */
+  /* Map the interrupt and program the IRQ into the line register.
+     Some operating systems rely on the Console providing this information
+     in order to avoid having mapping tables for every possible system
+     variation.  */
+
+  const uint8_t pin = pci_config_readb(bdf, PCI_INTERRUPT_PIN);
+  const uint8_t slot = PCI_SLOT(bdf);
+  const int irq = MAP_PCI_INTERRUPT(slot, pin, class_id);
+
+  if (irq == -1)
+    {
+      /* No interrupt mapping.  */
+      pci_config_writeb(bdf, PCI_INTERRUPT_LINE, 0xff);
+    }
+  else
+    {
+      printf("PCI:   intr pin %d -> irq %d\r\n", pin, irq);
+      pci_config_writeb(bdf, PCI_INTERRUPT_LINE, irq);
+    }
 }
 
 void
