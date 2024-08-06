$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-utils.c,v 1.2 2024/08/06 18:54:03 riastradh Exp $

fix NULL pointer reference
From upstream https://review.gluster.org/24726

Avoid ctype(3) abuse.

--- ./xlators/mgmt/glusterd/src/glusterd-utils.c.orig	2020-07-10 02:53:59.416898136 +0200
+++ ./xlators/mgmt/glusterd/src/glusterd-utils.c	2020-07-10 02:54:16.956178597 +0200
@@ -6394,9 +6394,10 @@
             }
         }
     }
 out:
-    sys_closedir(dirp);
+    if (dirp)
+      sys_closedir(dirp);
     return brick_path;
 }
 
 int
@@ -7177,7 +7178,7 @@ glusterd_parse_inode_size(char *stream, 
     needle = nwstrtail(needle, pattern);
 
     trail = needle;
-    while (trail && isdigit(*trail))
+    while (trail && isdigit((unsigned char)*trail))
         trail++;
     if (trail)
         *trail = '\0';
