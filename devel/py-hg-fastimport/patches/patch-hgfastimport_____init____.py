$NetBSD: patch-hgfastimport_____init____.py,v 1.2 2021/01/09 15:30:03 roy Exp $

--- hgfastimport/__init__.py.orig	2017-02-12 01:21:40.000000000 +0000
+++ hgfastimport/__init__.py
@@ -4,7 +4,7 @@ from __future__ import absolute_import
 from mercurial import (
     encoding,
     util,
-    cmdutil,
+    commands,
 )
 
 from mercurial.i18n import _
@@ -19,7 +19,7 @@ from .hgimport import fastimport_source
 
 # XXX sort options copied straight from hgext/convert/__init__.py
 cmdtable = {}
-command = cmdutil.command(cmdtable)
+command = commands.command
 
 testedwith = '4.1'
 
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
@@ -55,8 +59,8 @@ def fastimport(ui, repo, *sources, **opt
     encoding.encoding = 'UTF-8'
 
     # sink is the current repo, src is the list of fastimport streams
-    destc = hg.mercurial_sink(ui, repo.root)
-    srcc = fastimport_source(ui, repo, sources)
+    destc = hg.mercurial_sink(ui, 'hg', repo.root)
+    srcc = fastimport_source(ui, repo, sources, opts['fallback_message_encoding'], opts['compress'], opts['blob_tree_depth'], opts['blob_tree'])
 
     # XXX figuring out sortmode copied straight from hgext/convert/convcmd.py
     defaultsort = 'branchsort'          # for efficiency and consistency
