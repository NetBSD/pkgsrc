$NetBSD: patch-src_main_character.c,v 1.3 2016/07/26 04:53:33 wen Exp $

--- src/main/character.c.orig	2016-06-01 22:15:06.000000000 +0000
+++ src/main/character.c
@@ -1564,7 +1564,7 @@ SEXP attribute_hidden do_strtrim(SEXP ca
     return s;
 }
 
-static int strtoi(SEXP s, int base)
+static int my_strtoi(SEXP s, int base)
 {
     long int res;
     char *endp;
@@ -1598,7 +1598,7 @@ SEXP attribute_hidden do_strtoi(SEXP cal
 
     PROTECT(ans = allocVector(INTSXP, n = LENGTH(x)));
     for(i = 0; i < n; i++)
-	INTEGER(ans)[i] = strtoi(STRING_ELT(x, i), base);
+	INTEGER(ans)[i] = my_strtoi(STRING_ELT(x, i), base);
     UNPROTECT(1);
 
     return ans;
