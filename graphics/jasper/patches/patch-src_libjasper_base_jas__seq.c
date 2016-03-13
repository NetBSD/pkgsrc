$NetBSD: patch-src_libjasper_base_jas__seq.c,v 1.1 2016/03/13 04:11:18 tnn Exp $

CVE-2016-2089 denial of service. Via Debian.

--- src/libjasper/base/jas_seq.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/base/jas_seq.c
@@ -262,6 +262,10 @@ void jas_matrix_divpow2(jas_matrix_t *ma
 	int rowstep;
 	jas_seqent_t *data;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
 	  rowstart += rowstep) {
@@ -282,6 +286,10 @@ void jas_matrix_clip(jas_matrix_t *matri
 	jas_seqent_t *data;
 	int rowstep;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
 	  rowstart += rowstep) {
@@ -306,6 +314,10 @@ void jas_matrix_asr(jas_matrix_t *matrix
 	int rowstep;
 	jas_seqent_t *data;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	assert(n >= 0);
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
@@ -325,6 +337,10 @@ void jas_matrix_asl(jas_matrix_t *matrix
 	int rowstep;
 	jas_seqent_t *data;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
 	  rowstart += rowstep) {
@@ -367,6 +383,10 @@ void jas_matrix_setall(jas_matrix_t *mat
 	int rowstep;
 	jas_seqent_t *data;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
 	  rowstart += rowstep) {
