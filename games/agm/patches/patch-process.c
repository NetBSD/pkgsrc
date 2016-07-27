$NetBSD: patch-process.c,v 1.1 2016/07/27 20:37:27 kamil Exp $

Fix K&R code.

--- process.c.orig	2016-07-27 20:12:55.354713027 +0000
+++ process.c
@@ -27,14 +27,11 @@ char process_RCSid[] = "Revision: 1.6 $"
 
 #include "agm.h"
 
-process (word, ls, le, minlen, maxw, depth)
+void
+process (char *word, struct wnode *ls, struct wnode *le, unsigned int minlen, unsigned int maxw, unsigned int depth)
     /* searches the list ls - le for words which can be extracted from
        word; if a word extracts exactly, the words in prevs are printed out,
        otherwise, a sublist is built, and process() called recursively */
-    char *word;
-    struct wnode *ls, *le;
-    unsigned int minlen;
-    unsigned int depth;
 {
   char newword[WORDLEN];
   struct wnode *loop;
