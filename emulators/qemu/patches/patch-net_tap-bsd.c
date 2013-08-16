$NetBSD: patch-net_tap-bsd.c,v 1.5 2013/08/16 21:20:11 adam Exp $

Make it understand "-net tap,ifname=tap3" on NetBSD.

--- net/tap-bsd.c.orig	2013-08-15 19:56:23.000000000 +0000
+++ net/tap-bsd.c
@@ -45,6 +45,7 @@ int tap_open(char *ifname, int ifname_si
 #endif
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
+    defined(__NetBSD__) || \
     defined(__OpenBSD__) || defined(__APPLE__)
     /* if no ifname is given, always start the search from tap0/tun0. */
     int i;
