$NetBSD: patch-src_include_qrunner.h,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/include/qrunner.h.orig	2013-05-03 14:32:45.000000000 +0000
+++ src/include/qrunner.h
@@ -32,6 +32,7 @@
 #include <cerrno>
 #include <stdexcept>
 #include <cstring>
+#include <string>
 
 #if HAVE_STD_BIND
 #   include <functional>
