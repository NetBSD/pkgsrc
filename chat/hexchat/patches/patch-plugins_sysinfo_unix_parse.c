$NetBSD: patch-plugins_sysinfo_unix_parse.c,v 1.2 2018/03/17 11:56:15 tnn Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/unix/parse.c.orig	2018-03-14 02:27:13.000000000 +0000
+++ plugins/sysinfo/unix/parse.c
@@ -24,7 +24,7 @@
 #include <string.h>
 #include <ctype.h>
 #ifdef HAVE_LIBPCI
-	#include <pci/header.h>
+	#include <pciutils/header.h>
 	#include "pci.h"
 #endif
 #include <glib.h>
