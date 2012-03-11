$NetBSD: patch-dbxml_src_dbxml_dataItem_Join.cpp,v 1.2 2012/03/11 20:26:57 markd Exp $

Fix build with gcc 4.6

--- src/dbxml/dataItem/Join.cpp.orig	2009-12-22 13:17:00.000000000 +0000
+++ src/dbxml/dataItem/Join.cpp
@@ -5,6 +5,7 @@
 //
 //
 
+#include <stddef.h>
 #include "Join.hpp"
 #include "DbXmlNodeImpl.hpp"
 
