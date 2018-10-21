$NetBSD: patch-lib_isc_unix_socket.c,v 1.2 2018/10/21 15:51:14 taca Exp $

Apply fix from NetBSD revision 1.24.

--- lib/isc/unix/socket.c.orig	2018-10-06 01:36:17.000000000 +0000
+++ lib/isc/unix/socket.c
@@ -258,6 +258,7 @@ typedef enum { poll_idle, poll_active, p
 			 (e) == EWOULDBLOCK || \
 			 (e) == ENOBUFS || \
 			 (e) == EINTR || \
+			 (e) == ENOBUFS || \
 			 (e) == 0)
 
 #define DLVL(x) ISC_LOGCATEGORY_GENERAL, ISC_LOGMODULE_SOCKET, ISC_LOG_DEBUG(x)
@@ -1575,7 +1576,8 @@ build_msghdr_send(isc__socket_t *sock, c
 
 #if defined(IPV6_USE_MIN_MTU)
 	if ((sock->type == isc_sockettype_udp) &&
-	    ((dev->attributes & ISC_SOCKEVENTATTR_USEMINMTU) != 0))
+	    ((dev->attributes & ISC_SOCKEVENTATTR_USEMINMTU) != 0) &&
+	    (sock->pf == AF_INET6))
 	{
 		int use_min_mtu = 1;	/* -1, 0, 1 */
 
