$NetBSD: patch-src_encrypt.cpp,v 1.1 2016/09/26 01:08:42 kamil Exp $

Do not use deprecated GnuTLS functions

--- src/encrypt.cpp.orig	2011-09-28 11:15:10.000000000 +0000
+++ src/encrypt.cpp
@@ -175,10 +175,10 @@ net6::tcp_encrypted_socket_base::
                                   gnutls_session_t sess):
 	tcp_client_socket(cobj), session(sess), state(DEFAULT)
 {
-	const int kx_prio[] = { GNUTLS_KX_ANON_DH, 0 };
+	static const char kx_prio[] = "NORMAL:+ANON-DH";
 
 	gnutls_set_default_priority(session);
-	gnutls_kx_set_priority(session, kx_prio);
+	gnutls_priority_set_direct(session, kx_prio, NULL);
 
 	gnutls_transport_set_ptr(
 		session,
