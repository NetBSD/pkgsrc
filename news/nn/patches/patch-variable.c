$NetBSD: patch-variable.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- variable.c.orig	2026-05-16 21:29:40.872840811 +0000
+++ variable.c
@@ -7,7 +7,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "chset.h"
@@ -475,9 +475,9 @@ adjust(register char *str)
 	    *str++ = escaped_char(*s++);
 	} else if (str == s) {
 	    str++;
-	    if (isspace(*s++))
+	    if (ISSPACE(*s++))
 		continue;
-	} else if (isspace(*str++ = *s++))
+	} else if (ISSPACE(*str++ = *s++))
 	    continue;
 	t = str;
     }
@@ -693,12 +693,12 @@ set_variable(char *variable, int on, cha
 		    sp = codes;
 		    vs = val_string;
 		    while (*vs) {
-			while (*vs && (!isascii(*vs) || isspace(*vs)))
+			while (*vs && (!ISASCII(*vs) || ISSPACE(*vs)))
 			    vs++;
 			if (*vs == NUL)
 			    break;
 			cp = code;
-			while (*vs && isascii(*vs) && !isspace(*vs))
+			while (*vs && ISASCII(*vs) && !ISSPACE(*vs))
 			    *cp++ = *vs++;
 			*cp = NUL;
 			*sp++ = parse_key(code);
@@ -864,7 +864,7 @@ var_completion(char *path, int index)
     if (path) {
 	head = path;
 	tail = path + index;
-	while (*head && isspace(*head))
+	while (*head && ISSPACE(*head))
 	    head++;
 	if (strncmp(head, "no", 2) == 0) {
 	    head += 2;
@@ -1175,9 +1175,9 @@ var_options(char **str, register char *o
     options = *str;
     while (*options) {
 	for (wp = word; (c = *options) != NUL; *wp++ = c, options++)
-	    if (isascii(c) && isspace(c))
+	    if (ISASCII(c) && ISSPACE(c))
 		break;
-	while (((c = *options)) && isascii(c) && isspace(c))
+	while (((c = *options)) && ISASCII(c) && ISSPACE(c))
 	    options++;
 	*wp = NUL;
 
