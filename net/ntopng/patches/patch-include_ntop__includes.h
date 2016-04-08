$NetBSD: patch-include_ntop__includes.h,v 1.1 2016/04/08 16:59:07 adam Exp $

Add NetBSD support.

--- include/ntop_includes.h.orig	2016-04-04 12:57:38.000000000 +0000
+++ include/ntop_includes.h
@@ -43,7 +43,7 @@
 #include <arpa/inet.h>
 #include <poll.h>
 
-#if defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
