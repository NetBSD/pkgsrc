$NetBSD: patch-util_szap_util.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- util/szap/util.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/szap/util.c
@@ -29,8 +29,12 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
 #include <linux/dvb/dmx.h>
+#endif
 
 
 int set_pesfilter(int dmxfd, int pid, int pes_type, int dvr)
