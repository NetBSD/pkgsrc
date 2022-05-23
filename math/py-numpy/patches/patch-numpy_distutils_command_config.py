$NetBSD: patch-numpy_distutils_command_config.py,v 1.1 2022/05/23 17:28:41 ryoon Exp $

* Workaround for undefined-sysbol errors from graphics/py-matplotlib.

--- numpy/distutils/command/config.py.orig	2022-05-17 10:56:58.000000000 +0000
+++ numpy/distutils/command/config.py
@@ -321,11 +321,7 @@ class config(old_config):
         # return a value.
         self._check_compiler()
         body = []
-        if decl:
-            if type(decl) == str:
-                body.append(decl)
-            else:
-                body.append("int %s (void);" % func)
+        body.append("int %s (void);" % func)
         # Handle MSVC intrinsics: force MS compiler to make a function call.
         # Useful to test for some functions when built with optimization on, to
         # avoid build error because the intrinsic and our 'fake' test
@@ -336,15 +332,16 @@ class config(old_config):
         body.append("int main (void) {")
         if call:
             if call_args is None:
+                body.append("  %s(%s);" % (func, call_args))
                 call_args = ''
-            body.append("  %s(%s);" % (func, call_args))
+            body.append("  %s();" % func)
         else:
             body.append("  %s;" % func)
         body.append("  return 0;")
         body.append("}")
         body = '\n'.join(body) + "\n"
 
-        return self.try_link(body, headers, include_dirs,
+        return self.try_link(body, None, include_dirs,
                              libraries, library_dirs)
 
     def check_funcs_once(self, funcs,
@@ -376,10 +373,8 @@ class config(old_config):
         """
         self._check_compiler()
         body = []
-        if decl:
-            for f, v in decl.items():
-                if v:
-                    body.append("int %s (void);" % f)
+        for f in funcs:
+            body.append("int %s (void);" % f)
 
         # Handle MS intrinsics. See check_func for more info.
         body.append("#ifdef _MSC_VER")
@@ -395,7 +390,7 @@ class config(old_config):
                         args = ''
                     else:
                         args = call_args[f]
-                    body.append("  %s(%s);" % (f, args))
+                    body.append("  %s();" % f)
                 else:
                     body.append("  %s;" % f)
         else:
@@ -405,7 +400,7 @@ class config(old_config):
         body.append("}")
         body = '\n'.join(body) + "\n"
 
-        return self.try_link(body, headers, include_dirs,
+        return self.try_link(body, None, include_dirs,
                              libraries, library_dirs)
 
     def check_inline(self):
