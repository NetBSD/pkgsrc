$NetBSD: patch-include_rudiments_private_socketclient.h,v 1.1 2014/04/28 12:15:20 fhajny Exp $

Fix build with -Woverloaded-virtual.
--- include/rudiments/private/socketclient.h.orig	2013-09-23 04:57:18.000000000 +0000
+++ include/rudiments/private/socketclient.h
@@ -5,6 +5,7 @@
 #ifdef RUDIMENTS_HAS_SSL
 		void	*newSSLBIO() const;
 #endif
+		using ::client::connect;
 		int32_t	connect(const struct sockaddr *addr,
 				socklen_t addrlen, int32_t sec, int32_t usec);
 		ssize_t	lowLevelRead(void *buf, ssize_t count) const;
