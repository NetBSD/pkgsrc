$NetBSD: patch-setup.py,v 1.1 2013/12/28 02:53:47 obache Exp $

* prevent to detect optional tkinter

--- setup.py.orig	2013-10-02 04:07:08.000000000 +0000
+++ setup.py
@@ -75,10 +75,7 @@ def _lib_include(root):
 def _read(file):
     return open(file, 'rb').read()
 
-try:
-    import _tkinter
-except ImportError:
-    _tkinter = None
+_tkinter = None
 
 
 NAME = 'Pillow'
@@ -432,7 +429,7 @@ class pil_build_ext(build_ext):
             exts.append(Extension(
                 "PIL._webp", ["_webp.c"], libraries=libs, define_macros=defs))
 
-        if sys.platform == "darwin":
+        if _tkinter and sys.platform == "darwin":
             # locate Tcl/Tk frameworks
             frameworks = []
             framework_roots = [
@@ -598,7 +595,7 @@ setup(
     ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
     include_package_data=True,
     packages=find_packages(),
-    scripts=glob.glob("Scripts/pil*.py"),
+#    scripts=glob.glob("Scripts/pil*.py"),
     test_suite='PIL.tests',
     keywords=["Imaging",],
     license='Standard PIL License',
