$NetBSD: patch-net_tap-bsd.c,v 1.1 2012/08/03 17:51:47 asau Exp $

Make it understand "-net tap,ifname=tap3" on NetBSD.

--- net/tap-bsd.c.orig	2012-07-17 18:11:14.000000000 +0000
+++ net/tap-bsd.c
@@ -49,7 +49,7 @@ int tap_open(char *ifname, int ifname_si
     struct stat s;
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__NetBSD__)
     /* if no ifname is given, always start the search from tap0/tun0. */
     int i;
     char dname[100];
