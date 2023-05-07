$NetBSD: patch-doc_conf.py,v 1.1 2023/05/07 12:39:58 wiz Exp $

Sphinx compat per https://github.com/sphinx-doc/sphinx/issues/11094

--- doc/conf.py.orig	2022-02-10 16:06:45.000000000 +0000
+++ doc/conf.py
@@ -175,13 +175,13 @@ texinfo_documents = [
 extensions.append('sphinx.ext.extlinks')
 
 extlinks = {
-    'issue': ('https://github.com/SrainApp/srain/issues/%s', '#'),
-    'pull': ('https://github.com/SrainApp/srain/pull/%s', '#'),
-    'commit': ('https://github.com/SrainApp/srain/commit/%s', ''),
+    'issue': ('https://github.com/SrainApp/srain/issues/%s', '#%s'),
+    'pull': ('https://github.com/SrainApp/srain/pull/%s', '#%s'),
+    'commit': ('https://github.com/SrainApp/srain/commit/%s', '%s'),
 
-    'contrib-issue': ('https://github.com/SrainApp/srain-contrib/issues/%s', 'contrib#'),
-    'contrib-pull': ('https://github.com/SrainApp/srain-contrib/pull/%s', 'contrib#'),
-    'contrib-commit': ('https://github.com/SrainApp/srain/commit/%s', ''),
+    'contrib-issue': ('https://github.com/SrainApp/srain-contrib/issues/%s', 'contrib#%s'),
+    'contrib-pull': ('https://github.com/SrainApp/srain-contrib/pull/%s', 'contrib#%s'),
+    'contrib-commit': ('https://github.com/SrainApp/srain/commit/%s', '%s'),
 
-    'people': ('https://github.com/%s', '@'),
+    'people': ('https://github.com/%s', '@%s'),
 }
