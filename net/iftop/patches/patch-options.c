$NetBSD: patch-options.c,v 1.1 2018/10/22 14:58:14 jperkin Exp $

SunOS needs sockio.h for SIOCGIFFLAGS.

--- options.c.orig	2014-01-19 20:16:43.000000000 +0000
+++ options.c
@@ -18,6 +18,9 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <net/if.h>
+#ifdef __sun
+#include <sys/sockio.h>
+#endif
 
 #include "iftop.h"
 #include "options.h"
