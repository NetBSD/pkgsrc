$NetBSD: patch-include_qpdf_QUtil.hh,v 1.2 2015/01/26 11:54:17 mef Exp $

Pull time.h to define time_t on FreeBSD.

--- include/qpdf/QUtil.hh.orig	2014-06-08 06:06:13.000000000 +0900
+++ include/qpdf/QUtil.hh	2015-01-26 20:47:22.000000000 +0900
@@ -14,6 +14,7 @@
 #include <list>
 #include <stdexcept>
 #include <stdio.h>
+#include <time.h>
 
 class RandomDataProvider;
 
