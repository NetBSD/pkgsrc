$NetBSD: patch-tools_qemu-xen-traditional_xen-hooks.mak,v 1.1 2020/05/26 11:12:11 bouyer Exp $

enable PCI passthrough when pciutils is present

--- tools/qemu-xen-traditional/xen-hooks.mak.orig	2017-09-15 20:37:27.000000000 +0200
+++ tools/qemu-xen-traditional/xen-hooks.mak	2018-04-23 16:01:41.000000000 +0200
@@ -26,11 +26,11 @@
 LIBS += -L$(XEN_ROOT)/tools/libs/gnttab -lxengnttab
 LIBS += -L$(XEN_ROOT)/tools/libxc -lxenctrl -lxenguest
 LIBS += -L$(XEN_ROOT)/tools/xenstore -lxenstore
-LIBS += -Wl,-rpath-link=$(XEN_ROOT)/tools/libs/toollog
-LIBS += -Wl,-rpath-link=$(XEN_ROOT)/tools/libs/toolcore
-LIBS += -Wl,-rpath-link=$(XEN_ROOT)/tools/libs/call
-LIBS += -Wl,-rpath-link=$(XEN_ROOT)/tools/libs/foreignmemory
-LIBS += -Wl,-rpath-link=$(XEN_ROOT)/tools/libs/devicemodel
+LIBS += -Wl,-rpath-link,$(XEN_ROOT)/tools/libs/toollog
+LIBS += -Wl,-rpath-link,$(XEN_ROOT)/tools/libs/toolcore
+LIBS += -Wl,-rpath-link,$(XEN_ROOT)/tools/libs/call
+LIBS += -Wl,-rpath-link,$(XEN_ROOT)/tools/libs/foreignmemory
+LIBS += -Wl,-rpath-link,$(XEN_ROOT)/tools/libs/devicemodel
 
 LDFLAGS := $(CFLAGS) $(LDFLAGS)
 
@@ -71,17 +71,25 @@
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
