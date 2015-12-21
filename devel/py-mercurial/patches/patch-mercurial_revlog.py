$NetBSD: patch-mercurial_revlog.py,v 1.1 2015/12/21 13:19:17 richard Exp $
https://bz.mercurial-scm.org/show_bug.cgi?id=4943
--- mercurial/revlog.py.orig	2015-12-02 02:18:26.000000000 +0000
+++ mercurial/revlog.py
@@ -13,6 +13,7 @@ and O(changes) merge between branches.
 
 # import stuff from node for others to import from revlog
 import collections
+import os
 from node import bin, hex, nullid, nullrev
 from i18n import _
 import ancestor, mdiff, parsers, error, util, templatefilters
@@ -1426,6 +1427,20 @@ class revlog(object):
         return node
 
     def _writeentry(self, transaction, ifh, dfh, entry, data, link, offset):
+        # Files opened in a+ mode have inconsistent behavior on various
+        # platforms. Windows requires that a file positioning call be made
+        # when the file handle transitions between reads and writes. See
+        # 3686fa2b8eee and the mixedfilemodewrapper in windows.py. On other
+        # platforms, Python or the platform itself can be buggy. Some versions
+        # of Solaris have been observed to not append at the end of the file
+        # if the file was seeked to before the end. See issue4943 for more.
+        #
+        # We work around this issue by inserting a seek() before writing.
+        # Note: This is likely not necessary on Python 3.
+        ifh.seek(0, os.SEEK_END)
+        if dfh:
+            dfh.seek(0, os.SEEK_END)
+
         curr = len(self) - 1
         if not self._inline:
             transaction.add(self.datafile, offset)
