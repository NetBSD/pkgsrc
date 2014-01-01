$NetBSD: patch-pan_usenet-utils_rules-info.h,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/usenet-utils/rules-info.h.orig	2013-12-21 12:31:57.000000000 +0000
+++ pan/usenet-utils/rules-info.h
@@ -54,11 +54,11 @@ namespace pan
       virtual ~RulesInfo () { }
 
       /** Convenience typedef. */
-      typedef std::deque<RulesInfo> aggregates_t;
+      typedef std::deque<RulesInfo *> aggregatesp_t;
 
       /** When `_type' is AGGREGATE_OR or AGGREGATE_AND,
           these are the filters being or'ed or and'ed together. */
-      aggregates_t _aggregates;
+      aggregatesp_t _aggregates;
 
       /** When this is true, the results of the test should be negated. */
       bool _negate;
