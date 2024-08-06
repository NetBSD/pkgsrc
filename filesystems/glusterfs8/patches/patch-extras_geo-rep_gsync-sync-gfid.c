$NetBSD: patch-extras_geo-rep_gsync-sync-gfid.c,v 1.1 2024/08/06 18:54:02 riastradh Exp $

Avoid ctype(3) abuse.

--- extras/geo-rep/gsync-sync-gfid.c.orig	2020-09-16 18:40:32.206503559 +0000
+++ extras/geo-rep/gsync-sync-gfid.c
@@ -63,7 +63,7 @@ main(int argc, char *argv[])
 
         path += UUID_CANONICAL_FORM_LEN + 1;
 
-        while (isspace(*path))
+        while (isspace((unsigned char)*path))
             path++;
 
         len = strlen(line);
