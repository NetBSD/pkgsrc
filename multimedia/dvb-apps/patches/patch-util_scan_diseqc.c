$NetBSD: patch-util_scan_diseqc.c,v 1.1.1.1 2011/07/13 23:42:16 jmcneill Exp $

--- util/scan/diseqc.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/scan/diseqc.c
@@ -1,4 +1,8 @@
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
+#endif
 #include <sys/ioctl.h>
 #include <time.h>
 
