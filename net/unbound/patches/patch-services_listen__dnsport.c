$NetBSD: patch-services_listen__dnsport.c,v 1.1 2020/11/13 17:05:40 jperkin Exp $

Include limits.h for SSIZE_MAX.

--- services/listen_dnsport.c.orig	2020-10-08 06:24:21.000000000 +0000
+++ services/listen_dnsport.c
@@ -62,6 +62,7 @@
 #include <netdb.h>
 #endif
 #include <fcntl.h>
+#include <limits.h>
 
 #ifdef HAVE_SYS_UN_H
 #include <sys/un.h>
