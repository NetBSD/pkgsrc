$NetBSD: patch-src_futils.cpp,v 1.5 2023/07/07 10:33:26 jperkin Exp $

Fix build on NetBSD.
https://github.com/Exiv2/exiv2/pull/2625

Include image_int.hpp for Internal::stringFormat().

--- src/futils.cpp.orig	2023-05-08 16:01:13.000000000 +0000
+++ src/futils.cpp
@@ -6,6 +6,7 @@
 #include "config.h"
 #include "enforce.hpp"
 #include "error.hpp"
+#include "image_int.hpp"
 #include "utils.hpp"
 
 // + standard includes
@@ -360,7 +361,7 @@ std::string getProcessPath() {
     TCHAR pathbuf[MAX_PATH];
     GetModuleFileName(nullptr, pathbuf, MAX_PATH);
     auto path = fs::path(pathbuf);
-#elif __has_include(<libproc.h>)
+#elif defined(PROC_PIDPATHINFO_MAXSIZE)
     char pathbuf[PROC_PIDPATHINFO_MAXSIZE];
     proc_pidpath(getpid(), pathbuf, sizeof(pathbuf));
     auto path = fs::path(pathbuf);
