$NetBSD: patch-util_scan_diseqc.h,v 1.1.1.1 2011/07/13 23:42:16 jmcneill Exp $

--- util/scan/diseqc.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/scan/diseqc.h
@@ -2,7 +2,11 @@
 #define __DISEQC_H__
 
 #include <stdint.h>
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
+#endif
 
 
 struct diseqc_cmd {
