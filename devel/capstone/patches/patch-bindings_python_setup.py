$NetBSD: patch-bindings_python_setup.py,v 1.5 2025/04/12 09:44:00 adam Exp $

--- bindings/python/setup.py.orig	2025-03-23 15:48:02.000000000 +0000
+++ bindings/python/setup.py
@@ -147,10 +147,6 @@ def build_libraries():
         else:
             os.system('cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON -DCAPSTONE_BUILD_TESTS=OFF -DCAPSTONE_BUILD_CSTOOL=OFF -G "Unix Makefiles" ..')
         os.system("cmake --build .")
-    else:  # Unix incl. cygwin
-        os.system("CAPSTONE_BUILD_CORE_ONLY=yes bash ./make.sh")
-
-    shutil.copy(VERSIONED_LIBRARY_FILE, os.path.join(LIBS_DIR, LIBRARY_FILE))
     os.chdir(cwd)
 
 
