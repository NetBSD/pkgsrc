$NetBSD: patch-strrstr.c,v 1.2 2012/12/23 18:43:47 dholland Exp $

- use standard headers
- use c89 preprocessor syntax
- silence gcc warning about unused variable

--- strrstr.c.orig	1993-10-29 21:10:48.000000000 +0000
+++ strrstr.c
@@ -1,10 +1,11 @@
+#include <string.h>
 /* Strrstr.c, included for those computers that do not have it. */
 /* Written by Kent Irwin, irwin@leland.stanford.edu.  I am
    responsible for bugs */
 #ifdef STRRSTR_MISSING
 #ifndef NULL
 #define NULL    0
-#endif NULL
+#endif
 #ifdef ANSI
 char *strrstr(char *s1,char *s2) {
 #else
@@ -14,7 +15,7 @@ char *s2;
 {
 #endif
 
-	char *sc1, *sc2, *psc1, *ps1;
+	char *sc2, *psc1, *ps1;
 
 	if (*s2 == '\0')
 		return((char *)s1);
