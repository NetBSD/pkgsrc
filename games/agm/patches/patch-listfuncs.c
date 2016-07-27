$NetBSD: patch-listfuncs.c,v 1.1 2016/07/27 20:37:27 kamil Exp $

Fix K&R code.

--- listfuncs.c.orig	2016-07-27 20:12:55.344357171 +0000
+++ listfuncs.c
@@ -18,8 +18,10 @@ char listfuncs_RCSid[] = "Revision: 1.3 
 
 #include "agm.h"
 
-destroy_list (ls, le)
-    struct wnode *ls, *le;
+#include <stdlib.h>
+
+void
+destroy_list (struct wnode *ls, struct wnode *le)
 {
   struct wnode *loop = ls, *last;
 
@@ -30,9 +32,7 @@ destroy_list (ls, le)
   }
 }
 
-int addword (word, ls, le)
-    char *word;
-    struct wnode **ls, **le;
+int addword (char *word, struct wnode **ls, struct wnode **le)
 {
   struct wnode *new;
   int i;
