$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-utils.c,v 1.5 2024/08/06 21:10:48 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

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
