$NetBSD: patch-mercurial_bundle2.py,v 1.3 2024/06/20 23:56:45 joerg Exp $

Upstream f28c52a9f7b4

--- mercurial/bundle2.py.orig	2024-03-29 20:37:05.000000000 +0000
+++ mercurial/bundle2.py
@@ -1787,7 +1787,7 @@ def _addpartsfromopts(ui, repo, bundler,
         addpartrevbranchcache(repo, bundler, outgoing)
 
     if opts.get(b'obsolescence', False):
-        obsmarkers = repo.obsstore.relevantmarkers(outgoing.missing)
+        obsmarkers = repo.obsstore.relevantmarkers(nodes=outgoing.missing)
         buildobsmarkerspart(
             bundler,
             obsmarkers,
