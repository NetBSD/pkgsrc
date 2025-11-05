$NetBSD: patch-Lib_posixpath.py,v 1.1 2025/11/05 22:20:05 wiz Exp $

[3.14] gh-136065: Fix quadratic complexity in os.path.expandvars() (GH-134952) (GH-140844)
https://github.com/python/cpython/commit/631ba3407e3348ccd56ce5160c4fb2c5dc5f4d84

--- Lib/posixpath.py.orig	2025-10-07 09:34:52.000000000 +0000
+++ Lib/posixpath.py
@@ -284,42 +284,41 @@ def expanduser(path):
 # This expands the forms $variable and ${variable} only.
 # Non-existent variables are left unchanged.
 
-_varprog = None
-_varprogb = None
+_varpattern = r'\$(\w+|\{[^}]*\}?)'
+_varsub = None
+_varsubb = None
 
 def expandvars(path):
     """Expand shell variables of form $var and ${var}.  Unknown variables
     are left unchanged."""
     path = os.fspath(path)
-    global _varprog, _varprogb
+    global _varsub, _varsubb
     if isinstance(path, bytes):
         if b'$' not in path:
             return path
-        if not _varprogb:
+        if not _varsubb:
             import re
-            _varprogb = re.compile(br'\$(\w+|\{[^}]*\})', re.ASCII)
-        search = _varprogb.search
+            _varsubb = re.compile(_varpattern.encode(), re.ASCII).sub
+        sub = _varsubb
         start = b'{'
         end = b'}'
         environ = getattr(os, 'environb', None)
     else:
         if '$' not in path:
             return path
-        if not _varprog:
+        if not _varsub:
             import re
-            _varprog = re.compile(r'\$(\w+|\{[^}]*\})', re.ASCII)
-        search = _varprog.search
+            _varsub = re.compile(_varpattern, re.ASCII).sub
+        sub = _varsub
         start = '{'
         end = '}'
         environ = os.environ
-    i = 0
-    while True:
-        m = search(path, i)
-        if not m:
-            break
-        i, j = m.span(0)
-        name = m.group(1)
-        if name.startswith(start) and name.endswith(end):
+
+    def repl(m):
+        name = m[1]
+        if name.startswith(start):
+            if not name.endswith(end):
+                return m[0]
             name = name[1:-1]
         try:
             if environ is None:
@@ -327,13 +326,11 @@ def expandvars(path):
             else:
                 value = environ[name]
         except KeyError:
-            i = j
+            return m[0]
         else:
-            tail = path[j:]
-            path = path[:i] + value
-            i = len(path)
-            path += tail
-    return path
+            return value
+
+    return sub(repl, path)
 
 
 # Normalize a path, e.g. A//B, A/./B and A/foo/../B all become A/B.
