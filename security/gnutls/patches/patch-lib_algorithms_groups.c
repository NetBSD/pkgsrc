$NetBSD: patch-lib_algorithms_groups.c,v 1.1 2024/11/11 02:03:54 gutteridge Exp $

Fix builds with older GCCs like 7.5 on NetBSD 9.x that can't handle this.

--- lib/algorithms/groups.c.orig	2024-10-30 04:41:21.000000000 +0000
+++ lib/algorithms/groups.c
@@ -90,7 +90,13 @@ static const gnutls_group_entry_st suppo
 		.tls_id = 25,
 		.pk = GNUTLS_PK_ECDSA,
 	},
-	group_x25519,
+	{
+		.name = "X25519",
+		.id = GNUTLS_GROUP_X25519,
+		.curve = GNUTLS_ECC_CURVE_X25519,
+		.tls_id = 29,
+		.pk = GNUTLS_PK_ECDH_X25519,
+	},
 #ifdef ENABLE_GOST
 	/* draft-smyshlyaev-tls12-gost-suites-06, Section 6 */
 	{
