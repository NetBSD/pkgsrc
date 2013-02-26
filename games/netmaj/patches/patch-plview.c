$NetBSD: patch-plview.c,v 1.1 2013/02/26 10:29:34 joerg Exp $

--- plview.c.orig	2013-02-25 20:51:05.000000000 +0000
+++ plview.c
@@ -34,7 +34,7 @@ extern char *pai_strings[];
 river_t mrv[4][RIVER_MAX];
 
 FILE *df,*plog;
-FILE *log;
+FILE *logp;
 FILE *fp;
 FILE *ofp;
 
