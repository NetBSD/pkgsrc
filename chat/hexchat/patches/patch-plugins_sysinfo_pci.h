$NetBSD: patch-plugins_sysinfo_pci.h,v 1.1 2015/02/15 17:41:24 khorben Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/pci.h.orig	2014-06-01 16:11:26.000000000 +0000
+++ plugins/sysinfo/pci.h
@@ -21,7 +21,7 @@
 #ifndef _PCI_H_
 #define _PCI_H_
 
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 void pci_find_fullname(char *fullname, char *vendor, char *device);
 int  pci_find_by_class(u16 *class, char *vendor, char *device);
 
