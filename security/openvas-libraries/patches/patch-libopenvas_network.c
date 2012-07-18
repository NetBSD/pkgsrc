$NetBSD: patch-libopenvas_network.c,v 1.1 2012/07/18 09:52:44 marino Exp $

GnuTLS deprecated gnutls_transport_set_lowat in version 2.12.0 and removed it by version 3
The lowat feature is always disabled now.

--- libopenvas/network.c.orig	2008-12-16 13:03:21.000000000 +0000
+++ libopenvas/network.c
@@ -819,9 +819,10 @@ open_SSL_connection(nessus_connection *f
     }
 
   unblock_socket(fp->fd);
-  /* for non-blocking sockets, gnutls requires a 0 lowat value */
+#if GNUTLS_VERSION_NUMBER < 0x020c00
+  /* for non-blocking sockets, gnutls < 2.12.0 requires a 0 lowat value */
   gnutls_transport_set_lowat(fp->tls_session, 0);
-
+#endif
   gnutls_transport_set_ptr(fp->tls_session, (gnutls_transport_ptr_t) GSIZE_TO_POINTER(fp->fd));
 
   tictac = time(NULL);
