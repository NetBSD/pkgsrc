$NetBSD: patch-src_lexi.c,v 1.2 2013/12/31 16:14:15 jakllsch Exp $

--- src/lexi.c.orig	2008-03-11 18:50:42.000000000 +0000
+++ src/lexi.c
@@ -211,9 +211,6 @@ templ_ty *is_reserved (const char *str, 
 #undef MIN_WORD_LENGTH
 #undef MAX_WORD_LENGTH
 
-#ifdef __GNUC__
-__inline
-#endif
 templ_ty *is_reserved_cc (register const char *str, register unsigned int len);
 
 #include "gperf-cc.c"
