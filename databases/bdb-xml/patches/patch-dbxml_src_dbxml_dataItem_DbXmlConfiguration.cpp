$NetBSD: patch-dbxml_src_dbxml_dataItem_DbXmlConfiguration.cpp,v 1.1 2012/03/10 20:18:03 markd Exp $

Fix build with gcc 4.6

--- dbxml/src/dbxml/dataItem/DbXmlConfiguration.cpp.orig	2009-12-22 13:17:00.000000000 +0000
+++ dbxml/src/dbxml/dataItem/DbXmlConfiguration.cpp
@@ -5,6 +5,7 @@
 //
 //
 
+#include <stddef.h>
 #include "DbXmlConfiguration.hpp"
 #include "DbXmlFactoryImpl.hpp"
 #include "DbXmlSequenceBuilder.hpp"
