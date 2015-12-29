$NetBSD: patch-wrksp.c,v 1.3 2015/12/29 23:34:56 dholland Exp $

Use standard headers.
Use <ctype.h> correctly.
Use snprintf.
Pass the right type for printf %.* lengths.

--- wrksp.c.orig	2008-08-23 19:51:14.000000000 +0000
+++ wrksp.c
@@ -38,6 +38,7 @@ int wxEditFile(char *);
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#include <sys/wait.h>
 
 #ifdef ibm
 #include "process.h"
@@ -55,6 +56,8 @@ int wxEditFile(char *);
 #endif
 #endif
 
+#include <ctype.h>
+
 char *editor, *editorname, *tempdir;
 int to_pending = 0;
 
@@ -293,7 +296,7 @@ char *strncasestr(char *big, char *littl
     FIXNUM i;
 
     while (*big != '\0') {
-	while ((pc = *big++) != '\0' && tolower(pc) != tolower(*little)) ;
+	while ((pc = *big++) != '\0' && tolower((unsigned char)pc) != tolower((unsigned char)*little)) ;
 	if (pc == '\0') return NULL;
 	p = big; q = little+1; i = len;
 	while (--i > 0 && (qc = *q++) != '\0') {
@@ -1713,8 +1716,8 @@ NODE *cpdf_newname(NODE *name, NODE*titl
     p1 = titlestr+strcspn(titlestr, " \t");
     p1 = p1+strspn(p1, " \t");
     p2 = p1+strcspn(p1, " \t");
-    sprintf(buf, "%.*s%.*s%s",
-	    p1-titlestr, titlestr, getstrlen(nname), namestr, p2);
+    snprintf(buf, sizeof(buf), "%.*s%.*s%s",
+	    (int)(p1-titlestr), titlestr, (int)getstrlen(nname), namestr, p2);
     return make_strnode(buf, NULL, strlen(buf), STRING, strcpy);
 }
 
