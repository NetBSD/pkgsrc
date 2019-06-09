$NetBSD: patch-src_main_character.c,v 1.4 2019/06/09 13:39:12 wen Exp $

--- src/main/character.c.orig	2019-06-08 09:21:28.671757451 +0000
+++ src/main/character.c
@@ -1601,7 +1601,7 @@ SEXP attribute_hidden do_strtrim(SEXP ca
     return s;
 }
 
-static int strtoi(SEXP s, int base)
+static int my_strtoi(SEXP s, int base)
 {
     if(s == NA_STRING || CHAR(s)[0] == '\0') return(NA_INTEGER);
 
@@ -1634,7 +1634,7 @@ SEXP attribute_hidden do_strtoi(SEXP cal
 
     PROTECT(ans = allocVector(INTSXP, n = LENGTH(x)));
     for(i = 0; i < n; i++)
-	INTEGER(ans)[i] = strtoi(STRING_ELT(x, i), base);
+	INTEGER(ans)[i] = my_strtoi(STRING_ELT(x, i), base);
     UNPROTECT(1);
 
     return ans;
