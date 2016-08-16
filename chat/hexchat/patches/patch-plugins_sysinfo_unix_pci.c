$NetBSD: patch-plugins_sysinfo_unix_pci.c,v 1.1 2016/08/16 08:30:14 tnn Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/unix/pci.c.orig	2016-03-20 01:05:19.000000000 +0000
+++ plugins/sysinfo/unix/pci.c
@@ -23,7 +23,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 #include <glib.h>
 
 #include "sysinfo.h"
