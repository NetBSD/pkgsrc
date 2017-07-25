$NetBSD: patch-hgfastimport_____init____.py,v 1.1 2017/07/25 16:12:56 joerg Exp $

--- hgfastimport/__init__.py.orig	2017-02-12 01:21:40.000000000 +0000
+++ hgfastimport/__init__.py
@@ -27,7 +27,11 @@ testedwith = '4.1'
 @command("fastimport",
          [('', 'branchsort', None, _('try to sort changesets by branches')),
           ('', 'datesort', None, _('try to sort changesets by date')),
-          ('', 'sourcesort', None, _('preserve source changesets order'))],
+          ('', 'sourcesort', None, _('preserve source changesets order')),
+          ('', 'compress', False, _('compress temporary blob files')),
+          ('', 'blob-tree', '', _('path for the blob file tree, defaults to .hg/blobs')),
+          ('', 'blob-tree-depth', 2, _('depth of the blob file tree')),
+          ('', 'fallback-message-encoding', '', _('encoding to try for non-UTF-8 messages'))],
          _('hg fastimport SOURCE ...'),
          norepo=False)
 def fastimport(ui, repo, *sources, **opts):
@@ -56,7 +60,7 @@ def fastimport(ui, repo, *sources, **opt
 
     # sink is the current repo, src is the list of fastimport streams
     destc = hg.mercurial_sink(ui, repo.root)
-    srcc = fastimport_source(ui, repo, sources)
+    srcc = fastimport_source(ui, repo, sources, opts['fallback_message_encoding'], opts['compress'], opts['blob_tree_depth'], opts['blob_tree'])
 
     # XXX figuring out sortmode copied straight from hgext/convert/convcmd.py
     defaultsort = 'branchsort'          # for efficiency and consistency
