$NetBSD: patch-src_lookup_phrase__lookup.cpp,v 1.1 2014/07/12 12:11:12 obache Exp $

* resolve ambiguos usage of log(3), lookup_value_t expect gfloat.

--- src/lookup/phrase_lookup.cpp.orig	2013-06-18 05:56:09.000000000 +0000
+++ src/lookup/phrase_lookup.cpp
@@ -39,7 +39,7 @@ static bool populate_prefixes(GPtrArray 
                               GPtrArray * steps_content) {
 
     lookup_key_t initial_key = sentence_start;
-    lookup_value_t initial_value(log(1));
+    lookup_value_t initial_value(log((gfloat)1));
     initial_value.m_handles[1] = sentence_start;
 
     LookupStepContent initial_step_content = (LookupStepContent)
