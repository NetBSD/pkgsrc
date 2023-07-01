$NetBSD: patch-src_futils.cpp,v 1.4 2023/07/01 22:13:15 wiz Exp $

Fix build on NetBSD.
https://github.com/Exiv2/exiv2/pull/2625

--- src/futils.cpp.orig	2023-05-08 16:01:13.000000000 +0000
+++ src/futils.cpp
@@ -360,7 +360,7 @@ std::string getProcessPath() {
     TCHAR pathbuf[MAX_PATH];
     GetModuleFileName(nullptr, pathbuf, MAX_PATH);
     auto path = fs::path(pathbuf);
-#elif __has_include(<libproc.h>)
+#elif defined(PROC_PIDPATHINFO_MAXSIZE)
     char pathbuf[PROC_PIDPATHINFO_MAXSIZE];
     proc_pidpath(getpid(), pathbuf, sizeof(pathbuf));
     auto path = fs::path(pathbuf);
