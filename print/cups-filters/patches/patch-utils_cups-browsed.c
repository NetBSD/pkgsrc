$NetBSD: patch-utils_cups-browsed.c,v 1.5 2014/10/29 23:43:42 wiz Exp $

Build fix for NetBSD 6.1.
http://gnats.netbsd.org/49334
https://bugs.linuxfoundation.org/show_bug.cgi?id=1235

--- utils/cups-browsed.c.orig	2014-10-08 11:47:08.000000000 +0000
+++ utils/cups-browsed.c
@@ -26,12 +26,12 @@
 #if defined(__OpenBSD__)
 #include <sys/socket.h>
 #endif /* __OpenBSD__ */
+#include <sys/types.h>
 #include <net/if.h>
 #include <netinet/in.h>
 #include <ifaddrs.h>
 #include <resolv.h>
 #include <stdio.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
 #include <stdlib.h>
