$NetBSD: patch-include_rudiments_private_clientsocket.h,v 1.1 2013/09/17 11:58:57 fhajny Exp $

Fix hidden overloaded virtual function in include/rudiments/client.h.
--- include/rudiments/private/clientsocket.h.orig	2012-01-30 01:52:27.000000000 +0000
+++ include/rudiments/private/clientsocket.h
@@ -5,6 +5,7 @@
 #ifdef RUDIMENTS_HAS_SSL
 		BIO	*newSSLBIO() const;
 #endif
+		using rudiments::client::connect;
 		int32_t	connect(const struct ::sockaddr *addr,
 				socklen_t addrlen, long sec, long usec);
 		ssize_t	lowLevelRead(void *buf, ssize_t count) const;
