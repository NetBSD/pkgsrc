--- qt/src/network/ssl/qsslcertificate.cpp.orig	2016-08-23 08:13:31.000000000 +0200
+++ qt/src/network/ssl/qsslcertificate.cpp	2020-04-23 17:34:53.378239752 +0200
@@ -260,9 +260,9 @@
 {
     QMutexLocker lock(QMutexPool::globalInstanceGet(d.data()));
     if (d->versionString.isEmpty() && d->x509)
         d->versionString =
-            QByteArray::number(qlonglong(q_ASN1_INTEGER_get(d->x509->cert_info->version)) + 1);
+            QByteArray::number(qlonglong(X509_get_version(d->x509)) + 1);
 
     return d->versionString;
 }
 
@@ -275,9 +275,9 @@
 QByteArray QSslCertificate::serialNumber() const
 {
     QMutexLocker lock(QMutexPool::globalInstanceGet(d.data()));
     if (d->serialNumberString.isEmpty() && d->x509) {
-        ASN1_INTEGER *serialNumber = d->x509->cert_info->serialNumber;
+        ASN1_INTEGER *serialNumber = X509_get_serialNumber(d->x509);
         // if we cannot convert to a long, just output the hexadecimal number
         if (serialNumber->length > 4) {
             QByteArray hexString;
             hexString.reserve(serialNumber->length * 3);
@@ -488,21 +488,21 @@
 
     QSslKey key;
 
     key.d->type = QSsl::PublicKey;
-    X509_PUBKEY *xkey = d->x509->cert_info->key;
+    X509_PUBKEY *xkey = X509_get_X509_PUBKEY(d->x509);
     EVP_PKEY *pkey = q_X509_PUBKEY_get(xkey);
     Q_ASSERT(pkey);
 
-    if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_RSA) {
+    if (q_EVP_PKEY_type(EVP_PKEY_id(pkey)) == EVP_PKEY_RSA) {
         key.d->rsa = q_EVP_PKEY_get1_RSA(pkey);
         key.d->algorithm = QSsl::Rsa;
         key.d->isNull = false;
-    } else if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_DSA) {
+    } else if (q_EVP_PKEY_type(EVP_PKEY_id(pkey)) == EVP_PKEY_DSA) {
         key.d->dsa = q_EVP_PKEY_get1_DSA(pkey);
         key.d->algorithm = QSsl::Dsa;
         key.d->isNull = false;
-    } else if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_DH) {
+    } else if (q_EVP_PKEY_type(EVP_PKEY_id(pkey)) == EVP_PKEY_DH) {
         // DH unsupported
     } else {
         // error?
     }
