$NetBSD: patch-src_wutil.cpp,v 1.1 2017/05/15 13:46:47 jperkin Exp $

SunOS needs an explicit size to getcwd().

--- src/wutil.cpp.orig	2017-02-03 01:46:58.000000000 +0000
+++ src/wutil.cpp
@@ -129,7 +129,11 @@ bool wreaddir_for_dirs(DIR *dir, wcstrin
 const wcstring wgetcwd() {
     wcstring retval;
 
+#ifdef __sun
+    char *res = getcwd(NULL, PATH_MAX);
+#else
     char *res = getcwd(NULL, 0);
+#endif
     if (res) {
         retval = str2wcstring(res);
         free(res);
