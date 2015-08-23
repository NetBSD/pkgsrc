$NetBSD: patch-qemu-xen-traditional_xen-hooks.mak,v 1.2 2015/08/23 16:17:12 spz Exp $

enable PCI passthrough when pciutils is present

--- qemu-xen-traditional/xen-hooks.mak.orig	2014-01-09 12:44:42.000000000 +0000
+++ qemu-xen-traditional/xen-hooks.mak
@@ -57,17 +57,25 @@ endif
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
