$NetBSD: patch-src_cre2.cpp,v 1.2 2016/10/17 14:06:39 mef Exp $

Don't depend on GCC's VLA of non-POD types extensions.

--- src/cre2.cpp.orig	2016-03-28 17:32:57.445282715 +0000
+++ src/cre2.cpp
@@ -17,6 +17,7 @@
 
 #include <cstdlib>
 #include <cstdio>
+#include <vector>
 
 
 /** --------------------------------------------------------------------
@@ -201,7 +202,7 @@ cre2_match (const cre2_regexp_t *re , co
 	    cre2_string_t *match, int nmatch)
 {
   re2::StringPiece	text_re2(text, textlen);
-  re2::StringPiece	match_re2[nmatch];
+  std::vector<re2::StringPiece> match_re2(nmatch);
   RE2::Anchor		anchor_re2 = RE2::UNANCHORED;
   bool			retval; // 0 for no match
                                 // 1 for successful matching
@@ -215,7 +216,7 @@ cre2_match (const cre2_regexp_t *re , co
   case CRE2_UNANCHORED:
     break;
   }
-  retval = TO_CONST_RE2(re)->Match(text_re2, startpos, endpos, anchor_re2, match_re2, nmatch);
+  retval = TO_CONST_RE2(re)->Match(text_re2, startpos, endpos, anchor_re2, match_re2.data(), nmatch);
   if (retval) {
     for (int i=0; i<nmatch; i++) {
       match[i].data   = match_re2[i].data();
@@ -272,15 +273,15 @@ cre2_strings_to_ranges (const char * tex
 	cre2_string_t * match, int nmatch)			\
   {								\
     re2::StringPiece	input(text->data, text->length);	\
-    re2::StringPiece	strv[nmatch];				\
-    RE2::Arg		argv[nmatch];				\
-    RE2::Arg *		args[nmatch];				\
+    std::vector<re2::StringPiece> strv(nmatch);			\
+    std::vector<RE2::Arg> argv(nmatch);				\
+    std::vector<RE2::Arg *> args(nmatch);			\
     bool			retval;				\
     for (int i=0; i<nmatch; ++i) {				\
       argv[i] = &strv[i];					\
       args[i] = &argv[i];					\
     }								\
-    retval = RE2::FUN(input, pattern, args, nmatch);		\
+    retval = RE2::FUN(input, pattern, args.data(), nmatch);	\
     if (retval) {						\
       for (int i=0; i<nmatch; ++i) {				\
 	match[i].data   = strv[i].data();			\
@@ -301,15 +302,15 @@ DEFINE_MATCH_ZSTRING_FUN(cre2_partial_ma
 	cre2_string_t * match, int nmatch)			\
   {								\
     re2::StringPiece	input(text->data, text->length);	\
-    re2::StringPiece	strv[nmatch];				\
-    RE2::Arg		argv[nmatch];				\
-    RE2::Arg *		args[nmatch];				\
+    std::vector<re2::StringPiece> strv(nmatch);			\
+    std::vector<RE2::Arg> argv(nmatch);				\
+    std::vector<RE2::Arg *> args(nmatch);			\
     bool			retval;				\
     for (int i=0; i<nmatch; ++i) {				\
       argv[i] = &strv[i];					\
       args[i] = &argv[i];					\
     }								\
-    retval = RE2::FUN(&input, pattern, args, nmatch);		\
+    retval = RE2::FUN(&input, pattern, args.data(), nmatch);	\
     if (retval) {						\
       text->data   = input.data();				\
       text->length = input.length();				\
@@ -335,15 +336,15 @@ DEFINE_MATCH_ZSTRING_FUN2(cre2_find_and_
 	cre2_string_t * match, int nmatch)			\
   {								\
     re2::StringPiece	input(text->data, text->length);	\
-    re2::StringPiece	strv[nmatch];				\
-    RE2::Arg		argv[nmatch];				\
-    RE2::Arg *		args[nmatch];				\
+    std::vector<re2::StringPiece> strv(nmatch);			\
+    std::vector<RE2::Arg> argv(nmatch);				\
+    std::vector<RE2::Arg *> args(nmatch);			\
     bool			retval;				\
     for (int i=0; i<nmatch; ++i) {				\
       argv[i] = &strv[i];					\
       args[i] = &argv[i];					\
     }								\
-    retval = RE2::FUN(input, *TO_RE2(rex), args, nmatch);	\
+    retval = RE2::FUN(input, *TO_RE2(rex), args.data(), nmatch);	\
     if (retval) {						\
       for (int i=0; i<nmatch; ++i) {				\
 	match[i].data   = strv[i].data();			\
@@ -364,15 +365,15 @@ DEFINE_MATCH_REX_FUN(cre2_partial_match_
 	cre2_string_t * match, int nmatch)			\
   {								\
     re2::StringPiece	input(text->data, text->length);	\
-    re2::StringPiece	strv[nmatch];				\
-    RE2::Arg		argv[nmatch];				\
-    RE2::Arg *		args[nmatch];				\
+    std::vector<re2::StringPiece> strv(nmatch);			\
+    std::vector<RE2::Arg> argv(nmatch);				\
+    std::vector<RE2::Arg *> args(nmatch);			\
     bool			retval;				\
     for (int i=0; i<nmatch; ++i) {				\
       argv[i] = &strv[i];					\
       args[i] = &argv[i];					\
     }								\
-    retval = RE2::FUN(&input, *TO_RE2(rex), args, nmatch);	\
+    retval = RE2::FUN(&input, *TO_RE2(rex), args.data(), nmatch);	\
     if (retval) {						\
       text->data   = input.data();				\
       text->length = input.length();				\
