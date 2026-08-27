$NetBSD: patch-libraries_libldap_tls__o.c,v 1.1 2026/08/27 16:11:18 jperkin Exp $

Support pre-C23 compilers.

--- libraries/libldap/tls_o.c.orig	2026-08-27 15:54:30.824812399 +0000
+++ libraries/libldap/tls_o.c
@@ -543,7 +543,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 
 				while ((info = OSSL_STORE_load( sctx ))) {
 					switch (OSSL_STORE_INFO_get_type( info )) {
-					case OSSL_STORE_INFO_CERT:
+					case OSSL_STORE_INFO_CERT: {
 						X509 *cert = OSSL_STORE_INFO_get0_CERT( info );
 						X509_STORE *store = SSL_CTX_get_cert_store( ctx );
 						if ( !X509_STORE_add_cert( store, cert ) ) {
@@ -565,6 +565,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 							}
 						}
 						break;
+					}
 					default:
 						/* ignore other types */
 						break;
@@ -753,7 +754,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 						return -1;
 					}
 					break;
-				case OSSL_STORE_INFO_CERT:
+				case OSSL_STORE_INFO_CERT: {
 					X509 *cert = OSSL_STORE_INFO_get0_CERT(info);
 					int is_ca = X509_check_ca( cert );
 					if ( !is_ca && !SSL_CTX_use_certificate( ctx, cert )) {
@@ -773,7 +774,8 @@ tlso_ctx_init( struct ldapoptions *lo, s
 						return -1;
 					}
 					break;
-				case OSSL_STORE_INFO_CRL:
+				}
+				case OSSL_STORE_INFO_CRL: {
 					X509_STORE *x509_s = SSL_CTX_get_cert_store( ctx );
 					if ( !X509_STORE_add_crl( x509_s,
 							OSSL_STORE_INFO_get0_CRL(info) )) {
@@ -785,6 +787,7 @@ tlso_ctx_init( struct ldapoptions *lo, s
 						return -1;
 					}
 					break;
+				}
 				default:
 					/* ignore other types */
 					break;
