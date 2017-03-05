$NetBSD: patch-src_libjasper_jpc_jpc__enc.c,v 1.3 2017/03/05 12:49:52 wiz Exp $

Replace an sprintf() with snprintf().

--- src/libjasper/jpc/jpc_enc.c.orig	2017-03-02 18:03:10.000000000 +0000
+++ src/libjasper/jpc/jpc_enc.c
@@ -966,7 +966,8 @@ startoff = jas_stream_getrwcount(enc->ou
 		jas_eprintf("cannot create COM marker\n");
 		return -1;
 	}
-	sprintf(buf, "Creator: JasPer Version %s", jas_getversion());
+	snprintf(buf, sizeof buf, "Creator: JasPer Version %s",
+		 jas_getversion());
 	com = &enc->mrk->parms.com;
 	com->len = JAS_CAST(uint_fast16_t, strlen(buf));
 	com->regid = JPC_COM_LATIN;
