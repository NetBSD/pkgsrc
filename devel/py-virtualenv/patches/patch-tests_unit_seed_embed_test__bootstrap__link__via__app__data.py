$NetBSD: patch-tests_unit_seed_embed_test__bootstrap__link__via__app__data.py,v 1.2 2022/09/08 07:46:09 adam Exp $

Fix testing, related to patch-src_virtualenv_create_via__global__ref_api.py.

--- tests/unit/seed/embed/test_bootstrap_link_via_app_data.py.orig	2022-09-08 02:18:47.000000000 +0000
+++ tests/unit/seed/embed/test_bootstrap_link_via_app_data.py
@@ -110,6 +110,7 @@ def test_seed_link_via_app_data(tmp_path
         purelib = result.creator.purelib
         patch_files = {purelib / f"{'_virtualenv'}.{i}" for i in ("py", "pyc", "pth")}
         patch_files.add(purelib / "__pycache__")
+        patch_files.add(purelib / "_distutils_system_mod.py")
         post_run = set(site_package.iterdir()) - patch_files
         assert not post_run, "\n".join(str(i) for i in post_run)
 
