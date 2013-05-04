$NetBSD: patch-include_cln_exception.h,v 1.1 2013/05/04 12:59:47 joerg Exp $

--- include/cln/exception.h.orig	2013-05-04 00:51:47.000000000 +0000
+++ include/cln/exception.h
@@ -4,6 +4,7 @@
 #define _CL_EXCEPTION_H
 
 #include <stdexcept>
+#include <string>
 
 namespace cln {
 
