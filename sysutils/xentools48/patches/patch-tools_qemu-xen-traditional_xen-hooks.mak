$NetBSD: patch-tools_qemu-xen-traditional_xen-hooks.mak,v 1.1 2017/03/30 09:15:10 bouyer Exp $

enable PCI passthrough when pciutils is present

--- tools/qemu-xen-traditional/xen-hooks.mak.orig	2016-11-29 17:36:38.000000000 +0100
+++ tools/qemu-xen-traditional/xen-hooks.mak	2017-03-24 20:09:07.000000000 +0100
@@ -25,9 +25,9 @@
 LIBS += -L$(XEN_ROOT)/tools/libs/gnttab -lxengnttab
 LIBS += -L$(XEN_ROOT)/tools/libxc -lxenctrl -lxenguest
 LIBS += -L$(XEN_ROOT)/tools/xenstore -lxenstore
-LIBS += -Wl,-rpath-link=$(XEN_ROOT)/tools/libs/toollog
-LIBS += -Wl,-rpath-link=$(XEN_ROOT)/tools/libs/call
-LIBS += -Wl,-rpath-link=$(XEN_ROOT)/tools/libs/foreignmemory
+LIBS += -Wl,-rpath-link,$(XEN_ROOT)/tools/libs/toollog
+LIBS += -Wl,-rpath-link,$(XEN_ROOT)/tools/libs/call
+LIBS += -Wl,-rpath-link,$(XEN_ROOT)/tools/libs/foreignmemory
 
 LDFLAGS := $(CFLAGS) $(LDFLAGS)
 
@@ -68,17 +68,25 @@
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
