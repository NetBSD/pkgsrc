$NetBSD: patch-pyproj___datadir.pyx,v 1.1 2023/11/23 11:23:07 wiz Exp $

Fix build with Cython 3.

--- pyproj/_datadir.pyx.orig	2021-09-16 00:54:55.000000000 +0000
+++ pyproj/_datadir.pyx
@@ -6,7 +6,7 @@ from libc.stdlib cimport free, malloc
 
 from pyproj._compat cimport cstrencode
 
-from pyproj.exceptions import DataDirError, ProjError
+from pyproj.exceptions import ProjError
 from pyproj.utils import strtobool
 
 # for logging the internal PROJ messages
@@ -90,7 +90,7 @@ def get_user_data_dir(create=False):
     )
 
 
-cdef void pyproj_log_function(void *user_data, int level, const char *error_msg) nogil:
+cdef void pyproj_log_function(void *user_data, int level, const char *error_msg) nogil noexcept:
     """
     Log function for catching PROJ errors.
     """
