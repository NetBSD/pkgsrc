$NetBSD: patch-minissdpc.c,v 1.1 2017/07/03 11:53:57 wiedi Exp $

need sockio.h for SIOCGIFADDR on SunOS
--- minissdpc.c.orig	2016-01-19 10:26:58.000000000 +0000
+++ minissdpc.c
@@ -11,6 +11,9 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/types.h>
+#if defined(__sun)
+#include <sys/sockio.h> 
+#endif
 #if defined(_WIN32) || defined(__amigaos__) || defined(__amigaos4__)
 #ifdef _WIN32
 #include <winsock2.h>
