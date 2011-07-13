$NetBSD: patch-util_scan_dump-zap.h,v 1.1.1.1 2011/07/13 23:42:16 jmcneill Exp $

--- util/scan/dump-zap.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/scan/dump-zap.h
@@ -2,7 +2,11 @@
 #define __DUMP_ZAP_H__
 
 #include <stdint.h>
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
+#endif
 
 extern void zap_dump_dvb_parameters (FILE *f, fe_type_t type,
 		struct dvb_frontend_parameters *t, char polarity, int sat);
