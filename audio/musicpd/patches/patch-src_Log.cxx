$NetBSD: patch-src_Log.cxx,v 1.1 2024/07/15 10:06:15 adam Exp $

Fix build with fmtlib 11.

--- src/Log.cxx.orig	2024-07-15 09:58:53.526175404 +0000
+++ src/Log.cxx
@@ -21,6 +21,7 @@
 #include "lib/fmt/ExceptionFormatter.hxx"
 #include "util/Domain.hxx"
 
+#include <iterator>
 #include <fmt/format.h>
 
 static constexpr Domain exception_domain("exception");
