$NetBSD: patch-util_scan_dump-zap.c,v 1.1.1.1 2011/07/13 23:42:16 jmcneill Exp $

--- util/scan/dump-zap.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/scan/dump-zap.c
@@ -1,5 +1,9 @@
 #include <stdio.h>
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
+#endif
 #include "dump-zap.h"
 
 static const char *inv_name [] = {
