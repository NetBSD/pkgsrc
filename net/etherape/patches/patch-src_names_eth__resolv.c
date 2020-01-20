$NetBSD: patch-src_names_eth__resolv.c,v 1.1 2020/01/20 02:47:43 nia Exp $

Build on NetBSD.

--- src/names/eth_resolv.c.orig	2018-04-14 16:45:39.000000000 +0000
+++ src/names/eth_resolv.c
@@ -26,8 +26,12 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifdef __NetBSD__
+#include <net/if_ether.h>
+#else
 #include <net/ethernet.h>
 #include <netinet/ether.h>
+#endif
 
 #include <glib.h>
 
