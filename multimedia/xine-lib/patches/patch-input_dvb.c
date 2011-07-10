$NetBSD: patch-input_dvb.c,v 1.1 2011/07/10 16:52:25 jmcneill Exp $

--- src/input/input_dvb.c.orig	2010-07-24 22:09:09.000000000 +0000
+++ src/input/input_dvb.c
@@ -97,9 +97,13 @@
 #endif
 #include <ctype.h>
 
+#ifdef HAVE_DEV_DTV_DTVIO_H
+#include <dev/dtv/dtvio.h>
+#else
 /* These will eventually be #include <linux/dvb/...> */
 #include "dvb/dmx.h"
 #include "dvb/frontend.h"
+#endif
 
 #define LOG_MODULE "input_dvb"
 #define LOG_VERBOSE
