$NetBSD: patch-net_tap-bsd.c,v 1.4 2013/07/09 17:00:58 tsutsui Exp $

Make it understand "-net tap,ifname=tap3" on NetBSD.

--- net/tap-bsd.c.orig	2013-06-26 21:47:29.000000000 +0000
+++ net/tap-bsd.c
@@ -44,7 +44,7 @@ int tap_open(char *ifname, int ifname_si
     struct stat s;
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__NetBSD__)
     /* if no ifname is given, always start the search from tap0/tun0. */
     int i;
     char dname[100];
