$NetBSD: patch-bindings_python_setup.py,v 1.2 2020/08/18 20:20:46 riastradh Exp $

--- bindings/python/setup.py.orig	2020-05-08 10:03:30.000000000 +0000
+++ bindings/python/setup.py
@@ -140,14 +140,6 @@ def build_libraries():
         # Do not build tests & static library
         os.system('cmake -DCMAKE_BUILD_TYPE=RELEASE -DCAPSTONE_BUILD_TESTS=0 -DCAPSTONE_BUILD_STATIC=0 -G "NMake Makefiles" ..')
         os.system("nmake")
-    else:   # Unix incl. cygwin
-        os.system("CAPSTONE_BUILD_CORE_ONLY=yes bash ./make.sh")
-
-    shutil.copy(VERSIONED_LIBRARY_FILE, os.path.join(LIBS_DIR, LIBRARY_FILE))
-
-    # only copy static library if it exists (it's a build option)
-    if STATIC_LIBRARY_FILE and os.path.exists(STATIC_LIBRARY_FILE):
-        shutil.copy(STATIC_LIBRARY_FILE, LIBS_DIR)
     os.chdir(cwd)
 
 
