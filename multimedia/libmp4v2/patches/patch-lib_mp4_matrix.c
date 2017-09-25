$NetBSD: patch-lib_mp4_matrix.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/matrix.c.orig	2017-09-25 14:54:37.160447502 +0000
+++ lib/mp4/matrix.c
@@ -3,7 +3,7 @@
 
 
 
-int quicktime_matrix_init(quicktime_matrix_t *matrix)
+void quicktime_matrix_init(quicktime_matrix_t *matrix)
 {
 	int i;
 	for(i = 0; i < 9; i++) matrix->values[i] = 0;
@@ -11,11 +11,11 @@ int quicktime_matrix_init(quicktime_matr
 	matrix->values[8] = 16384;
 }
 
-int quicktime_matrix_delete(quicktime_matrix_t *matrix)
+void quicktime_matrix_delete(quicktime_matrix_t *matrix)
 {
 }
 
-int quicktime_read_matrix(quicktime_t *file, quicktime_matrix_t *matrix)
+void quicktime_read_matrix(quicktime_t *file, quicktime_matrix_t *matrix)
 {
 	int i = 0;
 	for(i = 0; i < 9; i++)
@@ -24,7 +24,7 @@ int quicktime_read_matrix(quicktime_t *f
 	}
 }
 
-int quicktime_matrix_dump(quicktime_matrix_t *matrix)
+void quicktime_matrix_dump(quicktime_matrix_t *matrix)
 {
 	int i;
 	printf("   matrix");
@@ -32,7 +32,7 @@ int quicktime_matrix_dump(quicktime_matr
 	printf("\n");
 }
 
-int quicktime_write_matrix(quicktime_t *file, quicktime_matrix_t *matrix)
+void quicktime_write_matrix(quicktime_t *file, quicktime_matrix_t *matrix)
 {
 	int i;
 	for(i = 0; i < 9; i++)
