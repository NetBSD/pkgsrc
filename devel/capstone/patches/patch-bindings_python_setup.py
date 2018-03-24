$NetBSD: patch-bindings_python_setup.py,v 1.1 2018/03/24 17:10:42 joerg Exp $

--- bindings/python/setup.py.orig	2018-03-24 13:56:27.958002410 +0000
+++ bindings/python/setup.py
@@ -129,11 +129,9 @@ def build_libraries():
         # Do not build tests & static library
         os.system('cmake -DCMAKE_BUILD_TYPE=RELEASE -DCAPSTONE_BUILD_TESTS=0 -DCAPSTONE_BUILD_STATIC=0 -G "NMake Makefiles" ..')
         os.system("nmake")
-    else:   # Unix incl. cygwin
-        os.system("CAPSTONE_BUILD_CORE_ONLY=yes bash ./make.sh")
 
-    shutil.copy(LIBRARY_FILE, LIBS_DIR)
-    if STATIC_LIBRARY_FILE: shutil.copy(STATIC_LIBRARY_FILE, LIBS_DIR)
+    #shutil.copy(LIBRARY_FILE, LIBS_DIR)
+    #if STATIC_LIBRARY_FILE: shutil.copy(STATIC_LIBRARY_FILE, LIBS_DIR)
     os.chdir(cwd)
 
 
