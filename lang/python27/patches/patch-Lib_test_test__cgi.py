$NetBSD: patch-Lib_test_test__cgi.py,v 1.1 2021/10/10 03:00:59 gutteridge Exp $

Fix CVE-2021-23336: Add `separator` argument to parse_qs; warn with default
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00359-CVE-2021-23336.patch

--- Lib/test/test_cgi.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/test/test_cgi.py
@@ -61,12 +61,9 @@ parse_strict_test_cases = [
     ("", ValueError("bad query field: ''")),
     ("&", ValueError("bad query field: ''")),
     ("&&", ValueError("bad query field: ''")),
-    (";", ValueError("bad query field: ''")),
-    (";&;", ValueError("bad query field: ''")),
     # Should the next few really be valid?
     ("=", {}),
     ("=&=", {}),
-    ("=;=", {}),
     # This rest seem to make sense
     ("=a", {'': ['a']}),
     ("&=a", ValueError("bad query field: ''")),
@@ -81,8 +78,6 @@ parse_strict_test_cases = [
     ("a=a+b&b=b+c", {'a': ['a b'], 'b': ['b c']}),
     ("a=a+b&a=b+a", {'a': ['a b', 'b a']}),
     ("x=1&y=2.0&z=2-3.%2b0", {'x': ['1'], 'y': ['2.0'], 'z': ['2-3.+0']}),
-    ("x=1;y=2.0&z=2-3.%2b0", {'x': ['1'], 'y': ['2.0'], 'z': ['2-3.+0']}),
-    ("x=1;y=2.0;z=2-3.%2b0", {'x': ['1'], 'y': ['2.0'], 'z': ['2-3.+0']}),
     ("Hbc5161168c542333633315dee1182227:key_store_seqid=400006&cuyer=r&view=bustomer&order_id=0bb2e248638833d48cb7fed300000f1b&expire=964546263&lobale=en-US&kid=130003.300038&ss=env",
      {'Hbc5161168c542333633315dee1182227:key_store_seqid': ['400006'],
       'cuyer': ['r'],
@@ -143,6 +138,60 @@ class CgiTests(unittest.TestCase):
             if isinstance(expect, dict):
                 # test dict interface
                 self.assertEqual(len(expect), len(fcd))
+                self.assertItemsEqual(expect.keys(), fcd.keys())
+                self.assertItemsEqual(expect.values(), fcd.values())
+                self.assertItemsEqual(expect.items(), fcd.items())
+                self.assertEqual(fcd.get("nonexistent field", "default"), "default")
+                self.assertEqual(len(sd), len(fs))
+                self.assertItemsEqual(sd.keys(), fs.keys())
+                self.assertEqual(fs.getvalue("nonexistent field", "default"), "default")
+                # test individual fields
+                for key in expect.keys():
+                    expect_val = expect[key]
+                    self.assertTrue(fcd.has_key(key))
+                    self.assertItemsEqual(fcd[key], expect[key])
+                    self.assertEqual(fcd.get(key, "default"), fcd[key])
+                    self.assertTrue(fs.has_key(key))
+                    if len(expect_val) > 1:
+                        single_value = 0
+                    else:
+                        single_value = 1
+                    try:
+                        val = sd[key]
+                    except IndexError:
+                        self.assertFalse(single_value)
+                        self.assertEqual(fs.getvalue(key), expect_val)
+                    else:
+                        self.assertTrue(single_value)
+                        self.assertEqual(val, expect_val[0])
+                        self.assertEqual(fs.getvalue(key), expect_val[0])
+                    self.assertItemsEqual(sd.getlist(key), expect_val)
+                    if single_value:
+                        self.assertItemsEqual(sd.values(),
+                                                first_elts(expect.values()))
+                        self.assertItemsEqual(sd.items(),
+                                                first_second_elts(expect.items()))
+
+    def test_separator(self):
+        parse_semicolon = [
+            ("x=1;y=2.0", {'x': ['1'], 'y': ['2.0']}),
+            ("x=1;y=2.0;z=2-3.%2b0", {'x': ['1'], 'y': ['2.0'], 'z': ['2-3.+0']}),
+            (";", ValueError("bad query field: ''")),
+            (";;", ValueError("bad query field: ''")),
+            ("=;a", ValueError("bad query field: 'a'")),
+            (";b=a", ValueError("bad query field: ''")),
+            ("b;=a", ValueError("bad query field: 'b'")),
+            ("a=a+b;b=b+c", {'a': ['a b'], 'b': ['b c']}),
+            ("a=a+b;a=b+a", {'a': ['a b', 'b a']}),
+        ]
+        for orig, expect in parse_semicolon:
+            env = {'QUERY_STRING': orig}
+            fcd = cgi.FormContentDict(env, separator=';')
+            sd = cgi.SvFormContentDict(env, separator=';')
+            fs = cgi.FieldStorage(environ=env, separator=';')
+            if isinstance(expect, dict):
+                # test dict interface
+                self.assertEqual(len(expect), len(fcd))
                 self.assertItemsEqual(expect.keys(), fcd.keys())
                 self.assertItemsEqual(expect.values(), fcd.values())
                 self.assertItemsEqual(expect.items(), fcd.items())
