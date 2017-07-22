$NetBSD: patch-hgfastimport_hgimport.py,v 1.1 2017/07/22 16:16:25 joerg Exp $

--- hgfastimport/hgimport.py.orig	2017-07-22 14:10:21.608040482 +0000
+++ hgfastimport/hgimport.py
@@ -449,3 +452,6 @@ class HgImportCommitHandler(processor.Co
         # copy oldname to newname and delete oldname
         self.copies[filecmd.new_path] = filecmd.old_path
         self.modified.append((filecmd.old_path, None))
+
+    def deleteall_handler(self, filecmd):
+        pass # Drop it for now, used by fossil when no parent exists.
