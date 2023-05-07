$NetBSD: patch-doc_conf.py,v 1.1 2023/05/07 13:09:52 wiz Exp $

Sphinx compatibility per https://github.com/sphinx-doc/sphinx/issues/11094

--- doc/conf.py.orig	2022-09-26 21:22:00.000000000 +0000
+++ doc/conf.py
@@ -203,9 +203,9 @@ extlinks = {
         "https://github.com/saltstack/salt/blob/%s/%%s" % repo_primary_branch,
         None,
     ),
-    "issue": ("https://github.com/saltstack/salt/issues/%s", "issue #"),
-    "pull": ("https://github.com/saltstack/salt/pull/%s", "PR #"),
-    "formula_url": ("https://github.com/saltstack-formulas/%s", ""),
+    "issue": ("https://github.com/saltstack/salt/issues/%s", "issue #%s"),
+    "pull": ("https://github.com/saltstack/salt/pull/%s", "PR #%s"),
+    "formula_url": ("https://github.com/saltstack-formulas/%s", "%s"),
 }
 
 
