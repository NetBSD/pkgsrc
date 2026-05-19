$NetBSD: patch-pack__subject.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- pack_subject.c.orig	2026-05-16 21:28:51.824808400 +0000
+++ pack_subject.c
@@ -8,7 +8,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 
@@ -23,7 +23,7 @@ pack_subject(register char *dest, regist
 	max_dest = dest + max_length;
 
 	while (*src) {
-	    if (isspace(*src)) {
+	    if (ISSPACE(*src)) {
 		src++;
 		continue;
 	    }
@@ -49,7 +49,7 @@ pack_subject(register char *dest, regist
 	    src++;
 	    dest = start_dest;
 
-	    while (isdigit(*src))
+	    while (ISDIGIT(*src))
 		*dest++ = *src++;
 	    if (dest == start_dest)
 		re++;
@@ -65,10 +65,10 @@ pack_subject(register char *dest, regist
 	while (*src && dest < max_dest) {
 	    if (*src == '-' && strncmp("- (nf)", src, 5) == 0)
 		break;
-	    if (isascii(*src) && isspace(*src)) {
+	    if (ISASCII(*src) && ISSPACE(*src)) {
 		do
 		    src++;
-		while (isascii(*src) && isspace(*src));
+		while (ISASCII(*src) && ISSPACE(*src));
 		*dest++ = SP;
 	    } else
 		*dest++ = *src++;
