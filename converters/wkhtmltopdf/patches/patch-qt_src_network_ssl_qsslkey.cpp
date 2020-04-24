--- qt/src/network/ssl/qsslkey.cpp.orig	2016-08-23 08:13:31.000000000 +0200
+++ qt/src/network/ssl/qsslkey.cpp	2020-04-23 17:34:53.449790782 +0200
@@ -321,9 +321,9 @@
 {
     if (d->isNull)
         return -1;
     return (d->algorithm == QSsl::Rsa)
-           ? q_BN_num_bits(d->rsa->n) : q_BN_num_bits(d->dsa->p);
+           ? BN_num_bits(RSA_get0_n(d->rsa)) : BN_num_bits(DSA_get0_p(d->dsa));
 }
 
 /*!
     Returns the type of the key (i.e., PublicKey or PrivateKey).
