$NetBSD: patch-g10_import.c,v 1.1 2026/09/28 16:57:08 wiz Exp $

Fix ECDH key problem, from upstream.

--- g10/import.c.orig	2026-09-22 09:20:47.000000000 +0000
+++ g10/import.c
@@ -2732,11 +2732,11 @@ build_mode1003_sexp (PKT_public_key *pk, gcry_sexp_t *
       else if (openpgp_oid_is_cv25519 (pk->pkey[0]))
         err = gcry_sexp_build
           (&skey,NULL,"(private-key(ecc(curve %s)(flags djb-tweak)(q%m)(d%m)))",
-           curvename, pk->pkey[2], pk->pkey[3]);
+           curvename, pk->pkey[1], pk->pkey[3]);
       else
         err = gcry_sexp_build
           (&skey,NULL,"(private-key(ecc(curve %s)(q%m)(d%m)))",
-           curvename, pk->pkey[2], pk->pkey[3]);
+           curvename, pk->pkey[1], pk->pkey[3]);
       break;
 
     case PUBKEY_ALGO_X25519:
