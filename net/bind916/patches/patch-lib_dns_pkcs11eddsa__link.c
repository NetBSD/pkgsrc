$NetBSD: patch-lib_dns_pkcs11eddsa__link.c,v 1.1 2020/12/19 16:41:36 taca Exp $

Fix build problem when memmove() is cpp macro.

--- lib/dns/pkcs11eddsa_link.c.orig	2020-12-07 08:16:53.000000000 +0000
+++ lib/dns/pkcs11eddsa_link.c
@@ -409,13 +409,14 @@ pkcs11eddsa_compare(const dst_key_t *key
 	case DST_ALG_ED25519:                                                  \
 		attr->pValue = isc_mem_get(key->mctx,                          \
 					   sizeof(PK11_ECX_ED25519));          \
-		memmove(attr->pValue, PK11_ECX_ED25519,                        \
+		memmove(attr->pValue, (PK11_ECX_ED25519),                      \
 			sizeof(PK11_ECX_ED25519));                             \
 		attr->ulValueLen = sizeof(PK11_ECX_ED25519);                   \
 		break;                                                         \
 	case DST_ALG_ED448:                                                    \
 		attr->pValue = isc_mem_get(key->mctx, sizeof(PK11_ECX_ED448)); \
-		memmove(attr->pValue, PK11_ECX_ED448, sizeof(PK11_ECX_ED448)); \
+		memmove(attr->pValue, (PK11_ECX_ED448),                        \
+			sizeof(PK11_ECX_ED448));                               \
 		attr->ulValueLen = sizeof(PK11_ECX_ED448);                     \
 		break;                                                         \
 	default:                                                               \
