$NetBSD: patch-cfortran.h,v 1.1 2023/07/22 10:11:02 adam Exp $

Add definition for NetBSD and DragonFlyBSD.

--- cfortran.h.orig	2008-05-20 05:28:41.000000000 +1200
+++ cfortran.h
@@ -177,6 +177,9 @@ only C calling FORTRAN subroutines will 
 #if defined(__APPLE__)                         /* 11/2002 (CFITSIO) */
 #define f2cFortran
 #endif
+#if defined(__NetBSD__) || defined(__DragonFly__) /* 11/2002 (CFITSIO) */
+#define f2cFortran
+#endif
 #if defined(__hpux)             /* 921107: Use __hpux instead of __hp9000s300 */
 #define       hpuxFortran       /*         Should also allow hp9000s7/800 use.*/
 #endif
