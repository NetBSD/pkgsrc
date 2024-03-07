$NetBSD: patch-src_Cedar_BridgeUnix.c,v 1.1 2024/03/07 11:48:35 hauke Exp $

Include netinet/if_ether.h for NetBSD in line with VLanUnix.c

--- src/Cedar/BridgeUnix.c.orig	2023-12-03 16:16:54.000000000 +0000
+++ src/Cedar/BridgeUnix.c
@@ -29,7 +29,9 @@
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 
-#if !defined(UNIX_OPENBSD) && !defined(UNIX_SOLARIS)
+#if defined(UNIX_NETBSD) || defined(UNIX_OPENBSD) || defined(UNIX_SOLARIS)
+#include <netinet/if_ether.h>
+#else
 #include <net/ethernet.h>
 #endif
 
