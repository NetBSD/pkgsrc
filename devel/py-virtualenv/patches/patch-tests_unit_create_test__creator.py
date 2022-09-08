$NetBSD: patch-tests_unit_create_test__creator.py,v 1.2 2022/09/08 07:46:09 adam Exp $

Fix testing, related to patch-src_virtualenv_create_via__global__ref_api.py.

--- tests/unit/create/test_creator.py.orig	2022-09-08 02:18:47.000000000 +0000
+++ tests/unit/create/test_creator.py
@@ -153,6 +153,7 @@ def test_create_no_seed(python, creator,
     purelib = creator.purelib
     patch_files = {purelib / f"{'_virtualenv'}.{i}" for i in ("py", "pyc", "pth")}
     patch_files.add(purelib / "__pycache__")
+    patch_files.add(purelib / "_distutils_system_mod.py")
     content = set(creator.purelib.iterdir()) - patch_files
     assert not content, "\n".join(str(i) for i in content)
     assert creator.env_name == str(dest.name)
