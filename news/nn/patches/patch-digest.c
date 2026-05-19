$NetBSD: patch-digest.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- digest.c.orig	2026-05-16 21:26:10.444484589 +0000
+++ digest.c
@@ -12,7 +12,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <strings.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "debug.h"
@@ -127,12 +127,12 @@ is_mail_from_line(char *line, char *name
     lp = line + 5;
     /* sender day mon dd hh:mm:ss year */
     for (n = 0, fp = fields; n < MAX_FIELDS; n++) {
-	while (*lp && *lp != NL && isascii(*lp) && isspace(*lp))
+	while (*lp && *lp != NL && ISASCII(*lp) && ISSPACE(*lp))
 	    lp++;
 	if (*lp == NUL || *lp == NL)
 	    break;
 	*fp++ = lp;
-	while (*lp && isascii(*lp) && !isspace(*lp))
+	while (*lp && ISASCII(*lp) && !ISSPACE(*lp))
 	    if (*lp++ == ':' && (n == 4 || n == 5))
 		break;
 	if (n == 0)
@@ -144,9 +144,9 @@ is_mail_from_line(char *line, char *name
 
     fp = fields;
 
-    if (n > 8 && !isdigit(fp[7][0]))
+    if (n > 8 && !ISDIGIT(fp[7][0]))
 	fp[7] = fp[8];		/* ... TZ year */
-    if (n > 9 && !isdigit(fp[7][0]))
+    if (n > 9 && !ISDIGIT(fp[7][0]))
 	fp[7] = fp[9];		/* ... TZ DST year */
 
     if (namebuf != NULL) {
@@ -174,7 +174,7 @@ is_mail_from_line(char *line, char *name
 
     for (i = 0; i < 10; i += 2) {
 	lp = *++fp;
-	if (!isdigit(*lp))
+	if (!ISDIGIT(*lp))
 	    return -20 - i;
 	n = atoi(lp);
 	if (n < legal_numbers[i] || legal_numbers[i + 1] < n)
@@ -368,7 +368,7 @@ next_possible_header_line:
 	--digest.dg_lines;
 	return (digest.dg_lines <= 0) ? -1 : 1;
     }
-    for (cp = line; *cp && isascii(*cp) && isspace(*cp); cp++);
+    for (cp = line; *cp && ISASCII(*cp) && ISSPACE(*cp); cp++);
 
     if (*cp == NUL) {
 	TEST0("BLANK");
@@ -393,7 +393,7 @@ next_possible_header_line:
 	while (*cp == '-')
 	    cp++;
 	if (cp - line - blanks > MIN_DASHES) {
-	    while (*cp && (*cp == '-' || (isascii(*cp) && isspace(*cp))))
+	    while (*cp && (*cp == '-' || (ISASCII(*cp) && ISSPACE(*cp))))
 		cp++;
 	    if (*cp == NUL) {
 		TEST0("DASHED");
@@ -410,7 +410,7 @@ next_possible_header_line:
 	while (*cp == '*')
 	    cp++;
 	if (cp - line - blanks > MIN_ASTERISKS) {
-	    while (*cp && (*cp == '*' || (isascii(*cp) && isspace(*cp))))
+	    while (*cp && (*cp == '*' || (ISASCII(*cp) && ISSPACE(*cp))))
 		cp++;
 	    if (*cp == NUL) {
 		TEST0("ASTERISK");
@@ -437,7 +437,7 @@ next_possible_header_line:
 	char           *colon;
 	if ((colon = strchr(line, ':'))) {
 	    for (cp = line; cp < colon; cp++)
-		if (!isascii(*cp) || isspace(*cp))
+		if (!ISASCII(*cp) || ISSPACE(*cp))
 		    break;
 	    if (cp == colon) {
 		TEST0("COLON");
@@ -514,7 +514,7 @@ dg_hdr_field(register char *lp, int all)
     static char     namebuf[33];
 
 #define check(name, lgt, field) \
-    if (isascii(lp[lgt]) && isspace(lp[lgt]) \
+    if (ISASCII(lp[lgt]) && ISSPACE(lp[lgt]) \
 	&& strncasecmp(name, lp, lgt) == 0) {\
 	TEST0("MATCH: " #field " "); \
 	return &digest.field; \
