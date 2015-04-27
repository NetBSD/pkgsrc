$NetBSD: patch-src_include_qrunner.h,v 1.5 2015/04/27 23:51:52 joerg Exp $

--- src/include/qrunner.h.orig	2015-04-27 23:31:20.000000000 +0000
+++ src/include/qrunner.h
@@ -32,6 +32,7 @@
 #include <cerrno>
 #include <stdexcept>
 #include <cstring>
+#include <string>
 
 #if HAVE_STD_BIND
 #   include <functional>
