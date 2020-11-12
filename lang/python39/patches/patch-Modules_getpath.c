$NetBSD: patch-Modules_getpath.c,v 1.1 2020/11/12 10:58:21 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Backported from:
https://github.com/python/cpython/pull/22855

--- Modules/getpath.c.orig	2020-10-05 15:07:58.000000000 +0000
+++ Modules/getpath.c
@@ -923,11 +923,7 @@ static PyStatus
 calculate_program_macos(wchar_t **abs_path_p)
 {
     char execpath[MAXPATHLEN + 1];
-#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_4
     uint32_t nsexeclength = Py_ARRAY_LENGTH(execpath) - 1;
-#else
-    unsigned long nsexeclength = Py_ARRAY_LENGTH(execpath) - 1;
-#endif
 
     /* On Mac OS X, if a script uses an interpreter of the form
        "#!/opt/python2.3/bin/python", the kernel only passes "python"
