$NetBSD: patch-ioemu-qemu-xen_xen-hooks.mak,v 1.1 2012/05/29 15:01:34 bouyer Exp $

enable PCI passthrough when pciutils is present

--- ioemu-qemu-xen/xen-hooks.mak.orig	2012-05-24 15:41:11.000000000 +0200
+++ ioemu-qemu-xen/xen-hooks.mak	2012-05-24 15:46:21.000000000 +0200
@@ -55,17 +55,25 @@
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
