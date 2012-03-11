$NetBSD: patch-dbxml_src_dbxml_dataItem_DbXmlPrintAST.cpp,v 1.2 2012/03/11 20:26:57 markd Exp $

Fix build with gcc 4.6

--- src/dbxml/dataItem/DbXmlPrintAST.cpp.orig	2009-12-22 13:17:00.000000000 +0000
+++ src/dbxml/dataItem/DbXmlPrintAST.cpp
@@ -7,6 +7,7 @@
 
 #include <iostream>
 #include <sstream>
+#include <cstddef>
 
 #include "DbXmlPrintAST.hpp"
 #include "UTF8.hpp"
