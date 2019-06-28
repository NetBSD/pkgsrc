$NetBSD: patch-src_mongo_db_matcher_expression__leaf.cpp,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/mongo/db/matcher/expression_leaf.cpp.orig	2017-07-11 17:17:17.311043545 +0000
+++ src/mongo/db/matcher/expression_leaf.cpp
@@ -31,6 +31,7 @@
 #include "mongo/db/matcher/expression_leaf.h"
 
 #include <cmath>
+#include <string>
 #include <pcrecpp.h>
 
 #include "mongo/bson/bsonelement_comparator.h"
@@ -45,6 +46,7 @@
 #include "mongo/util/mongoutils/str.h"
 
 namespace mongo {
+using std::string;
 
 Status LeafMatchExpression::setPath(StringData path) {
     _path = path;
