$NetBSD: patch-src_mumble_ServerHandler.cpp,v 1.3 2022/04/10 07:47:22 nia Exp $

Add missing include on NetBSD.

--- src/mumble/ServerHandler.cpp.orig	2022-01-18 01:00:00.350014000 +0000
+++ src/mumble/ServerHandler.cpp
@@ -51,7 +51,7 @@
 #	include <wincrypt.h>
 #	include <winsock2.h>
 #else
-#	if defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#	if defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
 #		include <netinet/in.h>
 #	endif
 #	include <netinet/ip.h>
