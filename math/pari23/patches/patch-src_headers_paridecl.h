$NetBSD: patch-src_headers_paridecl.h,v 1.1 2016/03/03 13:23:22 wiz Exp $

--- src/headers/paridecl.h.orig	2015-01-22 19:57:35.000000000 +0000
+++ src/headers/paridecl.h
@@ -264,7 +264,7 @@ GEN     readseq(char *t);
 long    manage_var(long n, entree *ep);
 void    name_var(long n, char *s);
 GEN     strtoGENstr(const char *s);
-GEN     strtoi(char *s);
+GEN     pari_strtoi(char *s);
 GEN     strtor(char *s, long prec);
 GEN     type0(GEN x);
 
