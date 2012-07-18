$NetBSD: patch-lib_ssl__gnutls.c,v 1.1 2012/07/18 09:56:02 marino Exp $

GnuTLS deprecated gnutls_transport_set_lowat in version 2.12.0 and removed it by version 3
The lowat feature is always disabled now.

--- lib/ssl_gnutls.c.orig	2012-07-18 08:30:44.294219000 +0000
+++ lib/ssl_gnutls.c
@@ -134,7 +134,9 @@ static gboolean ssl_connected( gpointer
 	
 	gnutls_certificate_allocate_credentials( &conn->xcred );
 	gnutls_init( &conn->session, GNUTLS_CLIENT );
+#if GNUTLS_VERSION_NUMBER < 0x020c00
 	gnutls_transport_set_lowat( conn->session, 1 ); 
+#endif       
 	gnutls_set_default_priority( conn->session );
 	gnutls_credentials_set( conn->session, GNUTLS_CRD_CERTIFICATE, conn->xcred );
 	
