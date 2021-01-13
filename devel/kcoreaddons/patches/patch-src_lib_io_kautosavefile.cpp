$NetBSD: patch-src_lib_io_kautosavefile.cpp,v 1.1 2021/01/13 10:47:05 jperkin Exp $

NAME_MAX compat.

--- src/lib/io/kautosavefile.cpp.orig	2020-05-02 22:16:16.000000000 +0000
+++ src/lib/io/kautosavefile.cpp
@@ -15,6 +15,9 @@
 #include <stdlib.h> // for _MAX_FNAME
 static const int maxNameLength = _MAX_FNAME;
 #else
+#ifndef NAME_MAX
+#define NAME_MAX PATH_MAX
+#endif
 static const int maxNameLength = NAME_MAX;
 #endif
 
