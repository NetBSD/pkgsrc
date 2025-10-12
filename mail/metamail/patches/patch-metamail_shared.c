$NetBSD: patch-metamail_shared.c,v 1.2 2025/10/12 00:57:39 mrg Exp $

- use standard headers
- don't provide own declarations of standard functions
- don't cast the return value of malloc
- add types for GCC 14.

--- metamail/shared.c.orig	1993-05-16 11:19:32.000000000 -0700
+++ metamail/shared.c	2025-10-11 16:52:18.287181298 -0700
@@ -1,16 +1,20 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <config.h>
-#ifdef SYSV
 #include <unistd.h>
+#ifdef SYSV
 #include <sys/utsname.h>
 #endif
 
-extern char *malloc();
+#include "metamail.h"
+
 char **Exceptions;
 int *NeedsPortableNewlines;
 int ExceptionsAlloced = 0, ExceptionsUsed = 0;
 
+int
 ExceptionalNewline(contenttype, needsportable)
 char *contenttype;
 int needsportable;
@@ -18,14 +22,14 @@ int needsportable;
     char *s;
     if (ExceptionsAlloced == 0) {
         ExceptionsAlloced = 25;
-        Exceptions = (char **) malloc(ExceptionsAlloced * sizeof(char *));
-        NeedsPortableNewlines = (int *) malloc(ExceptionsAlloced * sizeof(int));
+        Exceptions = malloc(ExceptionsAlloced * sizeof(char *));
+        NeedsPortableNewlines = malloc(ExceptionsAlloced * sizeof(int));
         if (!Exceptions || !NeedsPortableNewlines) return(-1);
     }
     if (ExceptionsUsed >= ExceptionsAlloced) {
         ExceptionsAlloced += 25;
-        Exceptions = (char **) realloc(Exceptions, ExceptionsAlloced * sizeof(char *));
-        NeedsPortableNewlines = (int *) realloc(NeedsPortableNewlines, ExceptionsAlloced * sizeof(int));
+        Exceptions = realloc(Exceptions, ExceptionsAlloced * sizeof(char *));
+        NeedsPortableNewlines = realloc(NeedsPortableNewlines, ExceptionsAlloced * sizeof(int));
         if (!Exceptions || !NeedsPortableNewlines) return(-1);
     }
     s = malloc(1+strlen(contenttype));
@@ -40,6 +44,7 @@ int needsportable;
     return(0);
 }
 
+int
 DoesNeedPortableNewlines(ctype)
 char *ctype;
 {
@@ -65,6 +70,7 @@ char *ctype;
     return(0);
 }
 
+int
 lc2strncmp(s1, s2, len)
 char *s1, *s2;
 int len;
@@ -78,6 +84,7 @@ int len;
     return((*s1 == *s2) ? 0 : -1);
 }
 
+int
 lc2strcmp(s1, s2)
 char *s1, *s2;
 {
