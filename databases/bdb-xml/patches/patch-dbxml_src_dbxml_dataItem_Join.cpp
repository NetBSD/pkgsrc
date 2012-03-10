$NetBSD: patch-dbxml_src_dbxml_dataItem_Join.cpp,v 1.1 2012/03/10 20:18:03 markd Exp $

Fix build with gcc 4.6

--- dbxml/src/dbxml/dataItem/Join.cpp.orig	2009-12-22 13:17:00.000000000 +0000
+++ dbxml-2.5.16/dbxml/src/dbxml/dataItem/Join.cpp
@@ -5,6 +5,7 @@
 //
 //
 
+#include <stddef.h>
 #include "Join.hpp"
 #include "DbXmlNodeImpl.hpp"
 
