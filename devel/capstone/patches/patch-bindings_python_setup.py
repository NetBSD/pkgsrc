$NetBSD: patch-bindings_python_setup.py,v 1.3 2024/02/07 09:46:36 adam Exp $

--- bindings/python/setup.py.orig	2023-08-22 16:03:55.000000000 +0000
+++ bindings/python/setup.py
@@ -144,14 +144,6 @@ def build_libraries():
         # Only build capstone.dll
         os.system('cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON -DCAPSTONE_BUILD_TESTS=OFF -DCAPSTONE_BUILD_CSTOOL=OFF -G "NMake Makefiles" ..')
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
 
 
