$NetBSD: patch-libtcpa_hmac.c,v 1.1 2020/03/27 20:57:12 joerg Exp $

--- libtcpa/hmac.c.orig	2020-03-27 18:46:13.942881974 +0000
+++ libtcpa/hmac.c
@@ -167,25 +167,30 @@ int authhmac(unsigned char *digest, unsi
 int rawhmac(unsigned char *digest, unsigned char *key,
             unsigned int keylen, ...)
 {
-    HMAC_CTX hmac;
+    HMAC_CTX *hmac;
     unsigned int dlen;
     unsigned char *data;
     va_list argp;
 
-    HMAC_Init(&hmac, key, keylen, EVP_sha1());
+    hmac = HMAC_CTX_new();
+    if (!hmac)
+        return -1;
+    HMAC_Init_ex(hmac, key, keylen, EVP_sha1(), NULL);
     va_start(argp, keylen);
     for (;;) {
         dlen = (unsigned int) va_arg(argp, unsigned int);
         if (dlen == 0)
             break;
         data = (unsigned char *) va_arg(argp, int);
-        if (data == NULL)
+        if (data == NULL) {
+            HMAC_CTX_free(hmac);
             return -1;
-        HMAC_Update(&hmac, data, dlen);
+        }
+        HMAC_Update(hmac, data, dlen);
     }
-    HMAC_Final(&hmac, digest, &dlen);
-    HMAC_cleanup(&hmac);
+    HMAC_Final(hmac, digest, &dlen);
     va_end(argp);
+    HMAC_CTX_free(hmac);
     return 0;
 }
 
