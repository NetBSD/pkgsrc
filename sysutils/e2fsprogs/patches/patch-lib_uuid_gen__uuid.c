$NetBSD: patch-lib_uuid_gen__uuid.c,v 1.2 2025/01/21 18:13:57 triaxx Exp $

Fix build on SunOS.

--- lib/uuid/gen_uuid.c.orig	2016-09-02 04:17:32.000000000 +0000
+++ lib/uuid/gen_uuid.c
@@ -254,7 +254,7 @@ static int get_node_id(unsigned char *no
 	for (i = 0; i < n; i+= ifreq_size(*ifrp) ) {
 		ifrp = (struct ifreq *)((char *) ifc.ifc_buf+i);
 		strncpy(ifr.ifr_name, ifrp->ifr_name, IFNAMSIZ);
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 		if (ioctl(sd, SIOCGIFHWADDR, &ifr) < 0)
 			continue;
 		a = (unsigned char *) &ifr.ifr_hwaddr.sa_data;
