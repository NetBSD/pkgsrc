$NetBSD: patch-openbsd-compat_port-tun.c,v 1.1.18.1 2015/07/14 22:03:39 tron Exp $

if_tun.h can be found in net/tun

--- openbsd-compat/port-tun.c.orig	2015-07-01 02:35:31.000000000 +0000
+++ openbsd-compat/port-tun.c
@@ -111,6 +111,10 @@ sys_tun_open(int tun, int mode)
 #include <sys/socket.h>
 #include <net/if.h>
 
+#ifdef HAVE_NET_TUN_IF_TUN_H
+#include <net/tun/if_tun.h>
+#endif
+
 #ifdef HAVE_NET_IF_TUN_H
 #include <net/if_tun.h>
 #endif
@@ -120,7 +124,10 @@ sys_tun_open(int tun, int mode)
 {
 	struct ifreq ifr;
 	char name[100];
-	int fd = -1, sock, flag;
+	int fd = -1, sock;
+#if defined(TUNSIFHEAD) && !defined(SSH_TUN_PREPEND_AF)
+	int flag;
+#endif
 	const char *tunbase = "tun";
 
 	if (mode == SSH_TUNMODE_ETHERNET) {
@@ -154,9 +161,9 @@ sys_tun_open(int tun, int mode)
 		return (-1);
 	}
 
+#if defined(TUNSIFHEAD) && !defined(SSH_TUN_PREPEND_AF)
 	/* Turn on tunnel headers */
 	flag = 1;
-#if defined(TUNSIFHEAD) && !defined(SSH_TUN_PREPEND_AF)
 	if (mode != SSH_TUNMODE_ETHERNET &&
 	    ioctl(fd, TUNSIFHEAD, &flag) == -1) {
 		debug("%s: ioctl(%d, TUNSIFHEAD, 1): %s", __func__, fd,
