$NetBSD: patch-src_fillmac.c,v 1.1 2012/06/14 17:16:23 fhajny Exp $

SIOCGIFHWADDR defined on recent SunOS, doesn't have the usual structure.
--- src/fillmac.c.orig	2007-07-04 13:34:59.000000000 +0000
+++ src/fillmac.c
@@ -43,7 +43,7 @@ int fill_mac_address(void)
                 strerror(errno));
         return -1;
     }
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
     {
         struct ifreq ifr;
         
