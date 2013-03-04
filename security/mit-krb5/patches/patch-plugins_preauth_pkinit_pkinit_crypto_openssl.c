$NetBSD: patch-plugins_preauth_pkinit_pkinit_crypto_openssl.c,v 1.1.2.2 2013/03/04 23:35:37 tron Exp $

Patch for CVE-2013-1415 from
http://krbdev.mit.edu/rt/Ticket/Display.html?id=7570

--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig	2013-02-27 22:15:40.286439500 +0000
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c
@@ -3242,7 +3242,7 @@ pkinit_check_kdc_pkid(krb5_context conte
     pkiDebug("found kdcPkId in AS REQ\n");
     is = d2i_PKCS7_ISSUER_AND_SERIAL(NULL, &p, (int)pkid_len);
     if (is == NULL)
-        goto cleanup;
+        return retval;
 
     status = X509_NAME_cmp(X509_get_issuer_name(kdc_cert), is->issuer);
     if (!status) {
@@ -3252,7 +3252,6 @@ pkinit_check_kdc_pkid(krb5_context conte
     }
 
     retval = 0;
-cleanup:
     X509_NAME_free(is->issuer);
     ASN1_INTEGER_free(is->serial);
     free(is);
