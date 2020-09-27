$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-utils.c,v 1.2 2020/09/27 01:13:11 manu Exp $

fix NULL pointer reference
From upstream https://review.gluster.org/24726

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
