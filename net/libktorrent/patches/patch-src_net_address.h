$NetBSD: patch-src_net_address.h,v 1.1 2012/09/03 10:06:40 marino Exp $

Version 4.2.1 fixed FreeBSD by putting <sys/socket.h> in address.cpp and
removing <arpa/inet.h> which was Linux-specific.
However, DragonFly still choked on it with incomplete type errors.  It
seems that upstream should have put <sys/socket.h> in address.h instead.

--- src/net/address.h.orig	2012-06-12 10:16:36.000000000 +0000
+++ src/net/address.h
@@ -24,6 +24,7 @@
 #include <QHostAddress>
 #include <util/constants.h>
 #include <ktorrent_export.h>
+#include <sys/socket.h>
 
 
 namespace net
