$NetBSD: patch-lib_isc_unix_socket.c,v 1.1.2.2 2018/08/18 13:18:09 bsiegert Exp $

Make ENOBUFS a soft error
https://gitlab.isc.org/isc-projects/bind9/issues/462

--- lib/isc/unix/socket.c.orig	2018-07-24 17:26:35.000000000 +0000
+++ lib/isc/unix/socket.c
@@ -236,6 +236,7 @@ typedef enum { poll_idle, poll_active, p
 #define SOFT_ERROR(e)	((e) == EAGAIN || \
 			 (e) == EWOULDBLOCK || \
 			 (e) == EINTR || \
+			 (e) == ENOBUFS || \
 			 (e) == 0)
 
 #define DLVL(x) ISC_LOGCATEGORY_GENERAL, ISC_LOGMODULE_SOCKET, ISC_LOG_DEBUG(x)
@@ -1743,7 +1744,7 @@ doio_recv(isc__socket_t *sock, isc_socke
 		SOFT_OR_HARD(EHOSTDOWN, ISC_R_HOSTDOWN);
 		/* HPUX 11.11 can return EADDRNOTAVAIL. */
 		SOFT_OR_HARD(EADDRNOTAVAIL, ISC_R_ADDRNOTAVAIL);
-		ALWAYS_HARD(ENOBUFS, ISC_R_NORESOURCES);
+		SOFT_OR_HARD(ENOBUFS, ISC_R_NORESOURCES);
 		/* Should never get this one but it was seen. */
 #ifdef ENOPROTOOPT
 		SOFT_OR_HARD(ENOPROTOOPT, ISC_R_HOSTUNREACH);
@@ -1939,7 +1940,7 @@ doio_send(isc__socket_t *sock, isc_socke
 		ALWAYS_HARD(EHOSTDOWN, ISC_R_HOSTUNREACH);
 #endif
 		ALWAYS_HARD(ENETUNREACH, ISC_R_NETUNREACH);
-		ALWAYS_HARD(ENOBUFS, ISC_R_NORESOURCES);
+		SOFT_OR_HARD(ENOBUFS, ISC_R_NORESOURCES);
 		ALWAYS_HARD(EPERM, ISC_R_HOSTUNREACH);
 		ALWAYS_HARD(EPIPE, ISC_R_NOTCONNECTED);
 		ALWAYS_HARD(ECONNRESET, ISC_R_CONNECTIONRESET);
