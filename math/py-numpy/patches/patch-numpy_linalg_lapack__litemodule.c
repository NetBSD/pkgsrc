$NetBSD: patch-numpy_linalg_lapack__litemodule.c,v 1.1 2019/02/01 09:24:25 adam Exp $

Add function definition for FNAME(MAIN_).

--- numpy/linalg/lapack_litemodule.c.orig	2015-04-16 14:14:55.000000000 +0000
+++ numpy/linalg/lapack_litemodule.c
@@ -17,6 +17,8 @@ typedef struct { float r, i; } f2c_compl
 typedef struct { double r, i; } f2c_doublecomplex;
 /* typedef long int (*L_fp)(); */
 
+int FNAME(MAIN_)() { return 0; }
+
 extern int FNAME(dgelsd)(int *m, int *n, int *nrhs,
                           double a[], int *lda, double b[], int *ldb,
                           double s[], double *rcond, int *rank,
