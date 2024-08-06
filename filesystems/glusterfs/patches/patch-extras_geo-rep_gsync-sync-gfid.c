$NetBSD: patch-extras_geo-rep_gsync-sync-gfid.c,v 1.1 2024/08/06 18:54:02 riastradh Exp $

Avoid ctype(3) abuse.

--- extras/geo-rep/gsync-sync-gfid.c.orig	2023-04-06 09:01:24.705967342 +0000
+++ extras/geo-rep/gsync-sync-gfid.c
@@ -63,7 +63,7 @@ main(int argc, char *argv[])
 
         path += UUID_CANONICAL_FORM_LEN + 1;
 
-        while (isspace(*path))
+        while (isspace((unsigned char)*path))
             path++;
 
         len = strlen(line);
