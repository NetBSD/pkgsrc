$NetBSD: patch-tinyxml_tinyxmlparser.cpp,v 1.1 2011/11/24 14:09:47 joerg Exp $

--- tinyxml/tinyxmlparser.cpp.orig	2011-11-24 00:44:44.000000000 +0000
+++ tinyxml/tinyxmlparser.cpp
@@ -24,6 +24,7 @@ distribution.
 
 #include "tinyxml.h"
 #include <ctype.h>
+#include <string.h>
 
 const char* TiXmlBase::SkipWhiteSpace( const char* p )
 {
