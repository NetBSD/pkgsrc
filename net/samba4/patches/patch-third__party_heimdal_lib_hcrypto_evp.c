$NetBSD: patch-third__party_heimdal_lib_hcrypto_evp.c,v 1.2 2023/11/15 18:54:43 wiz Exp $

Disable pkcs11_hcrypto, only available on Oracle Solaris 11.x

--- third_party/heimdal/lib/hcrypto/evp.c.orig	2023-07-18 08:14:56.858105700 +0000
+++ third_party/heimdal/lib/hcrypto/evp.c
@@ -55,8 +55,6 @@
 #ifndef HCRYPTO_DEF_PROVIDER
 # ifdef __APPLE__
 #  define HCRYPTO_DEF_PROVIDER cc
-# elif __sun
-#  define HCRYPTO_DEF_PROVIDER pkcs11_hcrypto
 # elif HAVE_HCRYPTO_W_OPENSSL
 #  define HCRYPTO_DEF_PROVIDER ossl
 #  define HCRYPTO_DEF_PROVIDER_IS_OPENSSL
