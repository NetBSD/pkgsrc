$NetBSD: patch-src_HostAddress.cpp,v 1.1 2022/04/10 07:47:22 nia Exp $

Add missing includes on NetBSD.

--- src/HostAddress.cpp.orig	2022-01-18 01:00:00.338013600 +0000
+++ src/HostAddress.cpp
@@ -13,7 +13,7 @@
 #	include <ws2tcpip.h>
 #else
 #	include <arpa/inet.h>
-#	if defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#	if defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
 #		include <netinet/in.h>
 #		include <sys/socket.h>
 #		include <sys/types.h>
