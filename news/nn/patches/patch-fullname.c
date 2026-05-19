$NetBSD: patch-fullname.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- fullname.c.orig	2026-05-16 21:26:57.561921842 +0000
+++ fullname.c
@@ -32,7 +32,7 @@ static char    *SccsId = "@(#)fullname.c
 #include <stdlib.h>
 #include <pwd.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 
@@ -70,13 +70,13 @@ buildfname(register char *p, char *login
     if (*p == '*')
 	p++;
     while (*p != '\0' && *p != ',' && *p != ';' && *p != ':' && *p != '(') {
-	if (*p == '-' && (isdigit(p[-1]) || isspace(p[-1]))) {
+	if (*p == '-' && (ISDIGIT(p[-1]) || ISSPACE(p[-1]))) {
 	    bp = buf;
 	    p++;
 	} else if (*p == '&') {
 	    strcpy(bp, login);
-	    if ((bp == buf || !isalpha(bp[-1])) && islower(*bp))
-		*bp = toupper(*bp);
+	    if ((bp == buf || !ISALPHA(bp[-1])) && ISLOWER(*bp))
+		*bp = TOUPPER(*bp);
 	    while (*bp != '\0')
 		bp++;
 	    p++;
