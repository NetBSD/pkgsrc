$NetBSD: patch-src_main_character.c,v 1.7 2024/02/15 07:48:50 markd Exp $

rename strtoi() to avoild conflict with NetBSD function.

--- src/main/character.c.orig	2023-07-04 22:15:01.000000000 +0000
+++ src/main/character.c
@@ -1749,7 +1749,7 @@ attribute_hidden SEXP do_strtrim(SEXP ca
     return s;
 }
 
-static int strtoi(SEXP s, int base)
+static int strtoiR(SEXP s, int base)
 {
     if(s == NA_STRING || CHAR(s)[0] == '\0') return(NA_INTEGER);
 
@@ -1782,7 +1782,7 @@ attribute_hidden SEXP do_strtoi(SEXP cal
 
     PROTECT(ans = allocVector(INTSXP, n = LENGTH(x)));
     for(i = 0; i < n; i++)
-	INTEGER(ans)[i] = strtoi(STRING_ELT(x, i), base);
+	INTEGER(ans)[i] = strtoiR(STRING_ELT(x, i), base);
     UNPROTECT(1);
 
     return ans;
