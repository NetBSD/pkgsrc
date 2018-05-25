$NetBSD: patch-mercurial_bundle2.py,v 1.1 2018/05/25 13:04:56 joerg Exp $

Merge 326b174c6a47 from upstream:
bundle2: mark the bundle2 part as advisory (issue5872)

--- mercurial/bundle2.py.orig	2018-05-05 23:02:57.000000000 +0000
+++ mercurial/bundle2.py
@@ -1659,7 +1659,8 @@ def addpartrevbranchcache(repo, bundler,
             for n in sorted(closed):
                 yield n
 
-    bundler.newpart('cache:rev-branch-cache', data=generate())
+    bundler.newpart('cache:rev-branch-cache', data=generate(),
+                    mandatory=False)
 
 def _formatrequirementsspec(requirements):
     return urlreq.quote(','.join(sorted(requirements)))
