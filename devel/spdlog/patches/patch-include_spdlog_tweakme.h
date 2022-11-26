$NetBSD: patch-include_spdlog_tweakme.h,v 1.1 2022/11/26 13:47:13 nia Exp $

Allow dependent programs to find the correct fmtlib headers.

--- include/spdlog/tweakme.h.orig	2022-11-02 21:13:08.000000000 +0000
+++ include/spdlog/tweakme.h
@@ -78,7 +78,7 @@
 // In this case spdlog will try to include <fmt/format.h> so set your -I flag
 // accordingly.
 //
-// #define SPDLOG_FMT_EXTERNAL
+#define SPDLOG_FMT_EXTERNAL
 ///////////////////////////////////////////////////////////////////////////////
 
 ///////////////////////////////////////////////////////////////////////////////
