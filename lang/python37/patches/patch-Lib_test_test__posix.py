$NetBSD: patch-Lib_test_test__posix.py,v 1.1 2020/11/17 19:33:26 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Lib/test/test_posix.py.orig	2020-08-15 05:20:16.000000000 +0000
+++ Lib/test/test_posix.py
@@ -1502,9 +1502,239 @@ class PosixGroupsTester(unittest.TestCas
             posix.setgroups(groups)
             self.assertListEqual(groups, posix.getgroups())
 
+@unittest.skipUnless(sys.platform == "darwin", "test weak linking on macOS")
+class TestPosixWeaklinking(unittest.TestCase):
+    # These test cases verify that weak linking support on macOS works
+    # as expected. These cases only test new behaviour introduced by weak linking,
+    # regular behaviour is tested by the normal test cases.
+    #
+    # See the section on Weak Linking in Mac/README.txt for more information.
+    def setUp(self):
+        import sysconfig
+        import platform
+
+        config_vars = sysconfig.get_config_vars()
+        self.available = { nm for nm in config_vars if nm.startswith("HAVE_") and config_vars[nm] }
+        self.mac_ver = tuple(int(part) for part in platform.mac_ver()[0].split("."))
+
+    def _verify_available(self, name):
+        if name not in self.available:
+            raise unittest.SkipTest(f"{name} not weak-linked")
+
+    def test_pwritev(self):
+        self._verify_available("HAVE_PWRITEV")
+        if self.mac_ver >= (10, 16):
+            self.assertTrue(hasattr(os, "pwritev"), "os.pwritev is not available")
+            self.assertTrue(hasattr(os, "preadv"), "os.readv is not available")
+
+        else:
+            self.assertFalse(hasattr(os, "pwritev"), "os.pwritev is available")
+            self.assertFalse(hasattr(os, "preadv"), "os.readv is available")
+
+    def test_stat(self):
+        self._verify_available("HAVE_FSTATAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_FSTATAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_FSTATAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.stat("file", dir_fd=0)
+
+    def test_access(self):
+        self._verify_available("HAVE_FACCESSAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_FACCESSAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_FACCESSAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.access("file", os.R_OK, dir_fd=0)
+
+            with self.assertRaisesRegex(NotImplementedError, "follow_symlinks unavailable"):
+                os.access("file", os.R_OK, follow_symlinks=False)
+
+            with self.assertRaisesRegex(NotImplementedError, "effective_ids unavailable"):
+                os.access("file", os.R_OK, effective_ids=True)
+
+    def test_chmod(self):
+        self._verify_available("HAVE_FCHMODAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_FCHMODAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_FCHMODAT", posix._have_functions)
+            self.assertIn("HAVE_LCHMOD", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.chmod("file", 0o644, dir_fd=0)
+
+    def test_chown(self):
+        self._verify_available("HAVE_FCHOWNAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_FCHOWNAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_FCHOWNAT", posix._have_functions)
+            self.assertIn("HAVE_LCHOWN", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.chown("file", 0, 0, dir_fd=0)
+
+    def test_link(self):
+        self._verify_available("HAVE_LINKAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_LINKAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_LINKAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "src_dir_fd unavailable"):
+                os.link("source", "target",  src_dir_fd=0)
+
+            with self.assertRaisesRegex(NotImplementedError, "dst_dir_fd unavailable"):
+                os.link("source", "target",  dst_dir_fd=0)
+
+            with self.assertRaisesRegex(NotImplementedError, "src_dir_fd unavailable"):
+                os.link("source", "target",  src_dir_fd=0, dst_dir_fd=0)
+
+            # issue 41355: !HAVE_LINKAT code path ignores the follow_symlinks flag
+            with os_helper.temp_dir() as base_path:
+                link_path = os.path.join(base_path, "link")
+                target_path = os.path.join(base_path, "target")
+                source_path = os.path.join(base_path, "source")
+
+                with open(source_path, "w") as fp:
+                    fp.write("data")
+
+                os.symlink("target", link_path)
+
+                # Calling os.link should fail in the link(2) call, and
+                # should not reject *follow_symlinks* (to match the
+                # behaviour you'd get when building on a platform without
+                # linkat)
+                with self.assertRaises(FileExistsError):
+                    os.link(source_path, link_path, follow_symlinks=True)
+
+                with self.assertRaises(FileExistsError):
+                    os.link(source_path, link_path, follow_symlinks=False)
+
+
+    def test_listdir_scandir(self):
+        self._verify_available("HAVE_FDOPENDIR")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_FDOPENDIR", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_FDOPENDIR", posix._have_functions)
+
+            with self.assertRaisesRegex(TypeError, "listdir: path should be string, bytes, os.PathLike or None, not int"):
+                os.listdir(0)
+
+            with self.assertRaisesRegex(TypeError, "scandir: path should be string, bytes, os.PathLike or None, not int"):
+                os.scandir(0)
+
+    def test_mkdir(self):
+        self._verify_available("HAVE_MKDIRAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_MKDIRAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_MKDIRAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.mkdir("dir", dir_fd=0)
+
+    def test_rename_replace(self):
+        self._verify_available("HAVE_RENAMEAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_RENAMEAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_RENAMEAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "src_dir_fd and dst_dir_fd unavailable"):
+                os.rename("a", "b", src_dir_fd=0)
+
+            with self.assertRaisesRegex(NotImplementedError, "src_dir_fd and dst_dir_fd unavailable"):
+                os.rename("a", "b", dst_dir_fd=0)
+
+            with self.assertRaisesRegex(NotImplementedError, "src_dir_fd and dst_dir_fd unavailable"):
+                os.replace("a", "b", src_dir_fd=0)
+
+            with self.assertRaisesRegex(NotImplementedError, "src_dir_fd and dst_dir_fd unavailable"):
+                os.replace("a", "b", dst_dir_fd=0)
+
+    def test_unlink_rmdir(self):
+        self._verify_available("HAVE_UNLINKAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_UNLINKAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_UNLINKAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.unlink("path", dir_fd=0)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.rmdir("path", dir_fd=0)
+
+    def test_open(self):
+        self._verify_available("HAVE_OPENAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_OPENAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_OPENAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.open("path", os.O_RDONLY, dir_fd=0)
+
+    def test_readlink(self):
+        self._verify_available("HAVE_READLINKAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_READLINKAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_READLINKAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.readlink("path",  dir_fd=0)
+
+    def test_symlink(self):
+        self._verify_available("HAVE_SYMLINKAT")
+        if self.mac_ver >= (10, 10):
+            self.assertIn("HAVE_SYMLINKAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_SYMLINKAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.symlink("a", "b",  dir_fd=0)
+
+    def test_utime(self):
+        self._verify_available("HAVE_FUTIMENS")
+        self._verify_available("HAVE_UTIMENSAT")
+        if self.mac_ver >= (10, 13):
+            self.assertIn("HAVE_FUTIMENS", posix._have_functions)
+            self.assertIn("HAVE_UTIMENSAT", posix._have_functions)
+
+        else:
+            self.assertNotIn("HAVE_FUTIMENS", posix._have_functions)
+            self.assertNotIn("HAVE_UTIMENSAT", posix._have_functions)
+
+            with self.assertRaisesRegex(NotImplementedError, "dir_fd unavailable"):
+                os.utime("path", dir_fd=0)
+
 def test_main():
     try:
-        support.run_unittest(PosixTester, PosixGroupsTester)
+        support.run_unittest(
+            PosixTester,
+            PosixGroupsTester,
+            TestPosixWeaklinking
+        )
     finally:
         support.reap_children()
 
