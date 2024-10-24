$NetBSD: patch-hgdemandimport_____init____.py,v 1.1 2024/10/24 10:41:05 wiz Exp $

Fix for Python 3.13.
https://lists.mercurial-scm.org/pipermail/mercurial-devel/2024-October/298120.html
https://bz.mercurial-scm.org/show_bug.cgi?id=6926

--- hgdemandimport/__init__.py.orig	2024-10-24 10:25:40.152971956 +0000
+++ hgdemandimport/__init__.py
@@ -62,6 +62,7 @@ IGNORES = {
     '_weakrefset',
     'warnings',
     'threading',
+    'collections.abc',
 }
 
 _pypy = '__pypy__' in sys.builtin_module_names
