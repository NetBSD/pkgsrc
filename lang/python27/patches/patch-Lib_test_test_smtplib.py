$NetBSD: patch-Lib_test_test_smtplib.py,v 1.1 2014/06/09 17:58:31 he Exp $

Apply a fix for CVE-2013-1752 for the SMTP part.
From http://bugs.python.org/issue16042.

--- Lib/test/test_smtplib.py.orig	2014-05-31 18:58:39.000000000 +0000
+++ Lib/test/test_smtplib.py
@@ -292,6 +292,32 @@ class BadHELOServerTests(unittest.TestCa
                             HOST, self.port, 'localhost', 3)
 
 
+class TooLongLineTests(TestCase):
+    respdata = '250 OK' + ('.' * smtplib._MAXLINE * 2) + '\n'
+
+    def setUp(self):
+        self.old_stdout = sys.stdout
+        self.output = StringIO.StringIO()
+        sys.stdout = self.output
+
+        self.evt = threading.Event()
+        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
+        self.sock.settimeout(15)
+        self.port = test_support.bind_port(self.sock)
+        servargs = (self.evt, self.respdata, self.sock)
+        threading.Thread(target=server, args=servargs).start()
+        self.evt.wait()
+        self.evt.clear()
+
+    def tearDown(self):
+        self.evt.wait()
+        sys.stdout = self.old_stdout
+
+    def testLineTooLong(self):
+        self.assertRaises(smtplib.SMTPResponseException, smtplib.SMTP,
+                          HOST, self.port, 'localhost', 3)
+
+
 sim_users = {'Mr.A@somewhere.com':'John A',
              'Ms.B@somewhere.com':'Sally B',
              'Mrs.C@somewhereesle.com':'Ruth C',
@@ -511,7 +537,8 @@ class SMTPSimTests(unittest.TestCase):
 def test_main(verbose=None):
     test_support.run_unittest(GeneralTests, DebuggingServerTests,
                               NonConnectingTests,
-                              BadHELOServerTests, SMTPSimTests)
+                              BadHELOServerTests, SMTPSimTests,
+                              TooLongLineTests)
 
 if __name__ == '__main__':
     test_main()
