$NetBSD: patch-third__party_heimdal_lib_hcrypto_evp.c,v 1.1 2022/08/30 17:47:50 jperkin Exp $

Disable pkcs11_hcrypto, only available on Oracle Solaris 11.x

--- third_party/heimdal/lib/hcrypto/evp.c.orig	2022-03-08 14:53:05.754089600 +0000
+++ third_party/heimdal/lib/hcrypto/evp.c
@@ -55,8 +55,6 @@
 #ifndef HCRYPTO_DEF_PROVIDER
 # ifdef __APPLE__
 #  define HCRYPTO_DEF_PROVIDER cc
-# elif __sun
-#  define HCRYPTO_DEF_PROVIDER pkcs11_hcrypto
 # elif HAVE_HCRYPTO_W_OPENSSL
 #  define HCRYPTO_DEF_PROVIDER ossl
 # else
