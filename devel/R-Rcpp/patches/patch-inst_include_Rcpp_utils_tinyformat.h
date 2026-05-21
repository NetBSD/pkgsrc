$NetBSD: patch-inst_include_Rcpp_utils_tinyformat.h,v 1.2 2026/05/21 09:11:08 mef Exp $

# Unbreak build on macOS 15.0 aarch64

--- inst/include/Rcpp/utils/tinyformat.h.orig	2025-03-27 00:52:25.000000000 +0900
+++ inst/include/Rcpp/utils/tinyformat.h	2026-05-20 21:38:09.662841895 +0900
@@ -24,7 +24,7 @@
 #define Rcpp_tinyformat_h
 
 namespace Rcpp {
-void stop(const std::string& message);
+NORET void stop(const std::string& message);
 }
 #define TINYFORMAT_ERROR(REASON) ::Rcpp::stop(REASON)
 #define TINYFORMAT_USE_VARIADIC_TEMPLATES
