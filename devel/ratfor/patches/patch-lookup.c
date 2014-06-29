$NetBSD: patch-lookup.c,v 1.2 2014/06/29 06:32:02 dholland Exp $

Use standard headers.
Don't declare own malloc.

--- lookup.c.orig	1999-02-14 02:05:24.000000000 +0000
+++ lookup.c
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "lookup.h"
 
 static
@@ -48,10 +50,10 @@ S_CHAR *def;
 {
 	int hashval;
 	struct hashlist *np, *lookup();
-	S_CHAR *strsave(), *malloc();
+	S_CHAR *strsave();
 
 	if ((np = lookup(name)) == NULL) {	/* not found.. */
-		np = (struct hashlist *) malloc(sizeof(*np));
+		np = malloc(sizeof(*np));
 		if (np == NULL)
 			return(NULL);
 		if ((np->name = strsave(name)) == NULL)
@@ -74,7 +76,7 @@ S_CHAR
 *strsave(s)
 S_CHAR *s;
 {
-	S_CHAR *p, *malloc();
+	S_CHAR *p;
 
 	if ((p = malloc(strlen(s)+1)) != NULL)
 		strcpy(p, s);
