$NetBSD: patch-src_lookup_pinyin__lookup2.cpp,v 1.1 2014/07/14 08:12:04 obache Exp $

* resolve ambiguos usage of log(3), lookup_value_t expect gfloat.

--- src/lookup/pinyin_lookup2.cpp.orig	2013-06-18 05:56:09.000000000 +0000
+++ src/lookup/pinyin_lookup2.cpp
@@ -133,7 +133,7 @@ static bool populate_prefixes(GPtrArray 
     for (size_t i = 0; i < prefixes->len; ++i) {
         phrase_token_t token = g_array_index(prefixes, phrase_token_t, i);
         lookup_key_t initial_key = token;
-        lookup_value_t initial_value(log(1));
+        lookup_value_t initial_value(log((gfloat)1));
         initial_value.m_handles[1] = token;
 
         LookupStepContent initial_step_content = (LookupStepContent)
