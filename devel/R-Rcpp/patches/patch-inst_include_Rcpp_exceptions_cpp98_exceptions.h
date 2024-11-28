$NetBSD: patch-inst_include_Rcpp_exceptions_cpp98_exceptions.h,v 1.1 2024/11/28 15:12:01 bacon Exp $

# Unbreak build on macOS 15.0 aarch64

--- inst/include/Rcpp/exceptions/cpp98/exceptions.h.orig	2024-11-28 14:39:28.908549027 +0000
+++ inst/include/Rcpp/exceptions/cpp98/exceptions.h
@@ -123,7 +123,7 @@ inline void warning(const char* fmt, con
 // -- Start Rcpp::stop declaration
 
 template <typename T1>
-inline void NORET stop(const char* fmt, const T1& arg1) {
+NORET inline void stop(const char* fmt, const T1& arg1) {
     throw Rcpp::exception(tfm::format(fmt, arg1).c_str());
 }
 
