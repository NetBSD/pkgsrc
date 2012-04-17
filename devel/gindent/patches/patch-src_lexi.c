$NetBSD: patch-src_lexi.c,v 1.1 2012/04/17 17:42:33 joerg Exp $

--- src/lexi.c.orig	2012-04-17 16:05:19.000000000 +0000
+++ src/lexi.c
@@ -192,9 +192,6 @@ templ_ty *is_reserved (register const ch
 #undef MIN_WORD_LENGTH
 #undef MAX_WORD_LENGTH
 
-#ifdef __GNUC__
-__inline
-#endif
 templ_ty *is_reserved_cc (register const char *str, register unsigned int len);
 
 #include "gperf-cc.c"
