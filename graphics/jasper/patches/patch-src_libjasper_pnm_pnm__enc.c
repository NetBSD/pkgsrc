$NetBSD: patch-src_libjasper_pnm_pnm__enc.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

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
