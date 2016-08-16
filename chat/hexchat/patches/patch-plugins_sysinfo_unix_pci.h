$NetBSD: patch-plugins_sysinfo_unix_pci.h,v 1.1 2016/08/16 08:30:14 tnn Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/unix/pci.h.orig	2016-03-20 01:05:19.000000000 +0000
+++ plugins/sysinfo/unix/pci.h
@@ -21,7 +21,7 @@
 #ifndef _PCI_H_
 #define _PCI_H_
 
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 void pci_find_fullname(char *fullname, char *vendor, char *device);
 int  pci_find_by_class(u16 *class, char *vendor, char *device);
 
