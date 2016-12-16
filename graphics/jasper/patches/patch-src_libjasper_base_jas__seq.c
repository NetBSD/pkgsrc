$NetBSD: patch-src_libjasper_base_jas__seq.c,v 1.3 2016/12/16 09:44:44 he Exp $

Replace one sprintf with snprintf.

--- src/libjasper/base/jas_seq.c.orig	2016-03-31 14:47:00.000000000 +0200
+++ src/libjasper/base/jas_seq.c	2016-03-31 14:47:50.000000000 +0200
@@ -493,7 +493,8 @@ int jas_seq2d_output(jas_matrix_t *matri
 	for (i = 0; i < jas_matrix_numrows(matrix); ++i) {
 		for (j = 0; j < jas_matrix_numcols(matrix); ++j) {
 			x = jas_matrix_get(matrix, i, j);
-			sprintf(sbuf, "%s%4ld", (strlen(buf) > 0) ? " " : "",
+			snprintf(sbuf, sizeof sbuf,
+				 "%s%4ld", (strlen(buf) > 0) ? " " : "",
 			  JAS_CAST(long, x));
 			n = JAS_CAST(int, strlen(buf));
 			if (n + JAS_CAST(int, strlen(sbuf)) > MAXLINELEN) {
