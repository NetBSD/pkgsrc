$NetBSD: patch-lib_libdvbapi_dvbdemux.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libdvbapi/dvbdemux.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libdvbapi/dvbdemux.c
@@ -27,7 +27,11 @@
 #include <unistd.h>
 #include <ctype.h>
 #include <errno.h>
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/dmx.h>
+#endif
 #include "dvbdemux.h"
 
 
