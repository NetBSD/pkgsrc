$NetBSD: patch-tools_qemu-xen-traditional_xen-hooks.mak,v 1.1 2021/04/18 12:31:26 bouyer Exp $

enable PCI passthrough when pciutils is present

--- tools/qemu-xen-traditional/xen-hooks.mak.orig	2020-12-08 16:54:20.000000000 +0100
+++ tools/qemu-xen-traditional/xen-hooks.mak	2020-12-09 16:07:04.817171636 +0100
@@ -61,17 +61,25 @@
 ifdef CONFIG_STUBDOM
 CONFIG_PASSTHROUGH=1
 else
-  ifeq (,$(wildcard /usr/include/pci))
+  ifeq ($(CONFIG_NetBSD), y)
+CONFIG_PASSTHROUGH=1
+  else
+    ifeq (,$(wildcard /usr/include/pci))
 $(warning === pciutils-dev package not found - missing /usr/include/pci)
 $(warning === PCI passthrough capability has been disabled)
-  else
+    else
 CONFIG_PASSTHROUGH=1
+    endif
   endif
 endif
 
 ifdef CONFIG_PASSTHROUGH
 OBJS+= pass-through.o pt-msi.o pt-graphics.o
+ifeq ($(CONFIG_NetBSD), y)
+LIBS += -Wl,-R${PREFIX}/lib -L${PREFIX}/lib -lpciutils -lpci
+else
 LIBS += -lpci
+endif
 CFLAGS += -DCONFIG_PASSTHROUGH 
 $(info === PCI passthrough capability has been enabled ===)
 endif
