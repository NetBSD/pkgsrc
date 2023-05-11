$NetBSD: patch-src_api_python_setup.py,v 1.1 2023/05/11 06:43:43 adam Exp $

Some platforms do not support LTO.

--- src/api/python/setup.py.orig	2023-05-10 16:39:33.324575995 +0000
+++ src/api/python/setup.py
@@ -110,7 +110,7 @@ def _configure_z3():
         'CMAKE_BUILD_TYPE' : 'Release',
         'Z3_BUILD_EXECUTABLE' : True,
         'Z3_BUILD_LIBZ3_SHARED' : True,
-        'Z3_LINK_TIME_OPTIMIZATION' : True,
+        'Z3_LINK_TIME_OPTIMIZATION' : False,
         'WARNINGS_AS_ERRORS' : 'SERIOUS_ONLY',
         # Disable Unwanted Options
         'Z3_USE_LIB_GMP' : False, # Is default false in python build
