$NetBSD: patch-bcmfw-install.c,v 1.1 2016/02/24 21:43:39 plunky Exp $

use %zu for size_t

--- bcmfw-install.c.orig	2016-02-24 21:39:09.000000000 +0000
+++ bcmfw-install.c
@@ -194,9 +194,9 @@ start:
 				}
 			}
 			if (quote)
-				warnx("unterminated quote on line #%d", lineno);
+				warnx("unterminated quote on line #%zu", lineno);
 			if (stringkey)
-				warnx("unterminated string key on line #%d", lineno);
+				warnx("unterminated string key on line #%zu", lineno);
 			if (space)
 				len = space;	/* drop trailing spaces */
 			if (ch == EOF) {
@@ -216,7 +216,7 @@ start:
 				if (buf[len - 1] == ']')
 					section = section_add(buf + 1, len - 2);
 				else {
-					warnx("malformed section header on line #%d", lineno);
+					warnx("malformed section header on line #%zu", lineno);
 					section = NULL;
 				}
 			} else if (section != NULL) /* ignore lines with no section */
@@ -257,7 +257,7 @@ start:
 		buf[len++] = (uint8_t)ch;
 	}
 
-	err(EXIT_FAILURE, "line #%d too long", lineno);
+	err(EXIT_FAILURE, "line #%zu too long", lineno);
 }
 
 static bool
