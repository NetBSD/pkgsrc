$NetBSD: patch-src_daemon_priv.c,v 1.1 2013/05/09 05:42:53 mef Exp $

Add DragonFly support.

--- src/daemon/priv.c.orig	2013-05-09 12:26:14.352290000 +0900
+++ src/daemon/priv.c	2013-05-09 12:27:54.003821000 +0900
@@ -42,6 +42,7 @@
 #endif
 #if defined HOST_OS_FREEBSD || \
 	    HOST_OS_NETBSD || \
+	    HOST_OS_DRAGONFLY || \
 	    HOST_OS_OPENBSD || \
 	    HOST_OS_OSX
 # include <net/bpf.h>
@@ -406,6 +407,7 @@ asroot_iface_init()
 #elif defined HOST_OS_FREEBSD || \
       defined HOST_OS_OPENBSD || \
       defined HOST_OS_NETBSD  || \
+      defined HOST_OS_DRAGONFLY || \
       defined HOST_OS_OSX
 	int n = 0;
 	int enable, required;
@@ -538,7 +540,7 @@ asroot_iface_multicast()
 	dlp->sdl_alen = ETHER_ADDR_LEN;
 	dlp->sdl_slen = 0;
 	must_read(remote, LLADDR(dlp), ETHER_ADDR_LEN);
-#elif defined HOST_OS_OPENBSD || defined HOST_OS_NETBSD
+#elif defined HOST_OS_OPENBSD || defined HOST_OS_NETBSD || defined HOST_OS_DRAGONFLY
 	struct sockaddr *sap = (struct sockaddr *)&ifr.ifr_addr;
 	sap->sa_len = sizeof(struct sockaddr);
 	sap->sa_family = AF_UNSPEC;
