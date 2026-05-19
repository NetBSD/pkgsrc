$NetBSD: patch-regexp.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- regexp.c.orig	2026-05-16 21:28:59.660188282 +0000
+++ regexp.c
@@ -33,7 +33,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "regexp.h"
@@ -834,15 +834,15 @@ regmatch(char *prog)
 		    return (0);
 		break;
 	    case W_START:
-		if (*reginput == '\0' || isspace(*reginput))
+		if (*reginput == '\0' || ISSPACE(*reginput))
 		    return (0);
-		if (reginput != regbol && !isspace(*(reginput - 1)))
+		if (reginput != regbol && !ISSPACE(*(reginput - 1)))
 		    return (0);
 		break;
 	    case W_END:
-		if (*reginput != '\0' && !isspace(*reginput))
+		if (*reginput != '\0' && !ISSPACE(*reginput))
 		    return (0);
-		if (reginput == regbol || isspace(*(reginput - 1)))
+		if (reginput == regbol || ISSPACE(*(reginput - 1)))
 		    return (0);
 		break;
 	    case ANY:
