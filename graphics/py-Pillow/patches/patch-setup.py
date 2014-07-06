$NetBSD: patch-setup.py,v 1.3 2014/07/06 12:15:53 obache Exp $

* Prevent to detect optional tkinter.
* Disable demo programs.

--- setup.py.orig	2014-06-30 22:42:26.000000000 +0000
+++ setup.py
@@ -82,11 +82,7 @@ def _lib_include(root):
 def _read(file):
     return open(file, 'rb').read()
 
-try:
-    import _tkinter
-except (ImportError, OSError):
-    # pypy emits an oserror
-    _tkinter = None
+_tkinter = None
 
 
 NAME = 'Pillow'
@@ -570,7 +566,7 @@ class pil_build_ext(build_ext):
             exts.append(Extension(
                 "PIL._webp", ["_webp.c"], libraries=libs, define_macros=defs))
 
-        if sys.platform == "darwin":
+        if _tkinter and sys.platform == "darwin":
             # locate Tcl/Tk frameworks
             frameworks = []
             framework_roots = [
@@ -746,7 +742,7 @@ setup(
     ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
     include_package_data=True,
     packages=find_packages(),
-    scripts=glob.glob("Scripts/pil*.py"),
+#    scripts=glob.glob("Scripts/pil*.py"),
     test_suite='PIL.tests',
     keywords=["Imaging", ],
     license='Standard PIL License',
