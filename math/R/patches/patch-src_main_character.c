$NetBSD: patch-src_main_character.c,v 1.2 2015/06/30 02:38:52 wen Exp $

--- src/main/character.c.orig	2015-06-29 21:44:13.000000000 +0000
+++ src/main/character.c
@@ -1360,7 +1360,7 @@ SEXP attribute_hidden do_strtrim(SEXP ca
     return s;
 }
 
-static int strtoi(SEXP s, int base)
+static int my_strtoi(SEXP s, int base)
 {
     long int res;
     char *endp;
@@ -1394,7 +1394,7 @@ SEXP attribute_hidden do_strtoi(SEXP cal
 
     PROTECT(ans = allocVector(INTSXP, n = LENGTH(x)));
     for(i = 0; i < n; i++)
-	INTEGER(ans)[i] = strtoi(STRING_ELT(x, i), base);
+	INTEGER(ans)[i] = my_strtoi(STRING_ELT(x, i), base);
     UNPROTECT(1);
 
     return ans;
