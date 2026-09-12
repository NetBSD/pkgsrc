$NetBSD: patch-autoopts_usage.c,v 1.1 2026/09/12 12:14:40 wiz Exp $

Bound the option name length used to build the vendor option format.

Upstream 58504a36, which has not appeared in a release.

--- autoopts/usage.c.orig	2018-08-25 00:00:00.000000000 +0000
+++ autoopts/usage.c
@@ -732,7 +732,8 @@
                 continue;
 
             l = strlen(od->pz_Name);
-            if (l > nmlen)  nmlen = l;
+            if ((l <= AO_NAME_LIMIT) && (l > nmlen))
+                nmlen = l;
         } while (od++, (--ct > 0));
 
         snprintf(vfmt, sizeof(vfmt), vfmtfmt, (unsigned int)nmlen + 4);
