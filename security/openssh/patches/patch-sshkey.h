$NetBSD: patch-sshkey.h,v 1.2 2020/09/29 15:17:42 ryoon Exp $

Support for non recommendable (insecure) modulus size for RSA. This may be
required in order to access old, non-upgradable, devices for which modulus size
is less than 1024 bits (frequently 768 bits).

--- sshkey.h.orig	2020-09-27 07:25:01.000000000 +0000
+++ sshkey.h
@@ -48,7 +48,11 @@
 # define EC_POINT	void
 #endif /* WITH_OPENSSL */
 
+#ifdef SSH_RSA_INSECURE_LEGACY_MIN_MOD_SZ
+#define SSH_RSA_MINIMUM_MODULUS_SIZE	SSH_RSA_INSECURE_LEGACY_MIN_MOD_SZ
+#else
 #define SSH_RSA_MINIMUM_MODULUS_SIZE	1024
+#endif
 #define SSH_KEY_MAX_SIGN_DATA_SIZE	(1 << 20)
 
 struct sshbuf;
