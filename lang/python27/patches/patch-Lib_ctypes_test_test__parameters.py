$NetBSD: patch-Lib_ctypes_test_test__parameters.py,v 1.1.2.2 2021/10/13 21:04:01 tm Exp $

Fix CVE-2021-3177: Replace snprintf with Python unicode formatting in ctypes param reprs
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00357-CVE-2021-3177.patch

--- Lib/ctypes/test/test_parameters.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/ctypes/test/test_parameters.py
@@ -206,6 +206,49 @@ class SimpleTypesTestCase(unittest.TestC
         with self.assertRaises(ZeroDivisionError):
             WorseStruct().__setstate__({}, b'foo')
 
+    def test_parameter_repr(self):
+        from ctypes import (
+            c_bool,
+            c_char,
+            c_wchar,
+            c_byte,
+            c_ubyte,
+            c_short,
+            c_ushort,
+            c_int,
+            c_uint,
+            c_long,
+            c_ulong,
+            c_longlong,
+            c_ulonglong,
+            c_float,
+            c_double,
+            c_longdouble,
+            c_char_p,
+            c_wchar_p,
+            c_void_p,
+        )
+        self.assertRegexpMatches(repr(c_bool.from_param(True)), r"^<cparam '\?' at 0x[A-Fa-f0-9]+>$")
+        self.assertEqual(repr(c_char.from_param('a')), "<cparam 'c' ('a')>")
+        self.assertRegexpMatches(repr(c_wchar.from_param('a')), r"^<cparam 'u' at 0x[A-Fa-f0-9]+>$")
+        self.assertEqual(repr(c_byte.from_param(98)), "<cparam 'b' (98)>")
+        self.assertEqual(repr(c_ubyte.from_param(98)), "<cparam 'B' (98)>")
+        self.assertEqual(repr(c_short.from_param(511)), "<cparam 'h' (511)>")
+        self.assertEqual(repr(c_ushort.from_param(511)), "<cparam 'H' (511)>")
+        self.assertRegexpMatches(repr(c_int.from_param(20000)), r"^<cparam '[li]' \(20000\)>$")
+        self.assertRegexpMatches(repr(c_uint.from_param(20000)), r"^<cparam '[LI]' \(20000\)>$")
+        self.assertRegexpMatches(repr(c_long.from_param(20000)), r"^<cparam '[li]' \(20000\)>$")
+        self.assertRegexpMatches(repr(c_ulong.from_param(20000)), r"^<cparam '[LI]' \(20000\)>$")
+        self.assertRegexpMatches(repr(c_longlong.from_param(20000)), r"^<cparam '[liq]' \(20000\)>$")
+        self.assertRegexpMatches(repr(c_ulonglong.from_param(20000)), r"^<cparam '[LIQ]' \(20000\)>$")
+        self.assertEqual(repr(c_float.from_param(1.5)), "<cparam 'f' (1.5)>")
+        self.assertEqual(repr(c_double.from_param(1.5)), "<cparam 'd' (1.5)>")
+        self.assertEqual(repr(c_double.from_param(1e300)), "<cparam 'd' (1e+300)>")
+        self.assertRegexpMatches(repr(c_longdouble.from_param(1.5)), r"^<cparam ('d' \(1.5\)|'g' at 0x[A-Fa-f0-9]+)>$")
+        self.assertRegexpMatches(repr(c_char_p.from_param(b'hihi')), "^<cparam 'z' \(0x[A-Fa-f0-9]+\)>$")
+        self.assertRegexpMatches(repr(c_wchar_p.from_param('hihi')), "^<cparam 'Z' \(0x[A-Fa-f0-9]+\)>$")
+        self.assertRegexpMatches(repr(c_void_p.from_param(0x12)), r"^<cparam 'P' \(0x0*12\)>$")
+
 ################################################################
 
 if __name__ == '__main__':
