$NetBSD: patch-src_futils.cpp,v 1.1 2023/05/16 20:25:00 wiz Exp $

Fix build on NetBSD.

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
