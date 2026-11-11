$NetBSD: patch-deps_v8_src_regexp_regexp-parser.cc,v 1.1 2026/11/11 11:48:36 wiz Exp $

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

--- deps/v8/src/regexp/regexp-parser.cc.orig	2026-10-20 19:59:14.000000000 +0000
+++ deps/v8/src/regexp/regexp-parser.cc
@@ -9,6 +9,7 @@
 #include "src/regexp/regexp-ast.h"
 #include "src/regexp/regexp-macro-assembler.h"
 #include "src/regexp/regexp.h"
+#include "src/regexp/special-case.h"
 #include "src/strings/char-predicates-inl.h"
 #include "src/utils/ostreams.h"
 #include "src/utils/utils.h"
@@ -241,12 +242,18 @@ bool RegExpTextBuilder::NeedsDesugaringForUnicode(RegE
   return false;
 }
 
+// Desugar supplementary characters with case equivalents and BMP characters
+// with supplementary equivalents. Other atoms are folded during code
+// generation.
 bool RegExpTextBuilder::NeedsDesugaringForIgnoreCase(base::uc32 c) {
 #ifdef V8_INTL_SUPPORT
   if (IsUnicodeMode() && ignore_case()) {
+    if (c <= unibrow::Utf16::kMaxNonSurrogateCharCode) {
+      return RegExpCaseFolding::HasSupplementaryEquivalents(
+          static_cast<base::uc16>(c));
+    }
     icu::UnicodeSet set(c, c);
-    set.closeOver(USET_CASE_INSENSITIVE);
-    set.removeAllStrings();
+    RegExpCaseFolding::CloseOver(set, RegExpCaseFolding::Mode::kUnicode);
     return set.size() > 1;
   }
   // In the case where ICU is not included, we act as if the unicode flag is
