$NetBSD: patch-tests_unit_seed_embed_test__bootstrap__link__via__app__data.py,v 1.1 2022/05/09 22:08:10 wiz Exp $

Fix testing, related to patch-src_virtualenv_create_via__global__ref_api.py.

--- tests/unit/seed/embed/test_bootstrap_link_via_app_data.py.orig	2022-05-04 12:39:44.000000000 +0000
+++ tests/unit/seed/embed/test_bootstrap_link_via_app_data.py
@@ -114,6 +114,7 @@ def test_seed_link_via_app_data(tmp_path
         purelib = result.creator.purelib
         patch_files = {purelib / "{}.{}".format("_virtualenv", i) for i in ("py", "pyc", "pth")}
         patch_files.add(purelib / "__pycache__")
+        patch_files.add(purelib / "_distutils_system_mod.py")
         post_run = set(site_package.iterdir()) - patch_files
         assert not post_run, "\n".join(str(i) for i in post_run)
 
