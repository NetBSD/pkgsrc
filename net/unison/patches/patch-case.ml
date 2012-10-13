$NetBSD: patch-case.ml,v 1.1 2012/10/13 09:05:11 wiz Exp $

r511 | vouillon | 2012-09-17 16:09:03 +0200 (Mon, 17 Sep 2012) | 3 lines

* Use hash function from OCaml 3.x for comparing archives, even when
  compiled with OCaml 4.x

--- case.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ case.ml
@@ -140,7 +140,7 @@ let sensitiveOps = object
   method mode = Sensitive
   method modeDesc = "case sensitive"
   method compare s s' = compare (s : string) s'
-  method hash s = Hashtbl.hash s
+  method hash s = Uutil.hash s
   method normalizePattern s = s
   method caseInsensitiveMatch = false
   method normalizeMatchedString s = s
@@ -152,7 +152,7 @@ let insensitiveOps = object
   method mode = Insensitive
   method modeDesc = "Latin-1 case insensitive"
   method compare s s' = Util.nocase_cmp s s'
-  method hash s = Hashtbl.hash (String.lowercase s)
+  method hash s = Uutil.hash (String.lowercase s)
   method normalizePattern s = s
   method caseInsensitiveMatch = true
   method normalizeMatchedString s = s
@@ -164,7 +164,7 @@ let unicodeSensitiveOps = object
   method mode = UnicodeSensitive
   method modeDesc = "Unicode case sensitive"
   method compare s s' = Unicode.case_sensitive_compare s s'
-  method hash s = Hashtbl.hash (Unicode.decompose s)
+  method hash s = Uutil.hash (Unicode.decompose s)
   method normalizePattern p = Unicode.decompose p
   method caseInsensitiveMatch = false
   method normalizeMatchedString s = Unicode.decompose s
@@ -176,7 +176,7 @@ let unicodeInsensitiveOps = object
   method mode = UnicodeInsensitive
   method modeDesc = "Unicode case insensitive"
   method compare s s' = Unicode.case_insensitive_compare s s'
-  method hash s = Hashtbl.hash (Unicode.normalize s)
+  method hash s = Uutil.hash (Unicode.normalize s)
   method normalizePattern p = Unicode.normalize p
   method caseInsensitiveMatch = false
   method normalizeMatchedString s = Unicode.normalize s
