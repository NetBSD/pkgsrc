$NetBSD: patch-dbxml_src_dbxml_dataItem_DbXmlConfiguration.cpp,v 1.2 2012/03/11 20:26:57 markd Exp $

Fix build with gcc 4.6

--- src/dbxml/dataItem/DbXmlConfiguration.cpp.orig	2009-12-22 13:17:00.000000000 +0000
+++ src/dbxml/dataItem/DbXmlConfiguration.cpp
@@ -5,6 +5,7 @@
 //
 //
 
+#include <stddef.h>
 #include "DbXmlConfiguration.hpp"
 #include "DbXmlFactoryImpl.hpp"
 #include "DbXmlSequenceBuilder.hpp"
