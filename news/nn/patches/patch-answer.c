$NetBSD: patch-answer.c,v 1.1 2026/05/19 18:38:10 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- answer.c.orig	2026-05-16 21:17:38.119293934 +0000
+++ answer.c
@@ -8,7 +8,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "answer.h"
@@ -203,10 +203,10 @@ ref_line(FILE * t)
 	putc(' ', t);
 	pos++;
 	/* Skip leading white space. */
-	while (*p && isascii(*p) && isspace(*p))
+	while (*p && ISASCII(*p) && ISSPACE(*p))
 	    p++;
 	/* Output through next white space. */
-	while (*p && !(isascii(*p) && isspace(*p))) {
+	while (*p && !(ISASCII(*p) && ISSPACE(*p))) {
 	    putc(*p++, t);
 	    pos++;
 	}
