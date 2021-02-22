$NetBSD: patch-setup.py,v 1.4 2021/02/22 09:24:34 adam Exp $

Fix file encoding.

--- setup.py.orig	2021-02-21 16:16:02.000000000 +0000
+++ setup.py
@@ -57,7 +57,7 @@ __docformat__ = "restructuredtext en"
 base_dir = os.path.dirname(__file__)
 
 __pkginfo__: Dict[str, Any] = {}
-with open(os.path.join(base_dir, "pylint", "__pkginfo__.py")) as pkginfo_fp:
+with open(os.path.join(base_dir, "pylint", "__pkginfo__.py"), encoding="utf-8") as pkginfo_fp:
     exec(pkginfo_fp.read(), __pkginfo__)
 scripts = __pkginfo__.get("scripts", [])
 data_files = __pkginfo__.get("data_files", None)
