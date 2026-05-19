$NetBSD: patch-menu.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- menu.c.orig	2026-05-16 21:27:55.837783975 +0000
+++ menu.c
@@ -6,7 +6,7 @@
  */
 
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "articles.h"
@@ -1025,12 +1025,12 @@ get_purpose(char *purpose)
     len = current_group->group_name_length;
 
     while (fgets(line, 256, f) != NULL) {
-	if (!isascii(line[len]) || !isspace(line[len]))
+	if (!ISASCII(line[len]) || !ISSPACE(line[len]))
 	    continue;
 	if (strncmp(line, group, len))
 	    continue;
 	cp = line + len;
-	while (*cp && isspace(*cp))
+	while (*cp && ISSPACE(*cp))
 	    cp++;
 	for (pp = purpose, len = 76; --len >= 0 && *cp && *cp != NL;)
 	    *pp++ = *cp++;
