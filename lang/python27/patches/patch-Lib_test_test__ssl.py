$NetBSD: patch-Lib_test_test__ssl.py,v 1.1.2.2 2013/08/21 11:47:14 tron Exp $

patch for CVE-2013-4238 taken from
http://hg.python.org/cpython/rev/bd2360476bdb

--- Lib/test/test_ssl.py.orig	2013-05-12 03:32:47.000000000 +0000
+++ Lib/test/test_ssl.py
@@ -25,6 +25,7 @@ ssl = test_support.import_module("ssl")
 HOST = test_support.HOST
 CERTFILE = None
 SVN_PYTHON_ORG_ROOT_CERT = None
+NULLBYTECERT = None
 
 def handle_error(prefix):
     exc_format = ' '.join(traceback.format_exception(*sys.exc_info()))
@@ -123,6 +124,27 @@ class BasicSocketTests(unittest.TestCase
                           ('DNS', 'projects.forum.nokia.com'))
                         )
 
+    def test_parse_cert_CVE_2013_4238(self):
+        p = ssl._ssl._test_decode_cert(NULLBYTECERT)
+        if test_support.verbose:
+            sys.stdout.write("\n" + pprint.pformat(p) + "\n")
+        subject = ((('countryName', 'US'),),
+                   (('stateOrProvinceName', 'Oregon'),),
+                   (('localityName', 'Beaverton'),),
+                   (('organizationName', 'Python Software Foundation'),),
+                   (('organizationalUnitName', 'Python Core Development'),),
+                   (('commonName', 'null.python.org\x00example.org'),),
+                   (('emailAddress', 'python-dev@python.org'),))
+        self.assertEqual(p['subject'], subject)
+        self.assertEqual(p['issuer'], subject)
+        self.assertEqual(p['subjectAltName'],
+                         (('DNS', 'altnull.python.org\x00example.com'),
+                         ('email', 'null@python.org\x00user@example.org'),
+                         ('URI', 'http://null.python.org\x00http://example.org'),
+                         ('IP Address', '192.0.2.1'),
+                         ('IP Address', '2001:DB8:0:0:0:0:0:1\n'))
+                        )
+
     def test_DER_to_PEM(self):
         with open(SVN_PYTHON_ORG_ROOT_CERT, 'r') as f:
             pem = f.read()
@@ -1360,7 +1382,7 @@ else:
 
 
 def test_main(verbose=False):
-    global CERTFILE, SVN_PYTHON_ORG_ROOT_CERT, NOKIACERT
+    global CERTFILE, SVN_PYTHON_ORG_ROOT_CERT, NOKIACERT, NULLBYTECERT
     CERTFILE = os.path.join(os.path.dirname(__file__) or os.curdir,
                             "keycert.pem")
     SVN_PYTHON_ORG_ROOT_CERT = os.path.join(
@@ -1368,10 +1390,13 @@ def test_main(verbose=False):
         "https_svn_python_org_root.pem")
     NOKIACERT = os.path.join(os.path.dirname(__file__) or os.curdir,
                              "nokia.pem")
+    NULLBYTECERT = os.path.join(os.path.dirname(__file__) or os.curdir,
+                                "nullbytecert.pem")
 
     if (not os.path.exists(CERTFILE) or
         not os.path.exists(SVN_PYTHON_ORG_ROOT_CERT) or
-        not os.path.exists(NOKIACERT)):
+        not os.path.exists(NOKIACERT) or
+        not os.path.exists(NULLBYTECERT)):
         raise test_support.TestFailed("Can't read certificate files!")
 
     tests = [BasicTests, BasicSocketTests]
