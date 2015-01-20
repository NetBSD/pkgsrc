$NetBSD: patch-qemu-xen-traditional_xen-hooks.mak,v 1.1 2015/01/20 16:42:13 bouyer Exp $

enable PCI passthrough when pciutils is present

--- qemu-xen-traditional/xen-hooks.mak.orig	2014-10-06 17:50:24.000000000 +0200
+++ qemu-xen-traditional/xen-hooks.mak	2015-01-19 13:16:38.000000000 +0100
@@ -59,17 +59,25 @@
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
+LIBS += -lpciutils -lpci
+else
 LIBS += -lpci
+endif
 CFLAGS += -DCONFIG_PASSTHROUGH 
 $(info === PCI passthrough capability has been enabled ===)
 endif
