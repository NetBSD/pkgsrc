$NetBSD: patch-deps_v8_src_regexp_gen-regexp-special-case.cc,v 1.1 2026/11/11 11:48:36 wiz Exp $

From e455d955bd6b7a7549106d1b9d7ae5bb3b9e77b4 Mon Sep 17 00:00:00 2001
From: Jakob Linke <jgruber@chromium.org>
Date: Fri, 9 Oct 2026 12:41:30 +0200
Subject: [PATCH] [regexp] Handle supplementary case equivalents of BMP
 characters

Unicode 18 adds U+1DF95, which simple-folds to U+00DF. This creates the
first case-equivalence class spanning BMP and supplementary characters:
{U+00DF, U+1E9E, U+1DF95}.

Discard supplementary characters from the generator's non-unicode
closures before calling Canonicalize, which requires UTF-16 code units
and otherwise CHECK-fails with ICU 79. Apply the same filtering in
runtime non-unicode closure.

Generate SupplementaryEquivalentsSet and desugar its BMP characters into
character classes under /iu and /iv, allowing literals to match
surrogate pairs.

Backreferences with differing UTF-16 character widths remain unsupported
and are tracked in crbug.com/571793821.

IgnoreSet is unchanged with ICU 78 and with ICU 78.2 patched to upstream
Unicode 18 case data. With the patched data, the generator succeeds,
SupplementaryEquivalentsSet is {U+00DF, U+1E9E}, and regexp tests pass
in release and debug.

Bug: 571232615, 571668686
Change-Id: I9eacb273a74c66e17f0cfb1b256e863f2718c130
Reviewed-on: https://chromium-review.googlesource.com/c/v8/v8/+/8548134
Reviewed-by: Patrick Thier <pthier@chromium.org>
Commit-Queue: Jakob Linke <jgruber@chromium.org>
Cr-Commit-Position: refs/heads/main@{#110522}
---
 src/regexp/gen-regexp-special-case.cc | 18 ++++++++++
 src/regexp/regexp-parser.cc           | 18 +++++++---
 src/regexp/special-case.h             | 47 ++++++++++++++++++++++++++-
 3 files changed, 77 insertions(+), 6 deletions(-)

--- deps/v8/src/regexp/gen-regexp-special-case.cc.orig	2026-10-21 07:17:30.000000000 +0000
+++ deps/v8/src/regexp/gen-regexp-special-case.cc
@@ -9,6 +9,7 @@
 
 #include "src/base/strings.h"
 #include "src/regexp/special-case.h"
+#include "unicode/uchar.h"
 
 namespace v8 {
 namespace internal {
@@ -17,6 +18,19 @@ static const base::uc32 kNonBmpStart = 0x10000;
 static const base::uc32 kSurrogateEnd = 0xdfff;
 static const base::uc32 kNonBmpStart = 0x10000;
 
+// Removes supplementary code points from |set| and returns whether any were
+// present. Since Unicode 18, the case closure of a BMP character can contain
+// supplementary code points (U+1DF95 LATIN SMALL LIGATURE LONG S WITH
+// DESCENDER S case-folds to U+00DF LATIN SMALL LETTER SHARP S). Non-unicode
+// ignoreCase matching compares UTF-16 code units, so a supplementary code
+// point never matches a BMP character and does not take part in Canonicalize.
+bool RemoveSupplementary(icu::UnicodeSet& set) {
+  constexpr UChar32 kFirstSupplementary = static_cast<UChar32>(kNonBmpStart);
+  if (!set.containsSome(kFirstSupplementary, UCHAR_MAX_VALUE)) return false;
+  set.remove(kFirstSupplementary, UCHAR_MAX_VALUE);
+  return true;
+}
+
 // The following code generates "src/regexp/special-case.cc".
 void PrintSet(std::ofstream& out, const char* name,
               const icu::UnicodeSet& set) {
@@ -51,6 +65,7 @@ void PrintSpecial(std::ofstream& out) {
   icu::UnicodeSet current;
   icu::UnicodeSet special_add;
   icu::UnicodeSet ignore;
+  icu::UnicodeSet supplementary_equivalents;
   UErrorCode status = U_ZERO_ERROR;
   icu::UnicodeSet upper("[\\p{Lu}]", status);
   CHECK(U_SUCCESS(status));
@@ -63,6 +78,7 @@ void PrintSpecial(std::ofstream& out) {
     }
     current.set(i, i);
     current.closeOver(USET_CASE_INSENSITIVE);
+    if (RemoveSupplementary(current)) supplementary_equivalents.add(i);
 
     // Check to see if all characters in the case-folding equivalence
     // class as defined by UnicodeSet::closeOver all map to the same
@@ -112,6 +128,7 @@ void PrintSpecial(std::ofstream& out) {
       UChar32 canonical = RegExpCaseFolding::Canonicalize(c);
       current.set(c, c);
       current.closeOver(USET_CASE_INSENSITIVE);
+      RemoveSupplementary(current);
       current.removeAll(ignore);
       for (int32_t j = 0; j < current.getRangeCount(); j++) {
         for (UChar32 c2 = current.getRangeStart(j);
@@ -124,6 +141,7 @@ void PrintSpecial(std::ofstream& out) {
 
   PrintSet(out, "IgnoreSet", ignore);
   PrintSet(out, "SpecialAddSet", special_add);
+  PrintSet(out, "SupplementaryEquivalentsSet", supplementary_equivalents);
 }
 
 void WriteHeader(const char* header_filename) {
