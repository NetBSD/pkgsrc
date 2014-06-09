$NetBSD: patch-Lib_test_test__poplib.py,v 1.1 2014/06/09 17:58:31 he Exp $

Apply a fix for CVE-2013-1752.
From http://bugs.python.org/issue16041.

--- Lib/test/test_poplib.py.orig	2014-06-09 11:29:38.000000000 +0000
+++ Lib/test/test_poplib.py
@@ -81,7 +81,7 @@ class DummyPOP3Handler(asynchat.async_ch
 
     def cmd_list(self, arg):
         if arg:
-            self.push('+OK %s %s' %(arg, arg))
+            self.push('+OK %s %s' % (arg, arg))
         else:
             self.push('+OK')
             asynchat.async_chat.push(self, LIST_RESP)
@@ -198,6 +198,10 @@ class TestPOP3Class(TestCase):
                     113)
         self.assertEqual(self.client.retr('foo'), expected)
 
+    def test_too_long_lines(self):
+        self.assertRaises(poplib.error_proto, self.client._shortcmd,
+                          'echo %s' % (3000 * 'a'))
+
     def test_dele(self):
         self.assertOK(self.client.dele('foo'))
 
