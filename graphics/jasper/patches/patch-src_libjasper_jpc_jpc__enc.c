$NetBSD: patch-src_libjasper_jpc_jpc__enc.c,v 1.2 2016/12/16 09:44:44 he Exp $

Replace an sprintf() with snprintf().

--- src/libjasper/jpc/jpc_enc.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_enc.c
@@ -957,7 +957,8 @@ startoff = jas_stream_getrwcount(enc->ou
 	if (!(enc->mrk = jpc_ms_create(JPC_MS_COM))) {
 		return -1;
 	}
-	sprintf(buf, "Creator: JasPer Version %s", jas_getversion());
+	snprintf(buf, sizeof buf, "Creator: JasPer Version %s",
+		 jas_getversion());
 	com = &enc->mrk->parms.com;
 	com->len = JAS_CAST(uint_fast16_t, strlen(buf));
 	com->regid = JPC_COM_LATIN;
