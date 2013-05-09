$NetBSD: patch-src_daemon_interfaces-bsd.c,v 1.1 2013/05/09 06:55:57 mef Exp $

Add DragonFly support
(net/agr/if_agrioctl.h is missing, to be added).

--- src/daemon/interfaces-bsd.c~	2013-04-13 17:18:24.000000000 +0900
+++ src/daemon/interfaces-bsd.c	2013-05-09 15:08:27.911845000 +0900
@@ -39,6 +39,9 @@
 # include <net/if_vlanvar.h>
 # include <net/if_bridgevar.h>
 # include <net/agr/if_agrioctl.h>
+#elif defined HOST_OS_DRAGONFLY
+# include <net/vlan/if_vlan_var.h>
+# include <net/bridge/if_bridgevar.h>
 #elif defined HOST_OS_OSX
 # include <osx/if_vlan_var.h>
 # include <osx/if_bridgevar.h>
@@ -74,7 +77,7 @@
 		.ifbic_req = req
 	};
 
-#if defined HOST_OS_FREEBSD || defined HOST_OS_NETBSD || defined HOST_OS_OSX
+#if defined HOST_OS_FREEBSD || defined HOST_OS_NETBSD || defined HOST_OS_OSX || defined HOST_OS_DRAGONFLY
 	struct ifdrv ifd = {
 		.ifd_cmd = BRDGGIFS,
 		.ifd_len = sizeof(bifc),
@@ -163,7 +166,7 @@
 		slave->upper = master;
 	}
 	master->type |= IFACE_BOND_T;
-#elif defined HOST_OS_NETBSD
+#elif defined HOST_OS_NETBSD  || defined HOST_OS_DRAGONFLY
 	/* No max, we consider a maximum of 24 ports */
 	char buf[sizeof(struct agrportinfo)*24] = {};
 	size_t buflen = sizeof(buf);
