$NetBSD: patch-tools_trietool.c,v 1.1 2020/07/30 01:56:16 scole Exp $

Use unsigned-char cast with isspace

--- tools/trietool.c.orig	2018-06-06 08:39:34.000000000 +0000
+++ tools/trietool.c
@@ -614,12 +614,12 @@ string_trim (char *s)
     char   *p;
 
     /* skip leading white spaces */
-    while (*s && isspace (*s))
+    while (*s && isspace ((unsigned char)*s))
         ++s;
 
     /* trim trailing white spaces */
     p = s + strlen (s) - 1;
-    while (isspace (*p))
+    while (isspace ((unsigned char)*p))
         --p;
     *++p = '\0';
 
