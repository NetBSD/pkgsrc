$NetBSD: patch-minissdpc.c,v 1.2 2018/10/03 22:27:05 nia Exp $

need sockio.h for SIOCGIFADDR on SunOS

--- minissdpc.c.orig	2018-04-06 10:53:30.000000000 +0000
+++ minissdpc.c
@@ -14,6 +14,9 @@
 #if defined (__NetBSD__)
 #include <net/if.h>
 #endif
+#if defined(__sun)
+#include <sys/sockio.h>
+#endif
 #if defined(_WIN32) || defined(__amigaos__) || defined(__amigaos4__)
 #ifdef _WIN32
 #include <winsock2.h>
