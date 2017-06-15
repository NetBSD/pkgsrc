$NetBSD: patch-include_ntop__includes.h,v 1.2 2017/06/15 14:54:45 fhajny Exp $

Add NetBSD and SunOS support.

--- include/ntop_includes.h.orig	2016-06-27 19:31:18.000000000 +0000
+++ include/ntop_includes.h
@@ -43,7 +43,7 @@
 #include <arpa/inet.h>
 #include <poll.h>
 
-#if defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -51,6 +51,9 @@
 #include <net/if_arp.h>
 #include <netinet/if_ether.h>
 #include <netinet/in_systm.h>
+#elif defined(__sun)
+#include <netinet/in_systm.h>
+#include <sys/sockio.h>
 #else
 #include <net/ethernet.h>
 #endif
