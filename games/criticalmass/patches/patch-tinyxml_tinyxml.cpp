$NetBSD: patch-tinyxml_tinyxml.cpp,v 1.1 2011/11/24 14:09:47 joerg Exp $

--- tinyxml/tinyxml.cpp.orig	2011-11-24 00:44:05.000000000 +0000
+++ tinyxml/tinyxml.cpp
@@ -22,6 +22,8 @@ distribution.
 */
 
 #include "tinyxml.h"
+#include <stdlib.h>
+#include <string.h>
 
 
 TiXmlNode::TiXmlNode( NodeType _type )
