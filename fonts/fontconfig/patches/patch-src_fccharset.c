$NetBSD: patch-src_fccharset.c,v 1.2 2022/04/04 12:47:47 riastradh Exp $

- Fix build on SCO OpenServer 5.0.7/3.2.
- Fix ctype(3) abuse.

--- src/fccharset.c.orig	2018-06-05 10:36:38.000000000 +0000
+++ src/fccharset.c
@@ -600,7 +600,7 @@ FcCharSetHasChar (const FcCharSet *fcs, 
 static FcChar32
 FcCharSetPopCount (FcChar32 c1)
 {
-#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
+#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)) && !defined(_SCO_DS)
     return __builtin_popcount (c1);
 #else
     /* hackmem 169 */
@@ -838,14 +838,14 @@ FcNameParseRange (FcChar8 **string, FcCh
 	char *t;
 	long first, last;
 
-	while (isspace(*s))
+	while (isspace((unsigned char)*s))
 	    s++;
 	t = s;
 	errno = 0;
 	first = last = strtol (s, &s, 16);
 	if (errno)
 	    return FcFalse;
-	while (isspace(*s))
+	while (isspace((unsigned char)*s))
 	    s++;
 	if (*s == '-')
 	{
