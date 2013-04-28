$NetBSD: patch-source_tags.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Silence gcc 4.5 warnings about uninitialized variables.

--- source/tags.c~	2004-08-01 10:06:11.000000000 +0000
+++ source/tags.c
@@ -1945,6 +1945,10 @@ static int loadTipsFile(const char *tips
     int nTipsAdded=0, langMode = PLAIN_LANGUAGE_MODE, oldLangMode;
     int currLine=0, code, blkLine;
     tf_alias *aliases=NULL, *tmp_alias;
+
+    /* silence gcc 4.5 warnings */
+    body = NULL;
+    blkLine = 0;
     
     if(recLevel > MAX_TAG_INCLUDE_RECURSION_LEVEL) {
         fprintf(stderr, "nedit: Warning: Reached recursion limit before loading calltips file:\n\t%s\n", tipsFile);
