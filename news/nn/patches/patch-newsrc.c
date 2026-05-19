$NetBSD: patch-newsrc.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- newsrc.c.orig	2026-05-16 21:28:19.289443231 +0000
+++ newsrc.c
@@ -7,7 +7,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "articles.h"
@@ -326,7 +326,7 @@ get_last_article(group_header * gh)
 	return -1;
 
     line += gh->group_name_length + 1;
-    while (*line && isspace(*line))
+    while (*line && ISSPACE(*line))
 	line++;
     if (*line == NUL)
 	return -1;
@@ -334,7 +334,7 @@ get_last_article(group_header * gh)
     if (line[0] == '1') {
 	if (line[1] == RC_RANGE)
 	    return atol(line + 2);
-	if (!isdigit(line[1]))
+	if (!ISDIGIT(line[1]))
 	    return 1;
     }
     return 0;
@@ -706,7 +706,7 @@ rctest(register article_header * ah, reg
 		    x = 0;
 		    continue;
 		}
-		if (isascii(*p) && isdigit(*p))
+		if (ISASCII(*p) && ISDIGIT(*p))
 		    x = x * 10 + c - '0';
 	    }
 	    r->rc_max = x;
@@ -1663,7 +1663,7 @@ opt_nngoback(int argc, char ***argvp)
 		      " days [groups]...");
 
     if (goback_days < 0) {
-	if (n == 0 || !isdigit((*argvp)[1][0])) {
+	if (n == 0 || !ISDIGIT((*argvp)[1][0])) {
 	    fprintf(stderr, "usage: %s [-NQvi] days [groups]...\n", pname);
 	    nn_exit(1);
 	}
