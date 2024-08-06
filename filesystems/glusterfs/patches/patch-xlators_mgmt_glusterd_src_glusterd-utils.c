$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-utils.c,v 1.4 2024/08/06 18:54:02 riastradh Exp $

Avoid ctype(3) abuse.

--- xlators/mgmt/glusterd/src/glusterd-utils.c.orig	2023-04-06 09:01:25.033968393 +0000
+++ xlators/mgmt/glusterd/src/glusterd-utils.c
@@ -7461,7 +7461,7 @@ glusterd_parse_inode_size(char *stream, 
     needle = nwstrtail(needle, pattern);
 
     trail = needle;
-    while (trail && isdigit(*trail))
+    while (trail && isdigit((unsigned char)*trail))
         trail++;
     if (trail)
         *trail = '\0';
