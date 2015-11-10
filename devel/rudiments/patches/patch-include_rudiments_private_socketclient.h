$NetBSD: patch-include_rudiments_private_socketclient.h,v 1.2 2015/11/10 10:04:40 fhajny Exp $

Fix build with -Woverloaded-virtual.
--- include/rudiments/private/socketclient.h.orig	2015-10-10 10:07:55.000000000 +0000
+++ include/rudiments/private/socketclient.h
@@ -6,6 +6,7 @@
 #ifdef RUDIMENTS_HAS_SSL
 		void	*newSSLBIO() const;
 #endif
+		using ::client::connect;
 		int32_t	connect(const struct sockaddr *addr,
 				socklen_t addrlen, int32_t sec, int32_t usec);
 		ssize_t	lowLevelRead(void *buf, ssize_t count);
