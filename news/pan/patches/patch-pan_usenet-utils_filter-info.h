$NetBSD: patch-pan_usenet-utils_filter-info.h,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/usenet-utils/filter-info.h.orig	2013-06-16 10:36:39.000000000 +0000
+++ pan/usenet-utils/filter-info.h
@@ -54,8 +54,8 @@ namespace pan
 
     public:
       bool empty() const { return _type == TYPE_ERR; }
-      FilterInfo () { clear(); }
-      virtual ~FilterInfo () { }
+      FilterInfo () : _aggregates(new aggregates_t) { clear(); }
+      virtual ~FilterInfo () { delete _aggregates; }
 
     public:
 
@@ -77,7 +77,7 @@ namespace pan
 
       /** When `_type' is AGGREGATE_OR or AGGREGATE_AND,
           these are the filters being or'ed or and'ed together. */
-      aggregates_t _aggregates;
+      aggregates_t *_aggregates;
 
       /** When this is true, the results of the test should be negated. */
       bool _negate;
