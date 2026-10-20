$NetBSD: patch-lib_utils_mu-utils.cc,v 1.4 2026/10/20 18:38:35 ktnb Exp $

GCC12 doesn't like constexpr but is okay with inline

--- lib/utils/mu-utils.cc.orig	2026-10-20 18:25:58.322604804 +0000
+++ lib/utils/mu-utils.cc
@@ -211,7 +211,7 @@ namespace {
 // Break text into space-separated words, mimicking Xapian's
 // TermGenerator
 
-constexpr bool is_wordchar(gunichar uc)
+inline bool is_wordchar(gunichar uc)
 {
 	return g_unichar_isalnum(uc) || g_unichar_ismark(uc) || uc == '_';
 }
