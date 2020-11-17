$NetBSD: patch-Lib_test_test__time.py,v 1.1 2020/11/17 19:33:26 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Lib/test/test_time.py.orig	2020-08-15 05:20:16.000000000 +0000
+++ Lib/test/test_time.py
@@ -1052,6 +1052,36 @@ class TestOldPyTime(CPyTimeTestCase, uni
             with self.assertRaises(ValueError):
                 pytime_object_to_timespec(float('nan'), time_rnd)
 
+@unittest.skipUnless(sys.platform == "darwin", "test weak linking on macOS")
+class TestTimeWeaklinking(unittest.TestCase):
+    # These test cases verify that weak linking support on macOS works
+    # as expected. These cases only test new behaviour introduced by weak linking,
+    # regular behaviour is tested by the normal test cases.
+    #
+    # See the section on Weak Linking in Mac/README.txt for more information.
+    def test_clock_functions(self):
+        import sysconfig
+        import platform
+
+        config_vars = sysconfig.get_config_vars()
+        var_name = "HAVE_CLOCK_GETTIME"
+        if var_name not in config_vars or not config_vars[var_name]:
+            raise unittest.SkipTest(f"{var_name} is not available")
+
+        mac_ver = tuple(int(x) for x in platform.mac_ver()[0].split("."))
+
+        clock_names = [
+            "CLOCK_MONOTONIC", "clock_gettime", "clock_gettime_ns", "clock_settime",
+            "clock_settime_ns", "clock_getres"]
+
+        if mac_ver >= (10, 12):
+            for name in clock_names:
+                self.assertTrue(hasattr(time, name), f"time.{name} is not available")
+
+        else:
+            for name in clock_names:
+                self.assertFalse(hasattr(time, name), f"time.{name} is available")
+
 
 if __name__ == "__main__":
     unittest.main()
