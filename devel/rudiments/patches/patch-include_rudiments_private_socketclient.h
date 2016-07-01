$NetBSD: patch-include_rudiments_private_socketclient.h,v 1.3 2016/07/01 16:02:12 fhajny Exp $

Fix build with -Woverloaded-virtual.
--- include/rudiments/private/socketclient.h.orig	2016-02-12 21:45:10.000000000 +0000
+++ include/rudiments/private/socketclient.h
@@ -3,6 +3,7 @@
 
 	friend class url;
 	protected:
+		using ::client::connect;
 		int32_t	connect(const struct sockaddr *addr,
 				socklen_t addrlen, int32_t sec, int32_t usec);
 		ssize_t	lowLevelRead(void *buf, ssize_t count);
