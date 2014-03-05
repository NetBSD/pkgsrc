$NetBSD: patch-setup.py,v 1.1 2014/03/05 11:14:00 darcy Exp $

  * Fix when building against PostgreSQL < 9.0:
    http://shell.vex.net/viewvc.cgi/pygresql?view=revision&revision=517
    http://thread.gmane.org/gmane.comp.python.db.pygresql/1175

--- setup.py.orig	2013-01-08 14:47:33.000000000 +0000
+++ setup.py
@@ -68,6 +68,17 @@ def pg_config(s):
     return d
 
 
+def pg_version():
+    """Return the PostgreSQL version as a tuple of integers."""
+    parts = []
+    for part in pg_config('version').split()[-1].split('.'):
+        if part.isdigit():
+            part = int(part)
+        parts.append(part)
+    return tuple(parts or [8])
+
+
+pg_version = pg_version()
 py_modules = ['pg', 'pgdb']
 libraries = ['pq']
 # Make sure that the Python header files are searched before
@@ -95,7 +106,7 @@ class build_pg_ext(build_ext):
             "enable string escaping functions")]
 
     boolean_options = build_ext.boolean_options + [
-        'direct-access', 'large-objects', 'default-vars']
+        'direct-access', 'large-objects', 'default-vars', 'escaping-funcs']
 
     def get_compiler(self):
         """Return the C compiler used for building the extension."""
@@ -103,10 +114,10 @@ class build_pg_ext(build_ext):
 
     def initialize_options(self):
         build_ext.initialize_options(self)
-        self.direct_access = 1
-        self.large_objects = 1
-        self.default_vars = 1
-        self.escaping_funcs = 1
+        self.direct_access = True
+        self.large_objects = True
+        self.default_vars = True
+        self.escaping_funcs = pg_version[0] >= 9
 
     def finalize_options(self):
         """Set final values for all build_pg options."""
