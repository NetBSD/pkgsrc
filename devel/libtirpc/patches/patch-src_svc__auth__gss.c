$NetBSD: patch-src_svc__auth__gss.c,v 1.1 2023/08/29 11:28:40 vins Exp $

Replace deprecated gss_sign().

--- src/svc_auth_gss.c.orig	2022-08-02 18:55:33.000000000 +0000
+++ src/svc_auth_gss.c
@@ -349,7 +349,7 @@ svcauth_gss_accept_sec_context(struct sv
 		seqbuf.value = &seq;
 		seqbuf.length = sizeof(seq);
 
-		maj_stat = gss_sign(&min_stat, gd->ctx, GSS_C_QOP_DEFAULT,
+		maj_stat = gss_get_mic(&min_stat, gd->ctx, GSS_C_QOP_DEFAULT,
 				    &seqbuf, &checksum);
 
 		if (maj_stat != GSS_S_COMPLETE)
