$NetBSD: patch-tests_test__main.py,v 1.1 2025/01/23 19:31:09 riastradh Exp $

Add `--executable' option.
https://github.com/pypa/installer/issues/257
https://github.com/pypa/installer/pull/258

--- tests/test_main.py.orig	2025-01-20 07:30:09.049591508 +0000
+++ tests/test_main.py
@@ -36,7 +36,18 @@ def test_main(fancy_wheel, tmp_path):
 def test_main_prefix(fancy_wheel, tmp_path):
     destdir = tmp_path / "dest"
 
-    main([str(fancy_wheel), "-d", str(destdir), "-p", "/foo"], "python -m installer")
+    main(
+        [
+            str(fancy_wheel),
+            "-d",
+            str(destdir),
+            "-p",
+            "/foo",
+            "--executable",
+            "/monty/python3.x",
+        ],
+        "python -m installer",
+    )
 
     installed_py_files = list(destdir.rglob("*.py"))
 
@@ -52,6 +63,16 @@ def test_main_prefix(fancy_wheel, tmp_pa
         "__main__",
     }
 
+    installed_scripts = destdir.rglob("bin/*")
+
+    for f in installed_scripts:
+        with f.open("rb") as fp:
+            shebang = fp.readline()
+            assert (
+                shebang == b"#!/monty/python3.x\n"
+                or shebang == b"#! /monty/python3.x\n"
+            )
+
 
 def test_main_no_pyc(fancy_wheel, tmp_path):
     destdir = tmp_path / "dest"
