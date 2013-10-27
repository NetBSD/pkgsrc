$NetBSD: patch-include_qpdf_QPDFExc.hh,v 1.3 2013/10/27 21:52:53 joerg Exp $

--- include/qpdf/QPDFExc.hh.orig	2013-10-27 21:38:44.000000000 +0000
+++ include/qpdf/QPDFExc.hh
@@ -13,6 +13,7 @@
 
 #include <qpdf/Constants.h>
 #include <stdexcept>
+#include <string>
 
 class QPDFExc: public std::runtime_error
 {
