$NetBSD: patch-folder.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- folder.c.orig	2026-05-16 21:26:49.061590925 +0000
+++ folder.c
@@ -9,7 +9,7 @@
 #include <unistd.h>
 #include <pwd.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "articles.h"
@@ -68,7 +68,7 @@ tilde_expansion(char **srcp, int compl)
     register char  *tail, x;
 
     tail = ++name;		/* skip ~ */
-    while (*tail && isascii(*tail) && !isspace(*tail) && *tail != '/')
+    while (*tail && ISASCII(*tail) && !ISSPACE(*tail) && *tail != '/')
 	tail++;
 
     if (compl && *tail != '/')
@@ -157,7 +157,7 @@ expand_file_name(char *dest, char *src, 
 	    }
 	    goto no_parse;
 	}
-	if ((expand_mode & 4) == 0 && c == '$' && !isalnum(src[2])) {
+	if ((expand_mode & 4) == 0 && c == '$' && !ISALNUM(src[2])) {
 	    remap = 0;
 	    cp = NULL;
 
@@ -213,7 +213,7 @@ expand_file_name(char *dest, char *src, 
 
 copy:
 	*dp++ = c;
-	parse = isspace(c);
+	parse = ISSPACE(c);
 	continue;
 
 no_parse:
