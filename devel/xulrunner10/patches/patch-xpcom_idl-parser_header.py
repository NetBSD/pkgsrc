$NetBSD: patch-xpcom_idl-parser_header.py,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- xpcom/idl-parser/header.py.orig	2012-03-09 22:20:38.000000000 +0000
+++ xpcom/idl-parser/header.py
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
 
