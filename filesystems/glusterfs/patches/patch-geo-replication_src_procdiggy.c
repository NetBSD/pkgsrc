$NetBSD: patch-geo-replication_src_procdiggy.c,v 1.1 2024/08/06 18:54:02 riastradh Exp $

Avoid ctype(3) abuse.

--- geo-replication/src/procdiggy.c.orig	2023-04-06 09:01:24.722967396 +0000
+++ geo-replication/src/procdiggy.c
@@ -55,7 +55,7 @@ pidinfo(pid_t pid, char **name)
         if (name && !*name) {
             p = strtail(buf, "Name:");
             if (p) {
-                while (isspace(*++p))
+                while (isspace((unsigned char)*++p))
                     ;
                 *name = gf_strdup(p);
                 if (!*name) {
@@ -71,7 +71,7 @@ pidinfo(pid_t pid, char **name)
             break;
     }
 
-    while (isspace(*++p))
+    while (isspace((unsigned char)*++p))
         ;
     ret = gf_string2int(p, &lpid);
     if (ret == -1)
