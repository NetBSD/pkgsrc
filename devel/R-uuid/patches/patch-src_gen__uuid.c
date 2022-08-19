$NetBSD: patch-src_gen__uuid.c,v 1.1 2022/08/19 11:36:25 tnn Exp $

Solaris does not have ifr.ifr_hwaddr.

--- src/gen_uuid.c.orig	2022-04-19 04:03:43.000000000 +0000
+++ src/gen_uuid.c
@@ -145,7 +145,7 @@ static int get_node_id(unsigned char *no
 	for (i = 0; i < n; i+= ifreq_size(*ifrp) ) {
 		ifrp = (struct ifreq *)((char *) ifc.ifc_buf+i);
 		strncpy(ifr.ifr_name, ifrp->ifr_name, IFNAMSIZ);
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 		if (ioctl(sd, SIOCGIFHWADDR, &ifr) < 0)
 			continue;
 		a = (unsigned char *) &ifr.ifr_hwaddr.sa_data;
