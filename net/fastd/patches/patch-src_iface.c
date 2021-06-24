$NetBSD: patch-src_iface.c,v 1.1 2021/06/24 14:01:31 nia Exp $

Add support for NetBSD.

--- src/iface.c.orig	2020-10-19 19:24:26.000000000 +0000
+++ src/iface.c
@@ -338,7 +338,7 @@ static void cleanup_iface(UNUSED fastd_i
 
 #endif
 
-#elif __APPLE__
+#elif defined(__APPLE__) || defined(__NetBSD__)
 
 /** Opens the TUN/TAP device */
 static bool open_iface(fastd_iface_t *iface, const char *ifname, uint16_t mtu) {
