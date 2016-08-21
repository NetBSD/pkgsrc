$NetBSD: patch-setup.py,v 1.2 2016/08/21 21:26:01 markd Exp $

Fix man path.

--- setup.py.orig	2016-08-05 23:24:22.000000000 +0000
+++ setup.py
@@ -34,7 +34,7 @@ setup(
             'src/depdiagram-generate-all',
         ],
         data_files= [
-            (os.path.join('share', 'man', 'man1'), ['docs/depdiagram-prepare.1',
+            (os.path.join('man', 'man1'), ['docs/depdiagram-prepare.1',
                 'docs/depdiagram-generate.1',
                 'docs/depdiagram-generate-all.1'])],
         classifiers = [
