$NetBSD: patch-pgp.c,v 1.1 2011/12/18 11:33:42 obache Exp $

* for OpenSSL without MD2 support.

--- pgp.c.orig	2009-12-16 05:51:12.000000000 +0000
+++ pgp.c
@@ -763,7 +763,9 @@ pgp_hashalg_md(int alg)
 	case PGP_HASH_SHA1:		return EVP_sha1();
 	case PGP_HASH_RIPEMD160:	return EVP_ripemd160();
 	case PGP_HASH_DWSHA:		return NULL;
+#ifndef OPENSSL_NO_MD2
 	case PGP_HASH_MD2:		return EVP_md2();
+#endif
 	case PGP_HASH_TIGER192:		return NULL;
 	case PGP_HASH_HAVAL_5_160:	return NULL;
 	}
@@ -1418,11 +1420,13 @@ pgp_comp_data(struct pgp_pkt *pkt)
 static const EVP_MD *
 pgp_asn1_md(u_char **pp, int len)
 {
+#ifndef OPENSSL_NO_MD2
 	static const u_char asn1_md2[] = {
 		0x30, 0x20, 0x30, 0x0C, 0x06, 0x08, 0x2A, 0x86,
 		0x48, 0x86, 0xF7, 0x0D, 0x02, 0x02, 0x05, 0x00,
 		0x04, 0x10
 	};
+#endif
 	static const u_char asn1_md5[] = {
 		0x30, 0x20, 0x30, 0x0C, 0x06, 0x08, 0x2A, 0x86,
 		0x48, 0x86, 0xF7, 0x0D, 0x02, 0x05, 0x05, 0x00,
@@ -1437,11 +1441,13 @@ pgp_asn1_md(u_char **pp, int len)
 		0x03, 0x02, 0x1A, 0x05, 0x00, 0x04, 0x14
 	};
 
+#ifndef OPENSSL_NO_MD2
 	if (len > sizeof(asn1_md2)
 	&&  memcmp(*pp, asn1_md2, sizeof(asn1_md2)) == 0) {
 		*pp += sizeof(asn1_md2);
 		return EVP_md2();
 	}
+#endif
 	if (len > sizeof(asn1_md5)
 	&&  memcmp(*pp, asn1_md5, sizeof(asn1_md5)) == 0) {
 		*pp += sizeof(asn1_md5);
@@ -1969,7 +1975,9 @@ pgp_show_hashalg(int alg)
 	case PGP_HASH_SHA1:		return "SHA1";
 	case PGP_HASH_RIPEMD160:	return "RIPEMD160";
 	case PGP_HASH_DWSHA:		return "DWSHA";
+#ifndef OPENSSL_NO_MD2
 	case PGP_HASH_MD2:		return "MD2";
+#endif
 	case PGP_HASH_TIGER192:		return "TIGER192";
 	case PGP_HASH_HAVAL_5_160:	return "HAVAL-5-160";
 	}
