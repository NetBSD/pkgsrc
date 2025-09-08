$NetBSD: patch-alpine_smime.c,v 1.1 2025/09/08 12:57:17 vins Exp $

Use X509_ALGOR_get0 instead of directly accessing X509_ALGOR.

--- alpine/smime.c.orig	2022-06-03 00:14:00.463274817 +0000
+++ alpine/smime.c
@@ -292,7 +292,10 @@ format_smime_info(int pass, BODY *body, 
 		    gf_puts(_("The algorithm used to encrypt was "), pc);
 
 		    if(alg){
-			char *n = (char *) OBJ_nid2sn( OBJ_obj2nid(alg->algorithm));
+			const ASN1_OBJECT *obj;
+			const char *n;
+			X509_ALGOR_get0(&obj, NULL, NULL, alg);
+			n = OBJ_nid2sn(OBJ_obj2nid(obj));
 
 			gf_puts(n ? n : "<unknown>", pc);
 
