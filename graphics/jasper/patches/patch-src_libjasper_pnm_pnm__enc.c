$NetBSD: patch-src_libjasper_pnm_pnm__enc.c,v 1.2 2016/12/16 09:44:44 he Exp $

Replace one sprintf() with snprintf().

--- src/libjasper/pnm/pnm_enc.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/pnm/pnm_enc.c
@@ -374,7 +374,7 @@ static int pnm_putdata(jas_stream_t *out
 						}
 					}
 				} else {
-					n = sprintf(buf, "%s%ld", ((!(!x && !cmptno)) ? " " : ""),
+					n = snprintf(buf, sizeof buf, "%s%ld", ((!(!x && !cmptno)) ? " " : ""),
 					  (long) v);
 					if (linelen > 0 && linelen + n > PNM_MAXLINELEN) {
 						jas_stream_printf(out, "\n");
