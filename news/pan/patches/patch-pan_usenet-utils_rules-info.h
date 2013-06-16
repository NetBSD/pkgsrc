$NetBSD: patch-pan_usenet-utils_rules-info.h,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/usenet-utils/rules-info.h.orig	2013-06-16 10:35:10.000000000 +0000
+++ pan/usenet-utils/rules-info.h
@@ -50,15 +50,15 @@ namespace pan
       RulesType _type;
 
       bool empty() const { return _type == TYPE__ERR; }
-      RulesInfo () { clear(); }
-      virtual ~RulesInfo () { }
+      RulesInfo () : _aggregates(new aggregates_t) { clear(); }
+      virtual ~RulesInfo () { delete _aggregates; }
 
       /** Convenience typedef. */
       typedef std::deque<RulesInfo> aggregates_t;
 
       /** When `_type' is AGGREGATE_OR or AGGREGATE_AND,
           these are the filters being or'ed or and'ed together. */
-      aggregates_t _aggregates;
+      aggregates_t *_aggregates;
 
       /** When this is true, the results of the test should be negated. */
       bool _negate;
