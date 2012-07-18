$NetBSD: patch-encrypt.cpp,v 1.1 2012/07/18 10:22:23 marino Exp $

GnuTLS deprecated gnutls_transport_set_lowat in version 2.12.0 and removed it by version 3
The lowat feature is always disabled now.

--- src/encrypt.cpp.orig	2009-08-24 12:18:29.000000000 +0000
+++ src/encrypt.cpp
@@ -202,7 +202,9 @@ net6::tcp_encrypted_socket_base::
 	);
 #endif
 
+#if GNUTLS_VERSION_NUMBER < 0x020c00
 	gnutls_transport_set_lowat(session, 0);
+#endif
 }
 
 net6::tcp_encrypted_socket_base::~tcp_encrypted_socket_base()
