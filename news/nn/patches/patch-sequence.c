$NetBSD: patch-sequence.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- sequence.c.orig	2026-05-16 21:29:16.870728911 +0000
+++ sequence.c
@@ -7,7 +7,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "db.h"
@@ -620,7 +620,7 @@ start_group_search(char *group)
 
 	if (group[2] != ':')
 	    return;
-	if (isdigit(group[3]))
+	if (ISDIGIT(group[3]))
 	    gs_index = atoi(group + 3);
 	else {
 	    gs_group = group + 3;
