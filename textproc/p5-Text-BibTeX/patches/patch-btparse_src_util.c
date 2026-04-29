$NetBSD: patch-btparse_src_util.c,v 1.1 2026/04/29 21:08:25 markd Exp $

Fix ctype(3) usage.

--- ./btparse/src/util.c.orig	2025-01-29 15:47:18.000000000 +0000
+++ ./btparse/src/util.c
@@ -36,7 +36,7 @@ strlwr(char *s)
 
     len = strlen(s);
     for (i = 0; i < len; i++)
-        s[i] = tolower(s[i]);
+        s[i] = tolower((unsigned char)s[i]);
 
     return s;
 }
@@ -61,7 +61,7 @@ strupr(char *s)
 
     len = strlen(s);
     for (i = 0; i < len; i++)
-        s[i] = toupper(s[i]);
+        s[i] = toupper((unsigned char)s[i]);
 
     return s;
 }
