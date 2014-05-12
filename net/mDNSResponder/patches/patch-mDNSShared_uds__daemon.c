$NetBSD: patch-mDNSShared_uds__daemon.c,v 1.1 2014/05/12 15:06:56 ryoon Exp $

Required for OpenBSD 5.5

--- mDNSShared/uds_daemon.c.orig	2010-08-24 00:28:17.000000000 +0000
+++ mDNSShared/uds_daemon.c
@@ -25,6 +25,7 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
+#include <sys/uio.h>
 #endif
 
 #include <stdlib.h>
