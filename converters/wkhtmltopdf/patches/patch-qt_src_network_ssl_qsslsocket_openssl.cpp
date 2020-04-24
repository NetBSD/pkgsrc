--- qt/src/network/ssl/qsslsocket_openssl.cpp.orig	2016-08-23 08:13:31.000000000 +0200
+++ qt/src/network/ssl/qsslsocket_openssl.cpp	2020-04-23 17:34:53.522272791 +0200
@@ -221,10 +221,10 @@
         if (descriptionList.at(4).startsWith(QLatin1String("Enc=")))
             ciph.d->encryptionMethod = descriptionList.at(4).mid(4);
         ciph.d->exportable = (descriptionList.size() > 6 && descriptionList.at(6) == QLatin1String("export"));
 
-        ciph.d->bits = cipher->strength_bits;
-        ciph.d->supportedBits = cipher->alg_bits;
+        ciph.d->bits = SSL_CIPHER_get_bits(cipher, NULL);
+        ciph.d->supportedBits = SSL_CIPHER_get_bits(cipher, NULL);
 
     }
     return ciph;
 }
@@ -362,9 +362,9 @@
         // certificates mixed with valid ones.
         //
         // See also: QSslContext::fromConfiguration()
         if (caCertificate.expiryDate() >= QDateTime::currentDateTime()) {
-            q_X509_STORE_add_cert(ctx->cert_store, (X509 *)caCertificate.handle());
+            q_X509_STORE_add_cert(SSL_CTX_get_cert_store(ctx), (X509 *)caCertificate.handle());
         }
     }
 
     if (s_loadRootCertsOnDemand && allowRootCertOnDemandLoading) {
@@ -658,9 +658,9 @@
 
     STACK_OF(SSL_CIPHER) *supportedCiphers = q_SSL_get_ciphers(mySsl);
     for (int i = 0; i < q_sk_SSL_CIPHER_num(supportedCiphers); ++i) {
         if (SSL_CIPHER *cipher = q_sk_SSL_CIPHER_value(supportedCiphers, i)) {
-            if (cipher->valid) {
+            if (1 /* cipher->valid */) {
                 QSslCipher ciph = QSslSocketBackendPrivate::QSslCipher_from_SSL_CIPHER(cipher);
                 if (!ciph.isNull()) {
                     if (!ciph.name().toLower().startsWith(QLatin1String("adh")))
                         ciphers << ciph;
