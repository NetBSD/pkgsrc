$NetBSD: patch-Lib_mailcap.py,v 1.1 2022/08/11 01:32:50 gutteridge Exp $

Fix CVE-2015-20107: Make mailcap refuse to match unsafe filenames/types/params

Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/raw/a9b12e85bd4d3280e07bc3bfa72a9f2b674cb4ff/f/00382-cve-2015-20107.patch

--- Lib/mailcap.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/mailcap.py
@@ -1,9 +1,18 @@
 """Mailcap file handling.  See RFC 1524."""
 
 import os
+import warnings
+import re
 
 __all__ = ["getcaps","findmatch"]
 
+
+_find_unsafe = re.compile(r'[^\xa1-\xff\w@+=:,./-]').search
+
+class UnsafeMailcapInput(Warning):
+    """Warning raised when refusing unsafe input"""
+
+
 # Part 1: top-level interface.
 
 def getcaps():
@@ -144,15 +153,22 @@ def findmatch(caps, MIMEtype, key='view'
     entry to use.
 
     """
+    if _find_unsafe(filename):
+        msg = "Refusing to use mailcap with filename %r. Use a safe temporary filename." % (filename,)
+        warnings.warn(msg, UnsafeMailcapInput)
+        return None, None
     entries = lookup(caps, MIMEtype, key)
     # XXX This code should somehow check for the needsterminal flag.
     for e in entries:
         if 'test' in e:
             test = subst(e['test'], filename, plist)
+            if test is None:
+                continue
             if test and os.system(test) != 0:
                 continue
         command = subst(e[key], MIMEtype, filename, plist)
-        return command, e
+        if command is not None:
+            return command, e
     return None, None
 
 def lookup(caps, MIMEtype, key=None):
@@ -184,6 +200,10 @@ def subst(field, MIMEtype, filename, pli
             elif c == 's':
                 res = res + filename
             elif c == 't':
+                if _find_unsafe(MIMEtype):
+                    msg = "Refusing to substitute MIME type %r into a shell command." % (MIMEtype,)
+                    warnings.warn(msg, UnsafeMailcapInput)
+                    return None
                 res = res + MIMEtype
             elif c == '{':
                 start = i
@@ -191,7 +211,12 @@ def subst(field, MIMEtype, filename, pli
                     i = i+1
                 name = field[start:i]
                 i = i+1
-                res = res + findparam(name, plist)
+                param = findparam(name, plist)
+                if _find_unsafe(param):
+                    msg = "Refusing to substitute parameter %r (%s) into a shell command" % (param, name)
+                    warnings.warn(msg, UnsafeMailcapInput)
+                    return None
+                res = res + param
             # XXX To do:
             # %n == number of parts if type is multipart/*
             # %F == list of alternating type and filename for parts
