$NetBSD: patch-src_main_cpp_stringhelper.cpp,v 1.1 2013/04/30 22:17:38 joerg Exp $

--- src/main/cpp/stringhelper.cpp.orig	2013-04-30 11:09:04.000000000 +0000
+++ src/main/cpp/stringhelper.cpp
@@ -28,6 +28,7 @@
 #endif
 #include <log4cxx/private/log4cxx_private.h>
 #include <cctype>
+#include <cstdlib>
 #include <apr.h>
 
 
