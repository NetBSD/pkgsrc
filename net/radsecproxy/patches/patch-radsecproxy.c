$NetBSD: patch-radsecproxy.c,v 1.1 2026/06/07 17:45:46 adam Exp $

Add support for Nettle 4.0
https://github.com/radsecproxy/radsecproxy/pull/197

--- radsecproxy.c.orig	2025-03-24 07:29:17.000000000 +0000
+++ radsecproxy.c
@@ -65,6 +65,7 @@
 #include <errno.h>
 #include <libgen.h>
 #include <nettle/md5.h>
+#include <nettle/version.h>
 #include <openssl/err.h>
 #include <openssl/rand.h>
 #include <openssl/ssl.h>
@@ -601,7 +602,11 @@ static int pwdcrypt(char encrypt_flag, u
             md5_update(&mdctx, saltlen, salt);
             salt = NULL;
         }
+#if NETTLE_VERSION_MAJOR >= 4
+        md5_digest(&mdctx, hash);
+#else
         md5_digest(&mdctx, sizeof(hash), hash);
+#endif
         for (i = 0; i < 16; i++)
             out[offset + i] = hash[i] ^ in[offset + i];
         if (encrypt_flag)
@@ -636,7 +641,11 @@ static int msmppencrypt(uint8_t *text, u
     md5_update(&mdctx, sharedlen, shared);
     md5_update(&mdctx, 16, auth);
     md5_update(&mdctx, 2, salt);
+#if NETTLE_VERSION_MAJOR >= 4
+    md5_digest(&mdctx, hash);
+#else
     md5_digest(&mdctx, sizeof(hash), hash);
+#endif
 
 #if 0
     printfchars(NULL, "msppencrypt hash", "%02x ", hash, 16);
@@ -652,7 +661,11 @@ static int msmppencrypt(uint8_t *text, u
 #endif
         md5_update(&mdctx, sharedlen, shared);
         md5_update(&mdctx, 16, text + offset - 16);
+#if NETTLE_VERSION_MAJOR >= 4
+        md5_digest(&mdctx, hash);
+#else
         md5_digest(&mdctx, sizeof(hash), hash);
+#endif
 #if 0
 	printfchars(NULL, "msppencrypt hash", "%02x ", hash, 16);
 #endif
@@ -688,7 +701,11 @@ static int msmppdecrypt(uint8_t *text, u
     md5_update(&mdctx, sharedlen, shared);
     md5_update(&mdctx, 16, auth);
     md5_update(&mdctx, 2, salt);
+#if NETTLE_VERSION_MAJOR >= 4
+    md5_digest(&mdctx, hash);
+#else
     md5_digest(&mdctx, sizeof(hash), hash);
+#endif
 
 #if 0
     printfchars(NULL, "msppdecrypt hash", "%02x ", hash, 16);
@@ -704,7 +721,11 @@ static int msmppdecrypt(uint8_t *text, u
 #endif
         md5_update(&mdctx, sharedlen, shared);
         md5_update(&mdctx, 16, text + offset - 16);
+#if NETTLE_VERSION_MAJOR >= 4
+        md5_digest(&mdctx, hash);
+#else
         md5_digest(&mdctx, sizeof(hash), hash);
+#endif
 #if 0
 	printfchars(NULL, "msppdecrypt hash", "%02x ", hash, 16);
 #endif
