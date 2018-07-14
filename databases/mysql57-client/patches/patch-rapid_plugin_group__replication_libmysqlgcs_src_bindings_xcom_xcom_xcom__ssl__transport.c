$NetBSD: patch-rapid_plugin_group__replication_libmysqlgcs_src_bindings_xcom_xcom_xcom__ssl__transport.c,v 1.1.4.1 2018/07/14 17:41:26 spz Exp $

support openssl 1.1 
from https://bugs.mysql.com/bug.php?id=83814

--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.c.orig	2018-03-04 13:40:40.000000000 +0000
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.c
@@ -104,7 +104,7 @@ static const char* tls_cipher_blocked= "
   mjxx/bg6bOOjpgZapvB6ABWlWmRmAAWFtwIBBQ==
   -----END DH PARAMETERS-----
  */
-static unsigned char dh2048_p[]=
+static unsigned char dhp_2048[]=
 {
   0x8A, 0x5D, 0xFA, 0xC0, 0x66, 0x76, 0x4E, 0x61, 0xFA, 0xCA, 0xC0, 0x37,
   0x57, 0x5C, 0x6D, 0x3F, 0x83, 0x0A, 0xA1, 0xF5, 0xF1, 0xE6, 0x7F, 0x3C,
@@ -131,20 +131,37 @@ static unsigned char dh2048_p[]=
 };
 
 
-static unsigned char dh2048_g[]={
+static unsigned char dhg_2048[]={
   0x05,
 };
 
 static DH *get_dh2048(void)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   DH *dh;
   if ((dh=DH_new()))
+#else
+  DH *dh = DH_new();
+  BIGNUM *dhp_bn, *dhg_bn;
+  if (dh != NULL)
+#endif
   {
-    dh->p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
-    dh->g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    dh->p=BN_bin2bn(dhp_2048, sizeof(dhp_2048), NULL);
+    dh->g=BN_bin2bn(dhg_2048, sizeof(dhg_2048), NULL);
     if (! dh->p || ! dh->g)
+#else
+    dhp_bn = BN_bin2bn(dhp_2048, sizeof (dhp_2048), NULL);
+    dhg_bn = BN_bin2bn(dhg_2048, sizeof (dhg_2048), NULL);
+    if (dhp_bn == NULL || dhg_bn == NULL
+        || !DH_set0_pqg(dh, dhp_bn, NULL, dhg_bn)) 
+#endif
     {
       DH_free(dh);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+      BN_free(dhp_bn);
+      BN_free(dhg_bn);
+#endif
       dh=0;
     }
   }
