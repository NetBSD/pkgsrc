$NetBSD: patch-src_loop.c,v 1.1 2023/02/25 03:30:47 riastradh Exp $

Fix ctype(3) misuse.

--- src/loop.c.orig	2023-02-02 20:24:24.000000000 +0000
+++ src/loop.c
@@ -92,7 +92,7 @@ int detect_loop(char *query, int type)
     return 0;
 
   for (i = 0; i < 8; i++)
-    if (!isxdigit(query[i]))
+    if (!isxdigit((unsigned char)query[i]))
       return 0;
 
   uid = strtol(query, NULL, 16);
