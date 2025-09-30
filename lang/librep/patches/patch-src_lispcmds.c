$NetBSD: patch-src_lispcmds.c,v 1.1 2025/09/30 14:29:17 gutteridge Exp $

Use ctype.h correctly.

--- src/lispcmds.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ src/lispcmds.c
@@ -1611,7 +1611,7 @@ Returns t if STRING1 and STRING2 are the
     s2 = rep_STR(str2);
     while(*s1 && *s2)
     {
-	if (toupper (*s1) != toupper (*s2))
+	if (toupper ((unsigned char)*s1) != toupper ((unsigned char)*s2))
 	    return Qnil;
 	s1++; s2++;
     }
@@ -1632,8 +1632,8 @@ Returns t if STRING1 is `less' than STRI
     s2 = rep_STR(str2);
     while(*s1 && *s2)
     {
-	if (toupper (*s1) != toupper (*s2))
-	    return (toupper (*s1) < toupper (*s2)) ? Qt : Qnil;
+	if (toupper ((unsigned char)*s1) != toupper ((unsigned char)*s2))
+	    return (toupper ((unsigned char)*s1) < toupper ((unsigned char)*s2)) ? Qt : Qnil;
 	s1++; s2++;
     }
     return *s2 ? Qt : Qnil;
