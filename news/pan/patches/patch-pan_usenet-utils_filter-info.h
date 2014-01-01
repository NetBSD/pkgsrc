$NetBSD: patch-pan_usenet-utils_filter-info.h,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/usenet-utils/filter-info.h.orig	2013-12-21 12:30:49.000000000 +0000
+++ pan/usenet-utils/filter-info.h
@@ -55,7 +55,10 @@ namespace pan
     public:
       bool empty() const { return _type == TYPE_ERR; }
       FilterInfo () { clear(); }
-      virtual ~FilterInfo () { }
+      virtual ~FilterInfo () {
+        foreach (aggregatesp_t, _aggregates, it)
+          delete *it;
+      }
 
     public:
 
@@ -73,11 +76,11 @@ namespace pan
       TextMatch _text;
 
       /** Convenience typedef. */
-      typedef std::deque<FilterInfo> aggregates_t;
+      typedef std::deque<FilterInfo *> aggregatesp_t;
 
       /** When `_type' is AGGREGATE_OR or AGGREGATE_AND,
           these are the filters being or'ed or and'ed together. */
-      aggregates_t _aggregates;
+      aggregatesp_t _aggregates;
 
       /** When this is true, the results of the test should be negated. */
       bool _negate;
