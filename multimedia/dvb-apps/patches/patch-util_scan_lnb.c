$NetBSD: patch-util_scan_lnb.c,v 1.1.1.1 2011/07/13 23:42:16 jmcneill Exp $

--- util/scan/lnb.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/scan/lnb.c
@@ -1,7 +1,11 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#ifdef __linux__
 #include <linux/types.h>
+#else
+#include <sys/types.h>
+#endif
 #include "lnb.h"
 
 static char *univ_desc[] = {
