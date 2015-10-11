$NetBSD: patch-src_include_qrunner.h,v 1.6 2015/10/11 03:59:56 mef Exp $

date: 2015-04-28 08:51:52 +0900;  author: joerg;  state: Exp;  lines: +2 -6;  commitid: 2iTQbBPEdUwBShjy;
Avoid implicit conversions to bool for streams.
Require C++11 for Clang and prefer std version over tr1 when in C++11
mode.

--- src/include/qrunner.h.orig	2015-04-27 23:31:20.000000000 +0000
+++ src/include/qrunner.h
@@ -32,6 +32,7 @@
 #include <cerrno>
 #include <stdexcept>
 #include <cstring>
+#include <string>
 
 #if HAVE_STD_BIND
 #   include <functional>
