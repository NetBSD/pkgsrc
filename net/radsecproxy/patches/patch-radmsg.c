$NetBSD: patch-radmsg.c,v 1.1 2026/06/07 17:45:46 adam Exp $

Add support for Nettle 4.0
https://github.com/radsecproxy/radsecproxy/pull/197

--- radmsg.c.orig	2025-03-25 13:15:57.000000000 +0000
+++ radmsg.c
@@ -9,6 +9,7 @@
 #include "util.h"
 #include <arpa/inet.h>
 #include <nettle/hmac.h>
+#include <nettle/version.h>
 #include <openssl/rand.h>
 #include <pthread.h>
 #include <stdlib.h>
@@ -146,7 +147,11 @@ int _checkmsgauth(unsigned char *rad, in
 
     hmac_md5_set_key(&hmacctx, secret_len, secret);
     hmac_md5_update(&hmacctx, radlen, rad);
+#if NETTLE_VERSION_MAJOR >= 4
+    hmac_md5_digest(&hmacctx, hash);
+#else
     hmac_md5_digest(&hmacctx, sizeof(hash), hash);
+#endif
 
     memcpy(authattr, auth, MD5_DIGEST_SIZE);
 
@@ -169,7 +174,11 @@ int _validauth(unsigned char *rad, int l
     if (len > 20)
         md5_update(&mdctx, len - 20, rad + 20);
     md5_update(&mdctx, sec_len, sec);
+#if NETTLE_VERSION_MAJOR >= 4
+    md5_digest(&mdctx, hash);
+#else
     md5_digest(&mdctx, sizeof(hash), hash);
+#endif
 
     result = !memcmp(hash, rad + 4, 16);
 
@@ -189,7 +198,11 @@ int _createmessageauth(unsigned char *ra
     memset(authattrval, 0, 16);
     hmac_md5_set_key(&hmacctx, secret_len, secret);
     hmac_md5_update(&hmacctx, radlen, rad);
+#if NETTLE_VERSION_MAJOR >= 4
+    hmac_md5_digest(&hmacctx, authattrval);
+#else
     hmac_md5_digest(&hmacctx, MD5_DIGEST_SIZE, authattrval);
+#endif
 
     pthread_mutex_unlock(&lock);
     return 1;
@@ -204,7 +217,11 @@ int _radsign(unsigned char *rad, int rad
     md5_init(&mdctx);
     md5_update(&mdctx, radlen, rad);
     md5_update(&mdctx, sec_len, sec);
+#if NETTLE_VERSION_MAJOR >= 4
+    md5_digest(&mdctx, rad + 4);
+#else
     md5_digest(&mdctx, MD5_DIGEST_SIZE, rad + 4);
+#endif
 
     pthread_mutex_unlock(&lock);
     return 1;
