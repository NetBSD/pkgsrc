$NetBSD: patch-libgfortran_intrinsics_string_intrinsics_inc.c,v 1.1 2024/04/01 14:33:57 js Exp $

--- libgfortran/intrinsics/string_intrinsics_inc.c.orig	2023-07-07 07:08:21.000000000 +0000
+++ libgfortran/intrinsics/string_intrinsics_inc.c
@@ -203,11 +203,7 @@ string_len_trim (gfc_charlen_type len, c
       /* Handle the first characters until we're aligned on a long word
 	 boundary.  Actually, s + i + 1 must be properly aligned, because
 	 s + i will be the last byte of a long word read.  */
-      starting = (
-#ifdef __INTPTR_TYPE__
-		  (__INTPTR_TYPE__)
-#endif
-		  (s + i + 1)) % long_len;
+      starting = ((intptr_t)(s + i + 1)) % long_len;
       i -= starting;
       for (; starting > 0; --starting)
 	if (s[i + starting] != ' ')
