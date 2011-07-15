$NetBSD: patch-lib_libdvbapi_dvbnet.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libdvbapi/dvbnet.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libdvbapi/dvbnet.c
@@ -25,7 +25,11 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/net.h>
+#endif
 #include <errno.h>
 #include "dvbnet.h"
 
@@ -46,6 +50,7 @@ int dvbnet_open(int adapter, int netdevi
 
 int dvbnet_add_interface(int fd, uint16_t pid, enum dvbnet_encap encapsulation)
 {
+#ifdef NET_ADD_IF
 	struct dvb_net_if params;
 	int status;
 
@@ -69,10 +74,14 @@ int dvbnet_add_interface(int fd, uint16_
 	if (status < 0)
 		return status;
 	return params.if_num;
+#else
+	return -1;
+#endif
 }
 
 int dvbnet_get_interface(int fd, int ifnum, uint16_t *pid, enum dvbnet_encap *encapsulation)
 {
+#ifdef NET_GET_IF
 	struct dvb_net_if info;
 	int res;
 
@@ -96,9 +105,16 @@ int dvbnet_get_interface(int fd, int ifn
 		return -EINVAL;
 	}
 	return 0;
+#else
+	return -1;
+#endif
 }
 
 int dvbnet_remove_interface(int fd, int ifnum)
 {
+#ifdef NET_REMOVE_IF
 	return ioctl(fd, NET_REMOVE_IF, ifnum);
+#else
+	return -1;
+#endif
 }
