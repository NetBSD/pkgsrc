$NetBSD: patch-geo-replication_src_procdiggy.c,v 1.2 2024/08/06 21:10:48 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- geo-replication/src/procdiggy.c.orig	2020-09-16 18:40:32.222503569 +0000
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
