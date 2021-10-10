$NetBSD: patch-Lib_cgi.py,v 1.1 2021/10/10 03:00:59 gutteridge Exp $

Fix CVE-2021-23336: Add `separator` argument to parse_qs; warn with default
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00359-CVE-2021-23336.patch

--- Lib/cgi.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/cgi.py
@@ -121,7 +121,8 @@ log = initlog           # The current lo
 # 0 ==> unlimited input
 maxlen = 0
 
-def parse(fp=None, environ=os.environ, keep_blank_values=0, strict_parsing=0):
+def parse(fp=None, environ=os.environ, keep_blank_values=0,
+          strict_parsing=0, separator=None):
     """Parse a query in the environment or from a file (default stdin)
 
         Arguments, all optional:
@@ -140,6 +141,8 @@ def parse(fp=None, environ=os.environ, k
         strict_parsing: flag indicating what to do with parsing errors.
             If false (the default), errors are silently ignored.
             If true, errors raise a ValueError exception.
+
+        separator: str. The symbol to use for separating the query arguments.
     """
     if fp is None:
         fp = sys.stdin
@@ -171,25 +174,26 @@ def parse(fp=None, environ=os.environ, k
         else:
             qs = ""
         environ['QUERY_STRING'] = qs    # XXX Shouldn't, really
-    return urlparse.parse_qs(qs, keep_blank_values, strict_parsing)
+    return urlparse.parse_qs(qs, keep_blank_values, strict_parsing, separator=separator)
 
 
 # parse query string function called from urlparse,
 # this is done in order to maintain backward compatibility.
 
-def parse_qs(qs, keep_blank_values=0, strict_parsing=0):
+def parse_qs(qs, keep_blank_values=0, strict_parsing=0, separator=None):
     """Parse a query given as a string argument."""
     warn("cgi.parse_qs is deprecated, use urlparse.parse_qs instead",
          PendingDeprecationWarning, 2)
-    return urlparse.parse_qs(qs, keep_blank_values, strict_parsing)
+    return urlparse.parse_qs(qs, keep_blank_values, strict_parsing,
+                             separator=separator)
 
 
-def parse_qsl(qs, keep_blank_values=0, strict_parsing=0, max_num_fields=None):
+def parse_qsl(qs, keep_blank_values=0, strict_parsing=0, max_num_fields=None, separator=None):
     """Parse a query given as a string argument."""
     warn("cgi.parse_qsl is deprecated, use urlparse.parse_qsl instead",
          PendingDeprecationWarning, 2)
     return urlparse.parse_qsl(qs, keep_blank_values, strict_parsing,
-                              max_num_fields)
+                              max_num_fields, separator=separator)
 
 def parse_multipart(fp, pdict):
     """Parse multipart input.
@@ -288,7 +292,6 @@ def parse_multipart(fp, pdict):
 
     return partdict
 
-
 def _parseparam(s):
     while s[:1] == ';':
         s = s[1:]
@@ -395,7 +398,7 @@ class FieldStorage:
 
     def __init__(self, fp=None, headers=None, outerboundary="",
                  environ=os.environ, keep_blank_values=0, strict_parsing=0,
-                 max_num_fields=None):
+                 max_num_fields=None, separator=None):
         """Constructor.  Read multipart/* until last part.
 
         Arguments, all optional:
@@ -430,6 +433,7 @@ class FieldStorage:
         self.keep_blank_values = keep_blank_values
         self.strict_parsing = strict_parsing
         self.max_num_fields = max_num_fields
+        self.separator = separator
         if 'REQUEST_METHOD' in environ:
             method = environ['REQUEST_METHOD'].upper()
         self.qs_on_post = None
@@ -613,7 +617,8 @@ class FieldStorage:
         if self.qs_on_post:
             qs += '&' + self.qs_on_post
         query = urlparse.parse_qsl(qs, self.keep_blank_values,
-                                   self.strict_parsing, self.max_num_fields)
+                                   self.strict_parsing, self.max_num_fields,
+                                   self.separator)
         self.list = [MiniFieldStorage(key, value) for key, value in query]
         self.skip_lines()
 
@@ -629,7 +634,8 @@ class FieldStorage:
             query = urlparse.parse_qsl(self.qs_on_post,
                                        self.keep_blank_values,
                                        self.strict_parsing,
-                                       self.max_num_fields)
+                                       self.max_num_fields,
+                                       self.separator)
             self.list.extend(MiniFieldStorage(key, value)
                              for key, value in query)
             FieldStorageClass = None
@@ -649,7 +655,8 @@ class FieldStorage:
             headers = rfc822.Message(self.fp)
             part = klass(self.fp, headers, ib,
                          environ, keep_blank_values, strict_parsing,
-                         max_num_fields)
+                         max_num_fields,
+                         separator=self.separator)
 
             if max_num_fields is not None:
                 max_num_fields -= 1
@@ -817,10 +824,11 @@ class FormContentDict(UserDict.UserDict)
     form.dict == {key: [val, val, ...], ...}
 
     """
-    def __init__(self, environ=os.environ, keep_blank_values=0, strict_parsing=0):
+    def __init__(self, environ=os.environ, keep_blank_values=0, strict_parsing=0, separator=None):
         self.dict = self.data = parse(environ=environ,
                                       keep_blank_values=keep_blank_values,
-                                      strict_parsing=strict_parsing)
+                                      strict_parsing=strict_parsing,
+                                      separator=separator)
         self.query_string = environ['QUERY_STRING']
 
 
