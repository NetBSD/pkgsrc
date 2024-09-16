$NetBSD: patch-bindings_python_setup.py,v 1.4 2024/09/16 10:04:50 adam Exp $

--- bindings/python/setup.py.orig	2024-08-20 14:41:54.000000000 +0000
+++ bindings/python/setup.py
@@ -150,14 +150,6 @@ def build_libraries():
         else:
             os.system('cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON -DCAPSTONE_BUILD_TESTS=OFF -DCAPSTONE_BUILD_CSTOOL=OFF -G "Unix Makefiles" ..')
         os.system("cmake --build .")
-    else:  # Unix incl. cygwin
-        os.system("CAPSTONE_BUILD_CORE_ONLY=yes bash ./make.sh")
-
-    shutil.copy(VERSIONED_LIBRARY_FILE, os.path.join(LIBS_DIR, LIBRARY_FILE))
-
-    # only copy static library if it exists (it's a build option)
-    if STATIC_LIBRARY_FILE and os.path.exists(STATIC_LIBRARY_FILE):
-        shutil.copy(STATIC_LIBRARY_FILE, LIBS_DIR)
     os.chdir(cwd)
 
 
