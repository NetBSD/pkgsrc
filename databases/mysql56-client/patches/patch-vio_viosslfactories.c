$NetBSD: patch-vio_viosslfactories.c,v 1.3.2.2 2019/09/08 16:55:18 bsiegert Exp $

* Allow build with OpenSSL 1.1.

--- vio/viosslfactories.c.orig	2019-06-10 10:25:32.000000000 +0000
+++ vio/viosslfactories.c
@@ -68,13 +68,21 @@ static DH *get_dh2048(void)
   DH *dh;
   if ((dh=DH_new()))
   {
-    dh->p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
-    dh->g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-    if (! dh->p || ! dh->g)
-    {
+    BIGNUM *p= BN_bin2bn(dh2048_p, sizeof(dh2048_p), NULL);
+    BIGNUM *g= BN_bin2bn(dh2048_g, sizeof(dh2048_g), NULL);
+    if (!p || !g
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+        || !DH_set0_pqg(dh, p, NULL, g)
+#endif /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
+    ) {
+      /* DH_free() will free 'p' and 'g' at once. */
       DH_free(dh);
-      dh=0;
+      return NULL;
     }
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    dh->p= p;
+    dh->g= g;
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   }
   return(dh);
 }
@@ -230,8 +238,8 @@ new_VioSSLFd(const char *key_file, const
     DBUG_RETURN(0);
 
   if (!(ssl_fd->ssl_context= SSL_CTX_new(is_client ?
-                                         TLSv1_client_method() :
-                                         TLSv1_server_method())))
+                                         SSLv23_client_method() :
+                                         SSLv23_server_method())))
   {
     *error= SSL_INITERR_MEMFAIL;
     DBUG_PRINT("error", ("%s", sslGetErrString(*error)));
