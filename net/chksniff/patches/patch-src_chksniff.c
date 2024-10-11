$NetBSD: patch-src_chksniff.c,v 1.1 2024/10/11 06:58:02 nia Exp $

Resolve problems with implicit function declarations
and missing SIOCGIFCONF.

--- src/chksniff.c.orig	2003-04-06 20:28:03.000000000 +0000
+++ src/chksniff.c
@@ -2,10 +2,13 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
+#include <string.h>
+#include <arpa/inet.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/sockio.h>
 #include <sys/ioctl.h>
 
 #if defined (__linux__)
