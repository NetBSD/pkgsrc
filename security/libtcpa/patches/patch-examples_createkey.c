$NetBSD: patch-examples_createkey.c,v 1.1 2020/03/27 20:57:12 joerg Exp $

--- examples/createkey.c.orig	2020-03-27 18:50:53.384965280 +0000
+++ examples/createkey.c
@@ -21,7 +21,7 @@ int main(int argc, char *argv[])
     keydata q;                    /* keydata structure for resulting key */
     RSA *rsa;                     /* OpenSSL format Public Key */
     FILE *keyfile;                /* output file for public key */
-    EVP_PKEY pkey;                /* OpenSSL public key */
+    EVP_PKEY *pkey;                /* OpenSSL public key */
     unsigned char pkeyname[256];  /* file name string of public key file */
 
     if (argc < 5) {
@@ -77,18 +77,20 @@ int main(int argc, char *argv[])
     }
     OpenSSL_add_all_algorithms();
     snprintf(pkeyname,sizeof(pkeyname),"%s.pem", argv[3]);
-    EVP_PKEY_assign_RSA(&pkey, rsa);
+    pkey = EVP_PKEY_new();
+    EVP_PKEY_assign_RSA(pkey, rsa);
     keyfile = fopen(pkeyname, "w");
     if (keyfile == NULL) {
         fprintf(stderr, "Unable to create public key file\n");
         exit(-1);
     }
-    ret = PEM_write_PUBKEY(keyfile, &pkey);
+    ret = PEM_write_PUBKEY(keyfile, pkey);
     if (ret == 0) {
         fprintf(stderr, "Unable to write public key file\n");
         exit(-1);
     }
     fclose(keyfile);
     RSA_free(rsa);
+    EVP_PKEY_free(pkey);
     exit(0);
 }
