$NetBSD: patch-hgfastimport_hgimport.py,v 1.2 2017/07/25 16:12:56 joerg Exp $

--- hgfastimport/hgimport.py.orig	2017-02-12 01:21:40.000000000 +0000
+++ hgfastimport/hgimport.py
@@ -24,6 +24,12 @@ import os
 import shutil
 import stat
 import sys
+import gzip
+import itertools
+
+def grouper(iterable, n, fillvalue=None):
+    args = [iter(iterable)] * n
+    return itertools.izip_longest(fillvalue=fillvalue, *args)
 
 from hgext.convert import common, hg as converthg
 from mercurial import util
@@ -31,6 +37,8 @@ from mercurial.i18n import _
 
 from fastimport import processor, parser
 
+from hashlib import sha256
+
 # convertor source objects had a getmode() method up to Mercurial 1.5,
 # but in 1.6 it was merged with getfile()
 HAVE_GETMODE = hasattr(converthg.mercurial_source, 'getmode')
@@ -39,11 +47,12 @@ class fastimport_source(common.converter
     """Interface between the fastimport processor below and Mercurial's
     normal conversion infrastructure.
     """
-    def __init__(self, ui, repo, sources):
+    def __init__(self, ui, repo, sources, fallback_message_encoding, compress, blob_tree_depth, blob_tree):
         self.ui = ui
         self.sources = sources
-        self.processor = HgImportProcessor(ui, repo)
+        self.processor = HgImportProcessor(ui, repo, compress, blob_tree_depth, blob_tree)
         self.parsed = False
+        self.fallback_message_encoding = fallback_message_encoding
 
     # converter_source methods
 
@@ -138,7 +147,7 @@ class fastimport_source(common.converter
             else:
                 infile = open(source, 'rb')
             try:
-                p = parser.ImportParser(infile)
+                p = parser.ImportParser(infile, message_fallback_encoding = self.fallback_message_encoding)
                 self.processor.process(p.iter_commands)
             finally:
                 if infile is not sys.stdin:
@@ -150,7 +159,7 @@ class HgImportProcessor(processor.Import
     
     tagprefix = "refs/tags/"
 
-    def __init__(self, ui, repo):
+    def __init__(self, ui, repo, compress, blob_tree_depth, blob_tree):
         super(HgImportProcessor, self).__init__()
         self.ui = ui
         self.repo = repo
@@ -168,6 +177,10 @@ class HgImportProcessor(processor.Import
         self.numblobs = 0               # for progress reporting
         self.blobdir = None
 
+        self.compress = compress
+        self.blob_tree = blob_tree
+        self.blob_tree_depth = blob_tree_depth
+
     def setup(self):
         """Setup before processing any streams."""
         pass
@@ -187,12 +200,24 @@ class HgImportProcessor(processor.Import
     def _getblobfilename(self, blobid):
         if self.blobdir is None:
             raise RuntimeError("no blobs seen, so no blob directory created")
-        # XXX should escape ":" for windows
-        return os.path.join(self.blobdir, "blob-" + blobid)
+        h = sha256(blobid).hexdigest()
+        h_comp = list(grouper(h, 3, ''))
+        if len(h_comp) > self.blob_tree_depth:
+            h_comp = h_comp[:self.blob_tree_depth] + [''.join(list(itertools.chain(*h_comp[self.blob_tree_depth:])))]
+        #self.ui.status("mapping blobid %s to %s\n" % (blobid, h))
+        return os.path.join(self.blobdir, *[''.join(x) for x in h_comp])
 
     def getblob(self, fileid):
         (commitid, blobid) = fileid
-        f = open(self._getblobfilename(blobid), "rb")
+        fn = self._getblobfilename(blobid)
+        try:
+            if self.compress:
+                f = gzip.open(fn, "rb")
+            else:
+                f = open(fn, "rb")
+        except:
+            self.ui.status("missing blob %s for fileid %s\n" % (fn, fileid))
+            raise
         try:
             return f.read()
         finally:
@@ -200,13 +225,23 @@ class HgImportProcessor(processor.Import
 
     def writeblob(self, blobid, data):
         if self.blobdir is None:        # no blobs seen yet
-            self.blobdir = os.path.join(self.repo.root, ".hg", "blobs")
-            os.mkdir(self.blobdir)
+            if self.blob_tree:
+                self.blobdir = self.blob_tree
+            else:
+                self.blobdir = os.path.join(self.repo.root, ".hg", "blobs")
 
         fn = self._getblobfilename(blobid)
-        blobfile = open(fn, "wb")
-        #self.ui.debug("writing blob %s to %s (%d bytes)\n"
+        try:
+            os.makedirs(os.path.dirname(fn))
+        except OSError:
+            pass
+
+        #self.ui.status("writing blob %s to %s (%d bytes)\n"
         #              % (blobid, fn, len(data)))
+        if self.compress:
+            blobfile = gzip.open(fn, "wb", 3)
+        else:
+            blobfile = open(fn, "wb")
         blobfile.write(data)
         blobfile.close()
 
@@ -449,3 +484,7 @@ class HgImportCommitHandler(processor.Co
         # copy oldname to newname and delete oldname
         self.copies[filecmd.new_path] = filecmd.old_path
         self.modified.append((filecmd.old_path, None))
+
+    def deleteall_handler(self, filecmd):
+        # Ignore for now.
+        pass
