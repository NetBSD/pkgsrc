$NetBSD: patch-libsrc_Wi_xmlenc.h,v 1.1 2013/04/13 13:16:02 jaapb Exp $

use proper DES interface
--- libsrc/Wi/xmlenc.h.orig	2012-03-23 12:28:31.000000000 +0000
+++ libsrc/Wi/xmlenc.h
@@ -312,15 +312,15 @@ struct xenc_key_s
     } dsa;
     struct dsig_des3_keyinfo_s
     {
-      des_cblock k1;
-      des_cblock k2;
-      des_cblock k3;
-
-      des_key_schedule ks1;/* key schedule */
-      des_key_schedule ks2;/* key schedule (for ede) */
-      des_key_schedule ks3;/* key schedule (for ede3) */
+      DES_cblock k1;
+      DES_cblock k2;
+      DES_cblock k3;
+
+      DES_key_schedule ks1;/* key schedule */
+      DES_key_schedule ks2;/* key schedule (for ede) */
+      DES_key_schedule ks3;/* key schedule (for ede3) */
 
-      des_cblock iv;
+      DES_cblock iv;
 #define PKCS5_SALT_LEN			8
       unsigned char salt[PKCS5_SALT_LEN];
     } triple_des;
