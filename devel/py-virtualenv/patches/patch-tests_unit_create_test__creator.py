$NetBSD: patch-tests_unit_create_test__creator.py,v 1.1 2022/05/09 22:08:10 wiz Exp $

Fix testing, related to patch-src_virtualenv_create_via__global__ref_api.py.

--- tests/unit/create/test_creator.py.orig	2022-05-04 12:29:21.000000000 +0000
+++ tests/unit/create/test_creator.py
@@ -156,6 +156,7 @@ def test_create_no_seed(python, creator,
     purelib = creator.purelib
     patch_files = {purelib / "{}.{}".format("_virtualenv", i) for i in ("py", "pyc", "pth")}
     patch_files.add(purelib / "__pycache__")
+    patch_files.add(purelib / "_distutils_system_mod.py")
     content = set(creator.purelib.iterdir()) - patch_files
     assert not content, "\n".join(ensure_text(str(i)) for i in content)
     assert creator.env_name == ensure_text(dest.name)
