$NetBSD: patch-metamail_shared.c,v 1.1 2012/12/30 05:38:55 dholland Exp $

- use standard headers
- don't provide own declarations of standard functions
- don't cast the return value of malloc

--- metamail/shared.c~	1993-05-16 18:19:32.000000000 +0000
+++ metamail/shared.c
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <config.h>
 #ifdef SYSV
@@ -6,7 +8,6 @@
 #include <sys/utsname.h>
 #endif
 
-extern char *malloc();
 char **Exceptions;
 int *NeedsPortableNewlines;
 int ExceptionsAlloced = 0, ExceptionsUsed = 0;
@@ -18,14 +19,14 @@ int needsportable;
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
