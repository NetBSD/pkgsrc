$NetBSD: patch-setup.py,v 1.4 2015/04/17 15:10:02 adam Exp $

* Prevent to detect optional tkinter.
* Disable demo programs.

--- setup.py.orig	2015-04-02 09:05:22.000000000 +0000
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
@@ -575,7 +571,7 @@ class pil_build_ext(build_ext):
             exts.append(Extension(
                 "PIL._webp", ["_webp.c"], libraries=libs, define_macros=defs))
 
-        if sys.platform == "darwin":
+        if _tkinter and sys.platform == "darwin":
             # locate Tcl/Tk frameworks
             frameworks = []
             framework_roots = [
@@ -753,7 +749,6 @@ setup(
     ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
     include_package_data=True,
     packages=find_packages(),
-    scripts=glob.glob("Scripts/pil*.py"),
     test_suite='nose.collector',
     keywords=["Imaging", ],
     license='Standard PIL License',
