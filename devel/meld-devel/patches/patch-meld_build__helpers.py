$NetBSD: patch-meld_build__helpers.py,v 1.1 2014/02/24 12:24:11 wiz Exp $

--- meld/build_helpers.py.orig	2014-02-22 20:41:47.000000000 +0000
+++ meld/build_helpers.py
@@ -135,7 +135,7 @@ class build_help(distutils.cmd.Command):
             for page in pages:
                 page_path = os.path.join(build_path, page)
                 if not os.path.exists(page_path):
-                    print "Skipping missing file", page_path
+                    print ("Skipping missing file", page_path)
                     continue
                 lint = ['xmllint', '--noout', '--noent', '--path', build_path,
                         '--xinclude', page_path]
