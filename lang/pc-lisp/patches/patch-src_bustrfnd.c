$NetBSD: patch-src_bustrfnd.c,v 1.1 2018/02/03 20:26:31 kamil Exp $

Port to NetBSD.

--- src/bustrfnd.c.orig	2015-07-22 00:49:58.000000000 +0000
+++ src/bustrfnd.c
@@ -4,7 +4,7 @@
  */
 #include <stdio.h>
 #include "lisp.h"
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 #include <regex.h>
 #endif
 
@@ -14,7 +14,7 @@
  |  because SYSV only handles a static pattern of its own hence we must be
  |  compatible with the minimum system.
  */
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 static regex_t pattern;
 static int reUsed = 0;
 #else
@@ -70,7 +70,7 @@ struct conscell *bustrsetpat(form)
              *p++ = '$'; *p = '\0';              /* match end of string '$' */
          } else
              strcpy(expr, s);
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 	 if (reUsed)
              regfree(&pattern);
 	 if (!regcomp(&pattern, expr, 0))  return(LIST(thold));
@@ -102,7 +102,7 @@ struct conscell *bustrfndpat(form)
    char *s;
    if ((form != NULL)&&(form->cdrp == NULL)) {
       if (GetString(form->carp, &s)) {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 	return( regexec(&pattern, s, 0, NULL, 0) ? NULL : LIST(thold) );
 #else
 #        if RE_COMP
@@ -119,4 +119,3 @@ struct conscell *bustrfndpat(form)
    ierror("strfndpat");  /*  doesn't return  */
    return NULL;   /*  keep compiler happy  */
 }
-
