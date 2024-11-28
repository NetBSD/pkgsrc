$NetBSD: patch-inst_include_Rcpp_exceptions.h,v 1.1 2024/11/28 15:12:01 bacon Exp $

# Unbreak build on macOS 15.0 aarch64

--- inst/include/Rcpp/exceptions.h.orig	2024-11-28 14:37:22.635316035 +0000
+++ inst/include/Rcpp/exceptions.h
@@ -114,7 +114,7 @@ namespace Rcpp {
         ::Rf_warning("%s", message.c_str());
     }                                                        // #nocov end
 
-    inline void NORET stop(const std::string& message) {     // #nocov start
+    NORET inline void stop(const std::string& message) {     // #nocov start
         throw Rcpp::exception(message.c_str());
     }                                                        // #nocov end
 
