$NetBSD: patch-src_include_qrunner.h,v 1.3 2014/09/05 07:29:28 mef Exp $

Avoid implicit conversions to bool for streams.
Require C++11 for Clang and prefer std version over tr1 when in C++11
mode.

--- src/include/qrunner.h.orig	2013-05-03 14:32:45.000000000 +0000
+++ src/include/qrunner.h
@@ -32,6 +32,7 @@
 #include <cerrno>
 #include <stdexcept>
 #include <cstring>
+#include <string>
 
 #if HAVE_STD_BIND
 #   include <functional>
