$NetBSD: patch-hgext3rd_evolve_obsexchange.py,v 1.1 2020/06/01 15:48:20 joerg Exp $

--- hgext3rd/evolve/obsexchange.py.orig	2020-06-01 15:45:28.403523975 +0000
+++ hgext3rd/evolve/obsexchange.py
@@ -113,7 +113,7 @@ def _getbundleobsmarkerpart(orig, bundle
             subset += kwargs['evo_missing_nodes']
         markers = repo.obsstore.relevantmarkers(subset)
         if util.safehasattr(bundle2, 'buildobsmarkerspart'):
-            bundle2.buildobsmarkerspart(bundler, markers)
+            bundle2.buildobsmarkerspart(bundler, markers, mandatory = True)
         else:
             exchange.buildobsmarkerspart(bundler, markers)
 
