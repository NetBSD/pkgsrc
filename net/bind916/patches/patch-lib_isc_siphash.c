$NetBSD: patch-lib_isc_siphash.c,v 1.3 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.

--- lib/isc/siphash.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/isc/siphash.c
@@ -90,8 +90,14 @@ isc_siphash24(const uint8_t *k, const ui
 	REQUIRE(k != NULL);
 	REQUIRE(out != NULL);
 
-	uint64_t k0 = U8TO64_LE(k);
-	uint64_t k1 = U8TO64_LE(k + 8);
+	uint64_t k0;
+	uint64_t k1;
+
+	memcpy(&k0, k, sizeof(k0));
+	memcpy(&k1, k + sizeof(k0), sizeof(k1));
+
+	k0 = le64toh(k0);
+	k1 = le64toh(k1);
 
 	uint64_t v0 = UINT64_C(0x736f6d6570736575) ^ k0;
 	uint64_t v1 = UINT64_C(0x646f72616e646f6d) ^ k1;
