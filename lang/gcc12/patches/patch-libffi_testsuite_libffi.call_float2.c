$NetBSD: patch-libffi_testsuite_libffi.call_float2.c,v 1.1 2022/06/16 15:43:55 adam Exp $

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90146

--- libffi/testsuite/libffi.call/float2.c.orig	2022-05-06 07:30:59.000000000 +0000
+++ libffi/testsuite/libffi.call/float2.c
@@ -47,7 +47,7 @@ int main (void)
   /* long double support under SunOS/gcc is pretty much non-existent.
      You'll get the odd bus error in library routines like printf() */
 #else
-  printf ("%Lf, %Lf, %Lf, %Lf\n", ld, ldblit(f), ld - ldblit(f), LDBL_EPSILON);
+  printf ("%Lf, %Lf, %Lf, %Lf\n", (long double)ld, (long double)ldblit(f), (long double)(ld - ldblit(f)), (long double)LDBL_EPSILON);
 #endif
 
   /* These are not always the same!! Check for a reasonable delta */
