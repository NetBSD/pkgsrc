$NetBSD: patch-lib_libpam_openpam__ctype.h,v 1.1 2014/06/10 13:17:42 joerg Exp $

--- lib/libpam/openpam_ctype.h.orig	2013-09-07 13:28:00.000000000 +0000
+++ lib/libpam/openpam_ctype.h
@@ -42,7 +42,7 @@
  * Evaluates to non-zero if the argument is an uppercase letter.
  */
 #define is_upper(ch)				\
-	(ch >= 'A' && ch <= 'A')
+	(ch >= 'A' && ch <= 'Z')
 
 /*
  * Evaluates to non-zero if the argument is a lowercase letter.
