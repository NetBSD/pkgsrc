$NetBSD: patch-Lib_smtplib.py,v 1.1 2014/06/09 17:58:31 he Exp $

Apply a fix for CVE-2013-1752 for the SMTP part.
From http://bugs.python.org/issue16042.

--- Lib/smtplib.py.orig	2014-05-31 18:58:39.000000000 +0000
+++ Lib/smtplib.py
@@ -57,6 +57,7 @@ __all__ = ["SMTPException", "SMTPServerD
 SMTP_PORT = 25
 SMTP_SSL_PORT = 465
 CRLF = "\r\n"
+_MAXLINE = 8192 # more than 8 times larger than RFC 821, 4.5.3
 
 OLDSTYLE_AUTH = re.compile(r"auth=(.*)", re.I)
 
@@ -179,10 +180,14 @@ else:
         def __init__(self, sslobj):
             self.sslobj = sslobj
 
-        def readline(self):
+        def readline(self, size=-1):
+            if size < 0:
+                size = None
             str = ""
             chr = None
             while chr != "\n":
+                if size is not None and len(str) >= size:
+                    break
                 chr = self.sslobj.read(1)
                 if not chr:
                     break
@@ -353,7 +358,7 @@ class SMTP:
             self.file = self.sock.makefile('rb')
         while 1:
             try:
-                line = self.file.readline()
+                line = self.file.readline(_MAXLINE + 1)
             except socket.error as e:
                 self.close()
                 raise SMTPServerDisconnected("Connection unexpectedly closed: "
@@ -362,7 +367,9 @@ class SMTP:
                 self.close()
                 raise SMTPServerDisconnected("Connection unexpectedly closed")
             if self.debuglevel > 0:
-                print>>stderr, 'reply:', repr(line)
+                print >>stderr, 'reply:', repr(line)
+            if len(line) > _MAXLINE:
+                raise SMTPResponseException(500, "Line too long.")
             resp.append(line[4:].strip())
             code = line[:3]
             # Check that the error code is syntactically correct.
