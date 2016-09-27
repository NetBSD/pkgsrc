$NetBSD: patch-plugins_collab_backends_service_xp_tls__tunnel.cpp,v 1.1 2016/09/27 12:00:51 wiz Exp $

Fix build with gnutls-3.5.
http://www.abisource.com/viewvc/abiword/branches/ABI-3-0-0-STABLE/plugins/collab/backends/service/xp/tls_tunnel.cpp?r1=35270&r2=35269&pathrev=35270

--- plugins/collab/backends/service/xp/tls_tunnel.cpp.orig	2014-11-04 01:12:14.000000000 +0000
+++ plugins/collab/backends/service/xp/tls_tunnel.cpp
@@ -306,9 +306,6 @@ void Proxy::tunnel_(transport_ptr_t tran
 	disconnect_(transport_ptr, session_ptr, local_socket_ptr, remote_socket_ptr);		
 }
 
-static const int PRIORITIES[] = { GNUTLS_KX_ANON_DH, GNUTLS_KX_RSA, GNUTLS_KX_DHE_DSS, GNUTLS_KX_DHE_RSA, 0 };
-static const int CIPHERS[] = { GNUTLS_CIPHER_AES_256_CBC, GNUTLS_CIPHER_AES_128_CBC, GNUTLS_CIPHER_3DES_CBC, GNUTLS_CIPHER_ARCFOUR_128, 0 };
-
 // FIXME: this clientproxy can only handle 1 SSL connection at the same time
 ClientProxy::ClientProxy(const std::string& connect_address, unsigned short connect_port, 
 		const std::string& ca_file, bool check_hostname)
@@ -400,8 +397,6 @@ session_ptr_t ClientProxy::setup_tls_ses
 	// setup session
 	return_val_if_neg(gnutls_init(session_ptr.get(), GNUTLS_CLIENT), session_ptr_t());
 	return_val_if_neg(gnutls_set_default_priority(*session_ptr), session_ptr_t());
-	return_val_if_neg(gnutls_kx_set_priority(*session_ptr,PRIORITIES), session_ptr_t());
-	return_val_if_neg(gnutls_cipher_set_priority(*session_ptr,CIPHERS), session_ptr_t());
 	return_val_if_neg(gnutls_credentials_set(*session_ptr, GNUTLS_CRD_CERTIFICATE, x509cred), session_ptr_t());
 
 	// setup transport
