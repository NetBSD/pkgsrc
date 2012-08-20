$NetBSD: patch-libfdcore_config.c,v 1.1 2012/08/20 12:17:20 wiz Exp $

Fix build against gnutls-3.x, based on feedback by Nikos Mavrogiannopou
on help-gnutls@gnu.org.

--- libfdcore/config.c.orig	2012-02-21 17:46:14.000000000 +0000
+++ libfdcore/config.c
@@ -358,9 +358,12 @@ int fd_conf_parse()
 		ASSERT(cert_max >= 1);
 		
 		/* Now, verify the list against the local CA and CRL */
-		GNUTLS_TRACE( gnutls_certificate_get_x509_cas (fd_g_config->cnf_sec_data.credentials, &CA_list, (unsigned int *) &CA_list_length) );
-		GNUTLS_TRACE( gnutls_certificate_get_x509_crls (fd_g_config->cnf_sec_data.credentials, &CRL_list, (unsigned int *) &CRL_list_length) );
-		CHECK_GNUTLS_DO( gnutls_x509_crt_list_verify(certs, cert_max, CA_list, CA_list_length, CRL_list, CRL_list_length, 0, &verify),
+		CHECK_GNUTLS_DO( gnutls_certificate_get_issuer(fd_g_config->cnf_sec_data.credentials, certs[cert_max-1], &CA_list, 0),
+			{
+				TRACE_DEBUG(INFO, "Cannot find issuer for local certificate '%s'. Please check your certificate is valid.", fd_g_config->cnf_sec_data.cert_file);
+				return EINVAL;
+			} );
+		CHECK_GNUTLS_DO( gnutls_x509_crt_list_verify(certs, cert_max, CA_list, 1, NULL, 0, 0, &verify),
 			{
 				TRACE_DEBUG(INFO, "Failed to verify the local certificate '%s' against local credentials. Please check your certificate is valid.", fd_g_config->cnf_sec_data.cert_file);
 				return EINVAL;
