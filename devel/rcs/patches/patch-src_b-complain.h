$NetBSD: patch-src_b-complain.h,v 1.1 2014/11/11 15:38:04 joerg Exp $

--- src/b-complain.h.orig	2014-11-10 12:48:07.000000000 +0000
+++ src/b-complain.h
@@ -29,12 +29,11 @@ extern void generic_warn (char const *wh
   printf_string (2, 3);
 extern void generic_error (char const *who, char const *fmt, ...)
   printf_string (2, 3);
-extern void generic_fatal (char const *who, char const *fmt, ...)
-  printf_string (2, 3) exiting;
-extern void fatal_syntax (size_t lno, char const *fmt, ...)
-  printf_string (2, 3) exiting;
-extern void fatal_sys (char const *who)
-  exiting;
+extern exiting void generic_fatal (char const *who, char const *fmt, ...)
+  printf_string (2, 3);
+extern exiting void fatal_syntax (size_t lno, char const *fmt, ...)
+  printf_string (2, 3);
+extern exiting void fatal_sys (char const *who);
 
 /* Idioms.  Here, prefix P stands for "program" (general operation);
    M for "manifestation"; R for "repository".  */
