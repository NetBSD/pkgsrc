$NetBSD: patch-openbsd-compat_port-tun.c,v 1.4 2019/01/18 20:13:37 tnn Exp $

if_tun.h can be found in net/tun

--- openbsd-compat/port-net.c.orig	2018-10-17 00:01:20.000000000 +0000
+++ openbsd-compat/port-net.c
@@ -1,3 +1,4 @@
+
 /*
  * Copyright (c) 2005 Reyk Floeter <reyk@openbsd.org>
  *
@@ -200,6 +201,10 @@ sys_tun_open(int tun, int mode, char **i
 #include <sys/socket.h>
 #include <net/if.h>
 
+#ifdef HAVE_NET_TUN_IF_TUN_H
+#include <net/tun/if_tun.h>
+#endif
+
 #ifdef HAVE_NET_IF_TUN_H
 #include <net/if_tun.h>
 #endif
@@ -209,7 +214,10 @@ sys_tun_open(int tun, int mode, char **i
 {
 	struct ifreq ifr;
 	char name[100];
-	int fd = -1, sock, flag;
+	int fd = -1, sock;
+#if defined(TUNSIFHEAD) && !defined(SSH_TUN_PREPEND_AF)
+	int flag;
+#endif
 	const char *tunbase = "tun";
 
 	if (ifname != NULL)
@@ -246,9 +254,9 @@ sys_tun_open(int tun, int mode, char **i
 		return (-1);
 	}
 
+#if defined(TUNSIFHEAD) && !defined(SSH_TUN_PREPEND_AF)
 	/* Turn on tunnel headers */
 	flag = 1;
-#if defined(TUNSIFHEAD) && !defined(SSH_TUN_PREPEND_AF)
 	if (mode != SSH_TUNMODE_ETHERNET &&
 	    ioctl(fd, TUNSIFHEAD, &flag) == -1) {
 		debug("%s: ioctl(%d, TUNSIFHEAD, 1): %s", __func__, fd,
