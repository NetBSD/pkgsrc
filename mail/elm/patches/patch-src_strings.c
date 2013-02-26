$NetBSD: patch-src_strings.c,v 1.1 2013/02/26 11:08:17 joerg Exp $

--- src/strings.c.orig	2013-02-25 16:42:37.000000000 +0000
+++ src/strings.c
@@ -165,8 +165,7 @@ char *string;
 	return string;
 }
 
-split_word(buffer, first, rest)
-char *buffer, *first, *rest;
+void split_word(char *buffer, char *first, char *rest)
 {
 	int len;
 	/** Rip the buffer into first word and rest of word, translating it
