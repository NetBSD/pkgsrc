$NetBSD: patch-src_Sigil_SourceUpdates_UniversalUpdates.cpp,v 1.1 2016/01/13 23:55:42 joerg Exp $

--- src/Sigil/SourceUpdates/UniversalUpdates.cpp.orig	2016-01-12 20:32:59.000000000 +0000
+++ src/Sigil/SourceUpdates/UniversalUpdates.cpp
@@ -47,6 +47,7 @@
 #include "SourceUpdates/UniversalUpdates.h"
 
 using boost::make_tuple;
+using namespace boost::placeholders;
 using boost::shared_ptr;
 using boost::tie;
 using boost::tuple;
