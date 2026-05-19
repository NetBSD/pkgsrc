$NetBSD: patch-reroute.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- reroute.c.orig	2026-05-16 21:29:09.369380690 +0000
+++ reroute.c
@@ -6,7 +6,7 @@
  */
 
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 
@@ -22,14 +22,14 @@ reroute(char *route, char *address)
 	name = atpos;
 
 	while (--name >= address)
-	    if (isspace(*name) || *name == '<') {
+	    if (ISSPACE(*name) || *name == '<') {
 		name++;
 		break;
 	    }
 	if (name < address)
 	    name++;
 
-	for (sp = atpos; (c = *sp); sp++)
+	for (sp = atpos; (c = (unsigned char)(*sp)); sp++)
 	    if (isspace(c) || c == '>')
 		break;
 
