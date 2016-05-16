$NetBSD: patch-src_libjasper_base_jas__seq.c,v 1.2 2016/05/16 14:03:40 he Exp $

CVE-2016-2089 denial of service. Via Debian.

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/base/jas_seq.c.old	2016-03-31 14:47:00.000000000 +0200
+++ src/libjasper/base/jas_seq.c	2016-03-31 14:47:50.000000000 +0200
@@ -114,7 +114,7 @@
 	matrix->datasize_ = numrows * numcols;
 
 	if (matrix->maxrows_ > 0) {
-		if (!(matrix->rows_ = jas_malloc(matrix->maxrows_ *
+		if (!(matrix->rows_ = jas_alloc2(matrix->maxrows_,
 		  sizeof(jas_seqent_t *)))) {
 			jas_matrix_destroy(matrix);
 			return 0;
@@ -122,7 +122,7 @@
 	}
 
 	if (matrix->datasize_ > 0) {
-		if (!(matrix->data_ = jas_malloc(matrix->datasize_ *
+		if (!(matrix->data_ = jas_alloc2(matrix->datasize_,
 		  sizeof(jas_seqent_t)))) {
 			jas_matrix_destroy(matrix);
 			return 0;
@@ -220,7 +220,7 @@
 	mat0->numrows_ = r1 - r0 + 1;
 	mat0->numcols_ = c1 - c0 + 1;
 	mat0->maxrows_ = mat0->numrows_;
-	mat0->rows_ = jas_malloc(mat0->maxrows_ * sizeof(jas_seqent_t *));
+	mat0->rows_ = jas_alloc2(mat0->maxrows_, sizeof(jas_seqent_t *));
 	for (i = 0; i < mat0->numrows_; ++i) {
 		mat0->rows_[i] = mat1->rows_[r0 + i] + c0;
 	}
@@ -262,6 +262,10 @@
 	int rowstep;
 	jas_seqent_t *data;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
 	  rowstart += rowstep) {
@@ -282,6 +286,10 @@
 	jas_seqent_t *data;
 	int rowstep;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
 	  rowstart += rowstep) {
@@ -306,6 +314,10 @@
 	int rowstep;
 	jas_seqent_t *data;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	assert(n >= 0);
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
@@ -325,6 +337,10 @@
 	int rowstep;
 	jas_seqent_t *data;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
 	  rowstart += rowstep) {
@@ -367,6 +383,10 @@
 	int rowstep;
 	jas_seqent_t *data;
 
+	if (!matrix->rows_) {
+		return;
+	}
+
 	rowstep = jas_matrix_rowstep(matrix);
 	for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i,
 	  rowstart += rowstep) {
@@ -432,7 +452,8 @@
 	for (i = 0; i < jas_matrix_numrows(matrix); ++i) {
 		for (j = 0; j < jas_matrix_numcols(matrix); ++j) {
 			x = jas_matrix_get(matrix, i, j);
-			sprintf(sbuf, "%s%4ld", (strlen(buf) > 0) ? " " : "",
+			snprintf(sbuf, sizeof sbuf, 
+			    "%s%4ld", (strlen(buf) > 0) ? " " : "",
 			  JAS_CAST(long, x));
 			n = strlen(buf);
 			if (n + strlen(sbuf) > MAXLINELEN) {
