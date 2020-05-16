$NetBSD: patch-setup.py,v 1.3 2020/05/16 02:11:40 joerg Exp $

--- setup.py.orig	2020-05-15 22:33:46.785574641 +0000
+++ setup.py
@@ -49,7 +49,7 @@ except ImportError:
 base_dir = os.path.dirname(__file__)
 
 __pkginfo__ = {}
-with open(os.path.join(base_dir, "pylint", "__pkginfo__.py")) as pkginfo_fp:
+with open(os.path.join(base_dir, "pylint", "__pkginfo__.py"), encoding="UTF-8") as pkginfo_fp:
     exec(pkginfo_fp.read(), __pkginfo__)
 scripts = __pkginfo__.get("scripts", [])
 data_files = __pkginfo__.get("data_files", None)
