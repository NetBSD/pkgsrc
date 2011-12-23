$NetBSD: patch-mozilla_xpcom_idl-parser_header.py,v 1.1 2011/12/23 01:16:28 joerg Exp $

--- mozilla/xpcom/idl-parser/header.py.orig	2011-12-22 00:35:28.000000000 +0000
+++ mozilla/xpcom/idl-parser/header.py
@@ -521,6 +521,12 @@ if __name__ == '__main__':
         outfd.close()
 
     if options.depfile is not None:
+        dirname = os.path.dirname(options.depfile)
+        if dirname:
+            try:
+                os.makedirs(dirname)
+            except:
+                pass
         depfd = open(options.depfile, 'w')
         deps = [dep.replace('\\', '/') for dep in idl.deps]
 
