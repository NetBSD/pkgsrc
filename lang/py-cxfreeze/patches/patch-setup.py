$NetBSD: patch-setup.py,v 1.2 2021/12/19 13:59:32 wiz Exp $

Link with proper run-time library path,
link with -lpthread on NetBSD.

--- setup.py.orig	2017-11-20 15:18:06.000000000 +0000
+++ setup.py
@@ -71,6 +71,7 @@ class build_ext(distutils.command.build_
         fileName = os.path.splitext(self.get_ext_filename(ext.name))[0]
         fullName = os.path.join(self.build_lib, fileName)
         libraryDirs = ext.library_dirs or []
+        runtimeLibraryDirs = ext.runtime_library_dirs or []
         libraries = self.get_libraries(ext)
         extraArgs = ext.extra_link_args or []
         if sys.platform == "win32":
@@ -96,10 +97,12 @@ class build_ext(distutils.command.build_
             if vars["LOCALMODLIBS"]:
                 extraArgs.extend(vars["LOCALMODLIBS"].split())
             extraArgs.append("-s")
+            runtimeLibraryDirs.append(sys.prefix + "/lib")
+            libraryDirs.append(sys.prefix + "/lib")
         self.compiler.link_executable(objects, fullName,
                 libraries = libraries,
                 library_dirs = libraryDirs,
-                runtime_library_dirs = ext.runtime_library_dirs,
+                runtime_library_dirs = runtimeLibraryDirs,
                 extra_postargs = extraArgs,
                 debug = self.debug)
 
@@ -136,7 +139,11 @@ if sys.platform == "win32":
 if sys.platform == "win32":
     libraries = ["imagehlp", "Shlwapi"]
 else:
-    libraries = []
+    if sys.platform.startswith('netbsd'):
+        libraries = ["pthread"]
+    else:
+        libraries = []
+
 utilModule = Extension("cx_Freeze.util", ["source/util.c"],
         libraries = libraries)
 
