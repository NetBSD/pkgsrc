$NetBSD: patch-dbxml_src_dbxml_Results.cpp,v 1.2 2012/03/11 20:26:57 markd Exp $

Fix build with gcc 4.6

--- src/dbxml/Results.cpp.orig	2009-12-22 13:17:00.000000000 +0000
+++ src/dbxml/Results.cpp
@@ -5,6 +5,7 @@
 //
 //
 
+#include <cstddef>
 #include <xqilla/simple-api/XQQuery.hpp>
 #include <xqilla/context/DynamicContext.hpp>
 #include <xqilla/context/impl/XQDynamicContextImpl.hpp>
