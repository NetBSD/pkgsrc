$NetBSD: patch-openssl-1.1-main.c,v 1.1 2020/04/17 11:28:02 tm Exp $

Fix compilation with OpenSSL 1.1

Richard Laager <rlaager@wiktel.com>
https://sourceforge.net/p/squirrelmail/mailman/message/35526927/

--- src/imapcommon.c.orig
+++ src/imapcommon.c
@@ -554,16 +554,24 @@
     unsigned int Expiration;
     struct addrinfo *useai;
 
-    EVP_MD_CTX mdctx;
+    EVP_MD_CTX *mdctx;
     unsigned int md_len;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    EVP_MD_CTX mdctx_;
+#define EVP_MD_CTX_new(x) &mdctx_
+#define EVP_MD_CTX_free(x)
+#endif
+
     Expiration = PC_Struct.cache_expiration_time;
     memset( &Server, 0, sizeof Server );
     
     /* need to md5 the passwd regardless, so do that now */
-    EVP_DigestInit(&mdctx, EVP_md5());
-    EVP_DigestUpdate(&mdctx, Password, strlen(Password));
-    EVP_DigestFinal(&mdctx, md5pw, &md_len);
+    mdctx = EVP_MD_CTX_new();
+    EVP_DigestInit(mdctx, EVP_md5());
+    EVP_DigestUpdate(mdctx, Password, strlen(Password));
+    EVP_DigestFinal(mdctx, md5pw, &md_len);
+    EVP_MD_CTX_free(mdctx);
     
     /* see if we have a reusable connection available */
     ICC_Active = NULL;
