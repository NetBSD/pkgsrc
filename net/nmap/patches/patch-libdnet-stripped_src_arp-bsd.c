$NetBSD: patch-libdnet-stripped_src_arp-bsd.c,v 1.1 2016/04/09 06:38:05 adam Exp $

Fix building on systems where RTF_LLINFO is not defined.

--- libdnet-stripped/src/arp-bsd.c.orig	2016-04-09 06:32:03.612302485 +0000
+++ libdnet-stripped/src/arp-bsd.c
@@ -22,6 +22,9 @@
 #include <net/if.h>
 #include <net/if_dl.h>
 #include <net/route.h>
+#ifndef RTF_LLINFO
+#define RTF_LLINFO RTF_LLDATA
+#endif
 #include <netinet/in.h>
 #include <netinet/if_ether.h>
 
