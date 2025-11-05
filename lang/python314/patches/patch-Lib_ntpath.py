$NetBSD: patch-Lib_ntpath.py,v 1.1 2025/11/05 22:20:05 wiz Exp $

[3.14] gh-136065: Fix quadratic complexity in os.path.expandvars() (GH-134952) (GH-140844)
https://github.com/python/cpython/commit/631ba3407e3348ccd56ce5160c4fb2c5dc5f4d84

--- Lib/ntpath.py.orig	2025-10-07 09:34:52.000000000 +0000
+++ Lib/ntpath.py
@@ -400,17 +400,23 @@ def expanduser(path):
 # XXX With COMMAND.COM you can use any characters in a variable name,
 # XXX except '^|<>='.
 
+_varpattern = r"'[^']*'?|%(%|[^%]*%?)|\$(\$|[-\w]+|\{[^}]*\}?)"
+_varsub = None
+_varsubb = None
+
 def expandvars(path):
     """Expand shell variables of the forms $var, ${var} and %var%.
 
     Unknown variables are left unchanged."""
     path = os.fspath(path)
+    global _varsub, _varsubb
     if isinstance(path, bytes):
         if b'$' not in path and b'%' not in path:
             return path
-        import string
-        varchars = bytes(string.ascii_letters + string.digits + '_-', 'ascii')
-        quote = b'\''
+        if not _varsubb:
+            import re
+            _varsubb = re.compile(_varpattern.encode(), re.ASCII).sub
+        sub = _varsubb
         percent = b'%'
         brace = b'{'
         rbrace = b'}'
@@ -419,94 +425,44 @@ def expandvars(path):
     else:
         if '$' not in path and '%' not in path:
             return path
-        import string
-        varchars = string.ascii_letters + string.digits + '_-'
-        quote = '\''
+        if not _varsub:
+            import re
+            _varsub = re.compile(_varpattern, re.ASCII).sub
+        sub = _varsub
         percent = '%'
         brace = '{'
         rbrace = '}'
         dollar = '$'
         environ = os.environ
-    res = path[:0]
-    index = 0
-    pathlen = len(path)
-    while index < pathlen:
-        c = path[index:index+1]
-        if c == quote:   # no expansion within single quotes
-            path = path[index + 1:]
-            pathlen = len(path)
-            try:
-                index = path.index(c)
-                res += c + path[:index + 1]
-            except ValueError:
-                res += c + path
-                index = pathlen - 1
-        elif c == percent:  # variable or '%'
-            if path[index + 1:index + 2] == percent:
-                res += c
-                index += 1
-            else:
-                path = path[index+1:]
-                pathlen = len(path)
-                try:
-                    index = path.index(percent)
-                except ValueError:
-                    res += percent + path
-                    index = pathlen - 1
-                else:
-                    var = path[:index]
-                    try:
-                        if environ is None:
-                            value = os.fsencode(os.environ[os.fsdecode(var)])
-                        else:
-                            value = environ[var]
-                    except KeyError:
-                        value = percent + var + percent
-                    res += value
-        elif c == dollar:  # variable or '$$'
-            if path[index + 1:index + 2] == dollar:
-                res += c
-                index += 1
-            elif path[index + 1:index + 2] == brace:
-                path = path[index+2:]
-                pathlen = len(path)
-                try:
-                    index = path.index(rbrace)
-                except ValueError:
-                    res += dollar + brace + path
-                    index = pathlen - 1
-                else:
-                    var = path[:index]
-                    try:
-                        if environ is None:
-                            value = os.fsencode(os.environ[os.fsdecode(var)])
-                        else:
-                            value = environ[var]
-                    except KeyError:
-                        value = dollar + brace + var + rbrace
-                    res += value
-            else:
-                var = path[:0]
-                index += 1
-                c = path[index:index + 1]
-                while c and c in varchars:
-                    var += c
-                    index += 1
-                    c = path[index:index + 1]
-                try:
-                    if environ is None:
-                        value = os.fsencode(os.environ[os.fsdecode(var)])
-                    else:
-                        value = environ[var]
-                except KeyError:
-                    value = dollar + var
-                res += value
-                if c:
-                    index -= 1
+
+    def repl(m):
+        lastindex = m.lastindex
+        if lastindex is None:
+            return m[0]
+        name = m[lastindex]
+        if lastindex == 1:
+            if name == percent:
+                return name
+            if not name.endswith(percent):
+                return m[0]
+            name = name[:-1]
         else:
-            res += c
-        index += 1
-    return res
+            if name == dollar:
+                return name
+            if name.startswith(brace):
+                if not name.endswith(rbrace):
+                    return m[0]
+                name = name[1:-1]
+
+        try:
+            if environ is None:
+                return os.fsencode(os.environ[os.fsdecode(name)])
+            else:
+                return environ[name]
+        except KeyError:
+            return m[0]
+
+    return sub(repl, path)
 
 
 # Normalize a path, e.g. A//B, A/./B and A/foo/../B all become A\B.
