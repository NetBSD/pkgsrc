$NetBSD: patch-src_mongo_db_matcher_expression__leaf.cpp,v 1.2 2019/03/05 19:35:58 adam Exp $

Fix building.

--- src/mongo/db/matcher/expression_leaf.cpp.orig	2019-01-30 14:26:33.000000000 +0000
+++ src/mongo/db/matcher/expression_leaf.cpp
@@ -33,6 +33,7 @@
 #include "mongo/db/matcher/expression_leaf.h"
 
 #include <cmath>
+#include <string>
 #include <pcrecpp.h>
 
 #include "mongo/bson/bsonelement_comparator.h"
@@ -48,6 +49,7 @@
 #include "mongo/util/mongoutils/str.h"
 
 namespace mongo {
+using std::string;
 
 ComparisonMatchExpressionBase::ComparisonMatchExpressionBase(
     MatchType type,
