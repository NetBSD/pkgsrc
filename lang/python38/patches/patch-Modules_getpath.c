$NetBSD: patch-Modules_getpath.c,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Modules/getpath.c.orig	2020-09-23 12:36:32.000000000 +0000
+++ Modules/getpath.c
@@ -777,11 +777,7 @@ calculate_program_full_path(PyCalculateP
 
 #ifdef __APPLE__
     char execpath[MAXPATHLEN + 1];
-#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_4
     uint32_t nsexeclength = Py_ARRAY_LENGTH(execpath) - 1;
-#else
-    unsigned long nsexeclength = Py_ARRAY_LENGTH(execpath) - 1;
-#endif
 #endif
 
     /* If there is no slash in the argv0 path, then we have to
