$NetBSD: patch-net.h,v 1.4 2017/06/26 14:41:37 wiz Exp $

Assumes that SCTP is available everywhere.
At least let it compile on older systems.
https://github.com/traviscross/mtr/issues/141

--- net.h.orig	2014-12-09 11:19:43.000000000 +0000
+++ net.h
@@ -26,6 +26,10 @@
 #include <netinet/icmp6.h>
 #endif
 
+#ifndef IPPROTO_SCTP
+#define	IPPROTO_SCTP	132
+#endif
+
 int net_preopen(void);
 int net_selectsocket(void);
 int net_open(struct hostent *host);
