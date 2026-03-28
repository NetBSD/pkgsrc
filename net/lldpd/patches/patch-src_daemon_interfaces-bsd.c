$NetBSD: patch-src_daemon_interfaces-bsd.c,v 1.6 2026/03/28 11:06:18 kardel Exp $

SIOCGDRVSPEC needs struct ifdrv to query the bridge interfaces
fixes tight loop when scanning bridge interfaces

--- src/daemon/interfaces-bsd.c.orig	2025-08-30 18:02:39.000000000 +0000
+++ src/daemon/interfaces-bsd.c
@@ -86,19 +86,24 @@ retry_alloc:
 
 #if defined HOST_OS_FREEBSD || defined HOST_OS_NETBSD || defined HOST_OS_OSX || \
     defined HOST_OS_DRAGONFLY
-	struct ifdrv ifd = { .ifd_cmd = BRDGGIFS,
-		.ifd_len = sizeof(bifc),
-		.ifd_data = &bifc };
+	struct ifdrv ifd = {
+	        .ifd_cmd = BRDGGIFS,
+		.ifd_len = ifbic_len,
+		.ifd_data = req };
 
 	strlcpy(ifd.ifd_name, master->name, sizeof(ifd.ifd_name));
 	if (ioctl(cfg->g_sock, SIOCGDRVSPEC, (caddr_t)&ifd) < 0) {
 		log_debug("interfaces", "%s is not a bridge", master->name);
+		free(req);
 		return;
 	}
+	bifc.ifbic_len = ifd.ifd_len;
+	bifc.ifbic_req = ifd.ifd_data;
 #elif defined HOST_OS_OPENBSD
 	strlcpy(bifc.ifbic_name, master->name, sizeof(bifc.ifbic_name));
 	if (ioctl(cfg->g_sock, SIOCBRDGIFS, (caddr_t)&bifc) < 0) {
 		log_debug("interfaces", "%s is not a bridge", master->name);
+		free(bifc.ifbic_req);
 		return;
 	}
 #else
@@ -121,6 +126,7 @@ retry_alloc:
 		    master->name);
 		slave->upper = master;
 	}
+	free(bifc.ifbic_req);
 	master->type |= IFACE_BRIDGE_T;
 }
 
