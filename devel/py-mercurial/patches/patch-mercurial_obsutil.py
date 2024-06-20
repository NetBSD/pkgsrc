$NetBSD: patch-mercurial_obsutil.py,v 1.1 2024/06/20 23:56:45 joerg Exp $

Upstream f28c52a9f7b4

--- mercurial/obsutil.py.orig	2024-03-29 20:37:05.000000000 +0000
+++ mercurial/obsutil.py
@@ -108,7 +108,7 @@ def getmarkers(repo, nodes=None, exclusi
     elif exclusive:
         rawmarkers = exclusivemarkers(repo, nodes)
     else:
-        rawmarkers = repo.obsstore.relevantmarkers(nodes)
+        rawmarkers = repo.obsstore.relevantmarkers(nodes=nodes)
 
     for markerdata in rawmarkers:
         yield marker(repo, markerdata)
