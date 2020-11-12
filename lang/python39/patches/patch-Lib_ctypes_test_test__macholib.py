$NetBSD: patch-Lib_ctypes_test_test__macholib.py,v 1.1 2020/11/12 10:58:21 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Backported from:
https://github.com/python/cpython/pull/22855

--- Lib/ctypes/test/test_macholib.py.orig	2020-10-05 15:07:58.000000000 +0000
+++ Lib/ctypes/test/test_macholib.py
@@ -45,19 +45,22 @@ def find_lib(name):
 class MachOTest(unittest.TestCase):
     @unittest.skipUnless(sys.platform == "darwin", 'OSX-specific test')
     def test_find(self):
-
-        self.assertEqual(find_lib('pthread'),
-                             '/usr/lib/libSystem.B.dylib')
+        # On Mac OS 11, system dylibs are only present in the shared cache,
+        # so symlinks like libpthread.dylib -> libSystem.B.dylib will not
+        # be resolved by dyld_find
+        self.assertIn(find_lib('pthread'),
+                              ('/usr/lib/libSystem.B.dylib', '/usr/lib/libpthread.dylib'))
 
         result = find_lib('z')
         # Issue #21093: dyld default search path includes $HOME/lib and
         # /usr/local/lib before /usr/lib, which caused test failures if
         # a local copy of libz exists in one of them. Now ignore the head
         # of the path.
-        self.assertRegex(result, r".*/lib/libz\..*.*\.dylib")
+        self.assertRegex(result, r".*/lib/libz.*\.dylib")
 
-        self.assertEqual(find_lib('IOKit'),
-                             '/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit')
+        self.assertIn(find_lib('IOKit'),
+                              ('/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit',
+                              '/System/Library/Frameworks/IOKit.framework/IOKit'))
 
 if __name__ == "__main__":
     unittest.main()
