$NetBSD: patch-include_qpdf_QUtil.hh,v 1.1 2014/04/17 21:37:55 asau Exp $

--- include/qpdf/QUtil.hh.orig	2013-10-18 17:51:30.000000000 +0000
+++ include/qpdf/QUtil.hh
@@ -14,6 +14,7 @@
 #include <list>
 #include <stdexcept>
 #include <stdio.h>
+#include <time.h>
 
 namespace QUtil
 {
