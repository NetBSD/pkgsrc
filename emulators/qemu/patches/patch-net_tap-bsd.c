$NetBSD: patch-net_tap-bsd.c,v 1.2 2012/09/11 17:13:45 asau Exp $

Make it understand "-net tap,ifname=tap3" on NetBSD.

--- net/tap-bsd.c.orig	2012-09-05 14:03:06.000000000 +0000
+++ net/tap-bsd.c
@@ -43,7 +43,7 @@ int tap_open(char *ifname, int ifname_si
     struct stat s;
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__NetBSD__)
     /* if no ifname is given, always start the search from tap0/tun0. */
     int i;
     char dname[100];
