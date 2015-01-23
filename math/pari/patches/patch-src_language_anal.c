$NetBSD: patch-src_language_anal.c,v 1.1 2015/01/23 15:07:53 joerg Exp $

--- src/language/anal.c.orig	2015-01-22 19:57:33.000000000 +0000
+++ src/language/anal.c
@@ -2520,7 +2520,7 @@ int_read(char **s)
 }
 
 GEN
-strtoi(char *s) { return int_read(&s); }
+pari_strtoi(char *s) { return int_read(&s); }
 
 GEN 
 strtor(char *s, long PREC)
