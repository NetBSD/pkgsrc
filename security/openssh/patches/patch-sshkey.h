$NetBSD: patch-sshkey.h,v 1.1 2019/09/06 09:03:00 manu Exp $

Support for non recommendable (insecure) modulus size for RSA. This may be
required in order to access old, non-upgradable, devices for which modulus size
is less than 1024 bits (frequently 768 bits).

--- sshkey.h.orig	2019-09-03 17:55:31.695925772 +0200
+++ sshkey.h
@@ -47,7 +47,11 @@
 # define EC_POINT	void
 #endif /* WITH_OPENSSL */

+#ifdef SSH_RSA_INSECURE_LEGACY_MIN_MOD_SZ
+#define SSH_RSA_MINIMUM_MODULUS_SIZE	SSH_RSA_INSECURE_LEGACY_MIN_MOD_SZ
+#else
 #define SSH_RSA_MINIMUM_MODULUS_SIZE	1024
+#endif
 #define SSH_KEY_MAX_SIGN_DATA_SIZE	(1 << 20)
 
 struct sshbuf;
