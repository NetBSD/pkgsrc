$NetBSD: patch-Lib_poplib.py,v 1.1 2014/06/09 17:58:31 he Exp $

Apply a fix for CVE-2013-1752.
From http://bugs.python.org/issue16041.

--- Lib/poplib.py.orig	2014-06-09 11:29:36.000000000 +0000
+++ Lib/poplib.py
@@ -32,6 +32,12 @@ CR = '\r'
 LF = '\n'
 CRLF = CR+LF
 
+# maximal line length when calling readline(). This is to prevent
+# reading arbitrary lenght lines. RFC 1939 limits POP3 line length to
+# 512 characters, including CRLF. We have selected 2048 just to be on
+# the safe side.
+_MAXLINE = 2048
+
 
 class POP3:
 
@@ -103,7 +109,10 @@ class POP3:
     # Raise error_proto('-ERR EOF') if the connection is closed.
 
     def _getline(self):
-        line = self.file.readline()
+        line = self.file.readline(_MAXLINE + 1)
+        if len(line) > _MAXLINE:
+            raise error_proto('line too long')
+
         if self._debugging > 1: print '*get*', repr(line)
         if not line: raise error_proto('-ERR EOF')
         octets = len(line)
@@ -363,7 +372,10 @@ else:
             line = ""
             renewline = re.compile(r'.*?\n')
             match = renewline.match(self.buffer)
+
             while not match:
+                if len(self.buffer) > _MAXLINE:
+                    raise error_proto('line too long')
                 self._fillBuffer()
                 match = renewline.match(self.buffer)
             line = match.group(0)
