$NetBSD: patch-externs.h,v 1.1 2013/01/11 13:29:34 joerg Exp $

--- externs.h.orig	2013-01-11 00:41:19.000000000 +0000
+++ externs.h
@@ -60,7 +60,7 @@ extern int (*                calctype)(v
 extern int                   calc_status;
 extern char                  calibrate;
 extern int                   checkcurdir;
-extern long                  cimag;
+extern long                  my_cimag;
 extern double                closenuff;
 extern double                closeprox;
 extern _CMPLX                coefficient;
@@ -82,7 +82,7 @@ extern int                   comparegif;
 extern long                  con;
 extern double                cosx;
 extern int                   cpu;
-extern long                  creal;
+extern long                  my_creal;
 extern int                   curcol;
 extern int                   curpass;
 extern int                   currow;
