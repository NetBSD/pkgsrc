$NetBSD: patch-sshkey.h,v 1.3 2021/09/26 15:37:51 wiz Exp $

Support for non recommendable (insecure) modulus size for RSA. This may be
required in order to access old, non-upgradable, devices for which modulus size
is less than 1024 bits (frequently 768 bits).

--- sshkey.h.orig	2021-09-26 14:03:19.000000000 +0000
+++ sshkey.h
@@ -50,7 +50,11 @@
 #define SSH_OPENSSL_VERSION "without OpenSSL"
 #endif /* WITH_OPENSSL */
 
+#ifdef SSH_RSA_INSECURE_LEGACY_MIN_MOD_SZ
+#define SSH_RSA_MINIMUM_MODULUS_SIZE	SSH_RSA_INSECURE_LEGACY_MIN_MOD_SZ
+#else
 #define SSH_RSA_MINIMUM_MODULUS_SIZE	1024
+#endif
 #define SSH_KEY_MAX_SIGN_DATA_SIZE	(1 << 20)
 
 struct sshbuf;
