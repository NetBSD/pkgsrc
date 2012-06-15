$NetBSD: patch-src_tokenise.c,v 1.1 2012/06/15 18:51:32 joerg Exp $

--- src/tokenise.c.orig	2012-06-15 14:24:46.000000000 +0000
+++ src/tokenise.c
@@ -154,9 +154,9 @@ ZDictionary* dictionary_cache(const ZUWo
 
 int cache = 1;
 
-inline ZUWord lookup_word(unsigned int*  word,
-			  int            wordlen,
-			  ZUWord         dct)
+ZUWord lookup_word(unsigned int*  word,
+		   int            wordlen,
+		   ZUWord         dct)
 {
   ZByte packed[12];
   int zscii_len;
