$NetBSD: patch-lib_dns_pkcs11ecdsa__link.c,v 1.1 2020/12/19 16:41:36 taca Exp $

Fix build problem when memmove() is cpp macro.

--- lib/dns/pkcs11ecdsa_link.c.orig	2020-12-07 08:16:53.000000000 +0000
+++ lib/dns/pkcs11ecdsa_link.c
@@ -435,14 +435,14 @@ pkcs11ecdsa_compare(const dst_key_t *key
 	case DST_ALG_ECDSA256:                                           \
 		attr->pValue = isc_mem_get(key->mctx,                    \
 					   sizeof(PK11_ECC_PRIME256V1)); \
-		memmove(attr->pValue, PK11_ECC_PRIME256V1,               \
+		memmove(attr->pValue, (PK11_ECC_PRIME256V1),		\
 			sizeof(PK11_ECC_PRIME256V1));                    \
 		attr->ulValueLen = sizeof(PK11_ECC_PRIME256V1);          \
 		break;                                                   \
 	case DST_ALG_ECDSA384:                                           \
 		attr->pValue = isc_mem_get(key->mctx,                    \
 					   sizeof(PK11_ECC_SECP384R1));  \
-		memmove(attr->pValue, PK11_ECC_SECP384R1,                \
+		memmove(attr->pValue, (PK11_ECC_SECP384R1),		\
 			sizeof(PK11_ECC_SECP384R1));                     \
 		attr->ulValueLen = sizeof(PK11_ECC_SECP384R1);           \
 		break;                                                   \
