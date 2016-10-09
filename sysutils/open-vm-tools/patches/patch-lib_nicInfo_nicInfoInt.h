$NetBSD: patch-lib_nicInfo_nicInfoInt.h,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/nicInfo/nicInfoInt.h.orig	2016-02-16 20:06:46.000000000 +0000
+++ lib/nicInfo/nicInfoInt.h
@@ -29,7 +29,7 @@
 
 #include "nicInfo.h"
 
-#if defined __FreeBSD__ || defined __sun__ || defined __APPLE__
+#if defined __FreeBSD__ || defined __sun__ || defined __APPLE__ || defined __NetBSD__
 #   include <sys/socket.h>      // struct sockaddr
 #endif
 
