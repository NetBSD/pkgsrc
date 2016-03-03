$NetBSD: patch-src_language_anal.c,v 1.2 2016/03/03 13:28:22 wiz Exp $

--- src/language/anal.c.orig	2014-10-01 14:57:39.000000000 +0000
+++ src/language/anal.c
@@ -496,7 +496,7 @@ int_read(const char **s)
 }
 
 GEN
-strtoi(const char *s) { return int_read(&s); }
+pari_strtoi(const char *s) { return int_read(&s); }
 
 GEN
 strtor(const char *s, long prec)
