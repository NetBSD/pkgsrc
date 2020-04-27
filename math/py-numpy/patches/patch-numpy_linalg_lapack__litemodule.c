$NetBSD: patch-numpy_linalg_lapack__litemodule.c,v 1.2 2020/04/27 17:00:35 adam Exp $

Add function definition for FNAME(MAIN_).

--- numpy/linalg/lapack_litemodule.c.orig	2020-04-19 08:51:58.000000000 +0000
+++ numpy/linalg/lapack_litemodule.c
@@ -37,6 +37,8 @@ typedef struct { float r, i; } f2c_compl
 typedef struct { double r, i; } f2c_doublecomplex;
 /* typedef long int (*L_fp)(); */
 
+int FNAME(MAIN_)() { return 0; }
+
 extern fortran_int FNAME(dgelsd)(fortran_int *m, fortran_int *n, fortran_int *nrhs,
                           double a[], fortran_int *lda, double b[], fortran_int *ldb,
                           double s[], double *rcond, fortran_int *rank,
