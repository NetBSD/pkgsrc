$NetBSD: patch-mercurial_exchange.py,v 1.1 2024/06/20 23:56:45 joerg Exp $

Upstream f28c52a9f7b4
https://foss.heptapod.net/mercurial/mercurial-devel/-/merge_requests/863

--- mercurial/exchange.py.orig	2024-03-29 20:37:05.000000000 +0000
+++ mercurial/exchange.py
@@ -668,8 +668,8 @@ def _pushdiscoveryobsmarkers(pushop):
     repo = pushop.repo
     # very naive computation, that can be quite expensive on big repo.
     # However: evolution is currently slow on them anyway.
-    nodes = (c.node() for c in repo.set(b'::%ln', pushop.futureheads))
-    pushop.outobsmarkers = pushop.repo.obsstore.relevantmarkers(nodes)
+    revs = repo.revs(b'::%ln', pushop.futureheads)
+    pushop.outobsmarkers = pushop.repo.obsstore.relevantmarkers(revs=revs)
 
 
 @pushdiscovery(b'bookmarks')
@@ -2542,10 +2542,15 @@ def _getbundleobsmarkerpart(
 ):
     """add an obsolescence markers part to the requested bundle"""
     if kwargs.get('obsmarkers', False):
+        unfi_cl = repo.unfiltered().changelog
         if heads is None:
-            heads = repo.heads()
-        subset = [c.node() for c in repo.set(b'::%ln', heads)]
-        markers = repo.obsstore.relevantmarkers(subset)
+            headrevs = repo.changelog.headrevs()
+        else:
+            get_rev = unfi_cl.index.get_rev
+            headrevs = [get_rev(node) for node in heads]
+            headrevs = [rev for rev in headrevs if rev is not None]
+        revs = set(unfi_cl.ancestors(headrevs, inclusive=True))
+        markers = repo.obsstore.relevantmarkers(revs=revs)
         markers = obsutil.sortedmarkers(markers)
         bundle2.buildobsmarkerspart(bundler, markers)
 
