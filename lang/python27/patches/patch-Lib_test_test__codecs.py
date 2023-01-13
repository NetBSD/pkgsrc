$NetBSD: patch-Lib_test_test__codecs.py,v 1.1.2.2 2023/01/13 19:54:39 bsiegert Exp $

Security fix for CVE-2022-45061: CPU denial of service via inefficient IDNA decoder
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/raw/64f3700b7679f9f8a385d99e3862a758b14e1d28/f/00394-cve-2022-45061-cpu-denial-of-service-via-inefficient-idna-decoder.patch

--- Lib/test/test_codecs.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/test/test_codecs.py
@@ -1318,6 +1318,12 @@ class IDNACodecTest(unittest.TestCase):
         self.assertEqual(u"pyth\xf6n.org".encode("idna"), "xn--pythn-mua.org")
         self.assertEqual(u"pyth\xf6n.org.".encode("idna"), "xn--pythn-mua.org.")
 
+    def test_builtin_decode_length_limit(self):
+        with self.assertRaisesRegexp(UnicodeError, "too long"):
+            (b"xn--016c"+b"a"*1100).decode("idna")
+        with self.assertRaisesRegexp(UnicodeError, "too long"):
+            (b"xn--016c"+b"a"*70).decode("idna")
+
     def test_stream(self):
         import StringIO
         r = codecs.getreader("idna")(StringIO.StringIO("abc"))
