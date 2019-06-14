$NetBSD: patch-lib_isc_unix_socket.c,v 1.2 2019/06/14 16:14:05 taca Exp $

* Apply fixes from NetBSD base system.

--- lib/isc/unix/socket.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/isc/unix/socket.c
@@ -225,6 +225,7 @@ typedef enum { poll_idle, poll_active, p
 			 (e) == EWOULDBLOCK || \
 			 (e) == ENOBUFS || \
 			 (e) == EINTR || \
+			 (e) == ENOBUFS || \
 			 (e) == 0)
 
 #define DLVL(x) ISC_LOGCATEGORY_GENERAL, ISC_LOGMODULE_SOCKET, ISC_LOG_DEBUG(x)
