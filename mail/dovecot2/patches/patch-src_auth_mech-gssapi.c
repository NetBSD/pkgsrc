$NetBSD: patch-src_auth_mech-gssapi.c,v 1.1 2020/12/03 19:30:00 markd Exp $

mech-gssapi - GSSAPI can contain NUL.
dovecot commit fea1bacab954d2f112da8a95756f198530e274af

--- src/auth/mech-gssapi.c.orig	2020-08-12 12:20:41.000000000 +0000
+++ src/auth/mech-gssapi.c
@@ -735,7 +735,7 @@ mech_gssapi_auth_free(struct auth_reques
 const struct mech_module mech_gssapi = {
 	"GSSAPI",
 
-	.flags = 0,
+	.flags = MECH_SEC_ALLOW_NULS,
 	.passdb_need = MECH_PASSDB_NEED_NOTHING,
 
 	mech_gssapi_auth_new,
