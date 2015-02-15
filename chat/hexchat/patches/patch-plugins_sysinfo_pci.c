$NetBSD: patch-plugins_sysinfo_pci.c,v 1.1 2015/02/15 17:41:24 khorben Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/pci.c.orig	2014-06-01 16:11:26.000000000 +0000
+++ plugins/sysinfo/pci.c
@@ -24,7 +24,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <unistd.h>
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 #include "xsys.h"
 
 static struct pci_filter filter;       /* Device filter */
