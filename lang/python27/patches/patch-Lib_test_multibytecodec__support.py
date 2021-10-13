$NetBSD: patch-Lib_test_multibytecodec__support.py,v 1.1.2.2 2021/10/13 21:04:01 tm Exp $

Fix CVE-2020-27619: No longer call eval() on content received via HTTP in the CJK codec tests
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00355-CVE-2020-27619.patch

--- Lib/test/multibytecodec_support.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/test/multibytecodec_support.py
@@ -279,30 +279,22 @@ class TestBase_Mapping(unittest.TestCase
             self._test_mapping_file_plain()
 
     def _test_mapping_file_plain(self):
-        _unichr = lambda c: eval("u'\\U%08x'" % int(c, 16))
-        unichrs = lambda s: u''.join(_unichr(c) for c in s.split('+'))
+        def unichrs(s):
+            return ''.join(unichr(int(x, 16)) for x in s.split('+'))
         urt_wa = {}
 
         with self.open_mapping_file() as f:
             for line in f:
                 if not line:
                     break
-                data = line.split('#')[0].strip().split()
+                data = line.split('#')[0].split()
                 if len(data) != 2:
                     continue
 
-                csetval = eval(data[0])
-                if csetval <= 0x7F:
-                    csetch = chr(csetval & 0xff)
-                elif csetval >= 0x1000000:
-                    csetch = chr(csetval >> 24) + chr((csetval >> 16) & 0xff) + \
-                             chr((csetval >> 8) & 0xff) + chr(csetval & 0xff)
-                elif csetval >= 0x10000:
-                    csetch = chr(csetval >> 16) + \
-                             chr((csetval >> 8) & 0xff) + chr(csetval & 0xff)
-                elif csetval >= 0x100:
-                    csetch = chr(csetval >> 8) + chr(csetval & 0xff)
-                else:
+                if data[0][:2] != '0x':
+                    self.fail("Invalid line: {!r}".format(line))
+                csetch = bytes.fromhex(data[0][2:])
+                if len(csetch) == 1 and 0x80 <= csetch[0]:
                     continue
 
                 unich = unichrs(data[1])
