$NetBSD: patch-plugins_sysinfo_unix_parse.c,v 1.1 2016/08/16 08:30:14 tnn Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/unix/parse.c.orig	2016-03-20 01:05:19.000000000 +0000
+++ plugins/sysinfo/unix/parse.c
@@ -23,7 +23,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
-#include <pci/header.h>
+#include <pciutils/header.h>
 #include <glib.h>
 
 #ifdef __sparc__
