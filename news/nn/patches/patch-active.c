$NetBSD: patch-active.c,v 1.1 2026/05/19 18:38:10 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- active.c.orig	2026-05-16 21:13:32.444810676 +0000
+++ active.c
@@ -7,7 +7,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "active.h"
@@ -36,7 +36,7 @@ read_active_file(FILE * act, FILE * copy
 	must_update = 0;
 
 	cp = line;
-	while (*cp && isspace(*cp))
+	while (*cp && ISSPACE(*cp))
 	    cp++;		/* eat blank lines */
 	if (*cp == NUL || *cp == '#')
 	    continue;
@@ -55,13 +55,13 @@ read_active_file(FILE * act, FILE * copy
 		continue;
 	    must_update = 1;
 	}
-	while (*cp && isspace(*cp))
+	while (*cp && ISSPACE(*cp))
 	    cp++;
 	gh->last_a_article = atol(cp);
 
-	while (*cp && isdigit(*cp))
+	while (*cp && ISDIGIT(*cp))
 	    cp++;
-	while (*cp && isspace(*cp))
+	while (*cp && ISSPACE(*cp))
 	    cp++;
 
 	if (*cp == NUL) {
@@ -71,9 +71,9 @@ read_active_file(FILE * act, FILE * copy
 	gh->first_a_article = atol(cp);
 	if (gh->first_a_article == 0)
 	    gh->first_a_article = 1;
-	while (*cp && isdigit(*cp))
+	while (*cp && ISDIGIT(*cp))
 	    cp++;
-	while (*cp && isspace(*cp))
+	while (*cp && ISSPACE(*cp))
 	    cp++;
 
 	gh->master_flag |= M_VALID;
@@ -111,10 +111,10 @@ read_active_file(FILE * act, FILE * copy
 		break;
 
 	    case '=':
-		while (*++cp && isspace(*cp))
+		while (*++cp && ISSPACE(*cp))
 		    cp++;
 		name = cp;
-		while (*cp && !isspace(*cp))
+		while (*cp && !ISSPACE(*cp))
 		    cp++;
 		*cp = NUL;
 		if (old_flag & M_ALIASED) {
