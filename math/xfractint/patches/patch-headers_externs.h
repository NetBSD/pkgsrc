$NetBSD: patch-headers_externs.h,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- headers/externs.h.orig	2015-04-26 13:25:57.000000000 +0000
+++ headers/externs.h
@@ -63,7 +63,7 @@ extern int                   calc_status
 extern char                  calibrate;
 extern int                   checkcurdir;
 extern int                   chkd_vvs;
-extern long                  cimag;
+extern long                  my_cimag;
 extern double                closenuff;
 extern double                closeprox;
 extern _CMPLX                coefficient;
@@ -89,7 +89,7 @@ extern double                cosx;
 extern LDBL                  cosx;
 #endif
 extern int                   cpu;
-extern long                  creal;
+extern long                  my_creal;
 extern int                   curcol;
 extern int                   curpass;
 extern int                   currow;
