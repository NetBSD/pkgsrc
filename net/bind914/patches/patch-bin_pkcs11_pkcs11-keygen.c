$NetBSD: patch-bin_pkcs11_pkcs11-keygen.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Honor HAVE_PKCS11_ECDSA.

--- bin/pkcs11/pkcs11-keygen.c.orig	2019-02-27 23:42:04.000000000 +0000
+++ bin/pkcs11/pkcs11-keygen.c
@@ -421,13 +421,23 @@ main(int argc, char *argv[]) {
 		id_offset = ECC_ID;
 
 		if (bits == 256) {
+#if HAVE_PKCS11_ECDSA
 			public_template[4].pValue = pk11_ecc_prime256v1;
 			public_template[4].ulValueLen =
 				sizeof(pk11_ecc_prime256v1);
+#else
+			fprintf(stderr, "PRIME256v1 is not supported\n");
+			usage();
+#endif
 		} else {
+#if HAVE_PKCS11_ECDSA
 			public_template[4].pValue = pk11_ecc_secp384r1;
 			public_template[4].ulValueLen =
 				sizeof(pk11_ecc_secp384r1);
+#else
+			fprintf(stderr, "SEP384r1 is not supported\n");
+			usage();
+#endif
 		}
 
 		break;
