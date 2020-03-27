$NetBSD: patch-examples_takeown.c,v 1.1 2020/03/27 20:57:12 joerg Exp $

--- examples/takeown.c.orig	2020-03-27 18:49:41.521284560 +0000
+++ examples/takeown.c
@@ -19,7 +19,7 @@ int main(int argc, char *argv[])
     keydata srk;
     RSA *rsa;                   /* OpenSSL format Public Key */
     FILE *keyfile;              /* output file for public key */
-    EVP_PKEY pkey;              /* OpenSSL public key */
+    EVP_PKEY *pkey;              /* OpenSSL public key */
 
     if (argc < 3) {
         fprintf(stderr, "Usage: takeown <ownerpass> <SRK password>\n");
@@ -42,18 +42,20 @@ int main(int argc, char *argv[])
         exit(3);
     }
     OpenSSL_add_all_algorithms();
-    EVP_PKEY_assign_RSA(&pkey, rsa);
+    pkey = EVP_PKEY_new();
+    EVP_PKEY_assign_RSA(pkey, rsa);
     keyfile = fopen("srootkey.pem", "w");
     if (keyfile == NULL) {
         fprintf(stderr, "Unable to create public key file\n");
         exit(4);
     }
-    ret = PEM_write_PUBKEY(keyfile, &pkey);
+    ret = PEM_write_PUBKEY(keyfile, pkey);
     if (ret == 0) {
         fprintf(stderr, "Unable to write public key file\n");
         exit(5);
     }
     fclose(keyfile);
     RSA_free(rsa);
+    EVP_PKEY_free(pkey);
     exit(0);
 }
