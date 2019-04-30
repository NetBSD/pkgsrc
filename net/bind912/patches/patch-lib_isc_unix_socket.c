$NetBSD: patch-lib_isc_unix_socket.c,v 1.3 2019/04/30 02:46:16 taca Exp $

Apply fix from NetBSD revision 1.24.

--- lib/isc/unix/socket.c.orig	2019-02-27 23:42:04.000000000 +0000
+++ lib/isc/unix/socket.c
@@ -257,6 +257,7 @@ typedef enum { poll_idle, poll_active, p
 			 (e) == EWOULDBLOCK || \
 			 (e) == ENOBUFS || \
 			 (e) == EINTR || \
+			 (e) == ENOBUFS || \
 			 (e) == 0)
 
 #define DLVL(x) ISC_LOGCATEGORY_GENERAL, ISC_LOGMODULE_SOCKET, ISC_LOG_DEBUG(x)
