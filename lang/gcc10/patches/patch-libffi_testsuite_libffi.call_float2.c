$NetBSD: patch-libffi_testsuite_libffi.call_float2.c,v 1.1 2020/05/10 15:02:44 maya Exp $

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90146

--- libffi/testsuite/libffi.call/float2.c.orig	2013-06-01 17:08:18.000000000 +0000
+++ libffi/testsuite/libffi.call/float2.c
@@ -45,7 +45,7 @@ int main (void)
   /* This is ifdef'd out for now. long double support under SunOS/gcc
      is pretty much non-existent.  You'll get the odd bus error in library
      routines like printf().  */
-  printf ("%Lf, %Lf, %Lf, %Lf\n", ld, ldblit(f), ld - ldblit(f), LDBL_EPSILON);
+  printf ("%Lf, %Lf, %Lf, %Lf\n", (long double)ld, (long double)ldblit(f), (long double)(ld - ldblit(f)), (long double)LDBL_EPSILON);
 #endif
 
   /* These are not always the same!! Check for a reasonable delta */
