$NetBSD: patch-roms_qemu-palcode_sys-clipper.h,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Povide PCI device interrupt mapping information.

--- roms/qemu-palcode/sys-clipper.h.orig	2020-10-04 17:10:06.597880613 +0000
+++ roms/qemu-palcode/sys-clipper.h	2020-10-04 17:10:33.149119398 +0000
@@ -27,4 +27,31 @@
 #define SYS_VARIATION	(5 << 10)
 #define SYS_REVISION	0
 
+#ifndef __ASSEMBLER__
+
+#define MAP_PCI_INTERRUPT(SLOT, PIN, CLASS_ID)				\
+({									\
+  int IRQ;								\
+    									\
+  if (CLASS_ID == 0x0601)						\
+    {									\
+      /* PCI-ISA bridge is hard-wired to IRQ 55 on real hardware,	\
+	 and comes in at a different SCB vector; force the line		\
+         register to -1.  */						\
+      IRQ = -1;								\
+    }									\
+  else if (PIN >= 1 && PIN <= 4)					\
+    {									\
+      /* See hw/alpha/dp264.c:clipper_pci_map_irq()  */			\
+      IRQ = (SLOT + 1) * 4 + (PIN - 1);					\
+    }									\
+  else									\
+    {									\
+      IRQ = -1;								\
+    }									\
+  IRQ;									\
+})
+
+#endif /* ! __ASSEMBLER__ */
+
 #endif
