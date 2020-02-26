$NetBSD: patch-testsuite_libffi.call_float2.c,v 1.1 2020/02/26 19:15:44 adam Exp $

The %Lf printf format expects "long double", so cast args accordingly.

--- testsuite/libffi.call/float2.c.orig	2019-10-31 14:49:54.000000000 +0000
+++ testsuite/libffi.call/float2.c
@@ -47,7 +47,7 @@ int main (void)
   /* long double support under SunOS/gcc is pretty much non-existent.
      You'll get the odd bus error in library routines like printf() */
 #else
-  printf ("%Lf, %Lf, %Lf, %Lf\n", ld, ldblit(f), ld - ldblit(f), LDBL_EPSILON);
+  printf ("%Lf, %Lf, %Lf, %Lf\n", (long double)ld, (long double)ldblit(f), (long double)(ld - ldblit(f)), (long double)LDBL_EPSILON);
 #endif
 
   /* These are not always the same!! Check for a reasonable delta */
