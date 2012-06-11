$NetBSD: patch-stream_dvb_tune.c,v 1.2 2012/06/11 21:55:34 wiz Exp $

Add support for dvb capture on NetBSD.

--- stream/dvb_tune.c.orig	2010-03-02 19:57:17.000000000 +0000
+++ stream/dvb_tune.c
@@ -32,8 +32,12 @@
 #include <fcntl.h>
 #include <time.h>
 #include <errno.h>
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/dmx.h>
 #include <linux/dvb/frontend.h>
+#endif
 #include "config.h"
 #include "dvbin.h"
 #include "dvb_tune.h"
