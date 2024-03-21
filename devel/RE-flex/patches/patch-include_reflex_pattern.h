$NetBSD: patch-include_reflex_pattern.h,v 1.1 2024/03/21 20:44:40 wiz Exp $

fix doxygen errors

--- include/reflex/pattern.h.orig	2024-03-17 18:07:40.405467527 +0000
+++ include/reflex/pattern.h
@@ -501,7 +501,7 @@ class Pattern {
     static const value_type NEGATE  = 1ULL << 51; ///< marks negative patterns
     static const value_type TICKED  = 1ULL << 52; ///< marks lookahead ending ) in (?=X)
     static const value_type RES4    = 1ULL << 53; ///< reserved
-    static const value_type ANCHOR  = 1ULL << 54; ///< marks begin of word (\b,\<,\>) and buffer (\A,^) anchors
+    static const value_type ANCHOR  = 1ULL << 54; ///< marks begin of word (`\b`,`\<`,`\>`) and buffer (`\A`,`^`) anchors
     static const value_type ACCEPT  = 1ULL << 55; ///< accept, not a regex position
     Position()                   : k(NPOS) { }
     Position(value_type k)       : k(k)    { }
