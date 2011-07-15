$NetBSD: patch-util_szap_czap.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- util/szap/czap.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/szap/czap.c
@@ -10,8 +10,12 @@
 #include <ctype.h>
 #include <errno.h>
 
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
 #include <linux/dvb/dmx.h>
+#endif
 
 #include "util.h"
 
