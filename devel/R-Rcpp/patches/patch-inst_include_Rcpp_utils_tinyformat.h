$NetBSD: patch-inst_include_Rcpp_utils_tinyformat.h,v 1.1 2024/11/28 15:12:01 bacon Exp $

# Unbreak build on macOS 15.0 aarch64

--- inst/include/Rcpp/utils/tinyformat.h.orig	2024-11-28 14:40:26.847508847 +0000
+++ inst/include/Rcpp/utils/tinyformat.h
@@ -24,7 +24,7 @@
 #define Rcpp_tinyformat_h
 
 namespace Rcpp {
-void stop(const std::string& message);
+NORET void stop(const std::string& message);
 }
 #define TINYFORMAT_ERROR(REASON) ::Rcpp::stop(REASON)
 
