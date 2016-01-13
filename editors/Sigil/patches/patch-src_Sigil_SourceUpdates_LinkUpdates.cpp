$NetBSD: patch-src_Sigil_SourceUpdates_LinkUpdates.cpp,v 1.1 2016/01/13 23:55:42 joerg Exp $

--- src/Sigil/SourceUpdates/LinkUpdates.cpp.orig	2016-01-12 20:31:45.000000000 +0000
+++ src/Sigil/SourceUpdates/LinkUpdates.cpp
@@ -34,6 +34,7 @@
 #include "SourceUpdates/LinkUpdates.h"
 
 using boost::shared_ptr;
+using namespace boost::placeholders;
 
 static QString HTML_XML_NAMESPACE = "http://www.w3.org/1999/xhtml";
 
