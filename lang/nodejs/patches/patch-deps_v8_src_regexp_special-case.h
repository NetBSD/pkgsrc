$NetBSD: patch-deps_v8_src_regexp_special-case.h,v 1.1 2026/11/11 11:48:36 wiz Exp $

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

--- deps/v8/src/regexp/special-case.h.orig	2026-10-21 07:17:30.000000000 +0000
+++ deps/v8/src/regexp/special-case.h
@@ -7,8 +7,8 @@
 
 #ifdef V8_INTL_SUPPORT
 #include "src/base/logging.h"
+#include "src/base/strings.h"
 #include "src/common/globals.h"
-
 #include "unicode/uchar.h"
 #include "unicode/uniset.h"
 #include "unicode/unistr.h"
@@ -71,9 +71,17 @@ namespace internal {
 // another character. Characters that match no other characters in
 // their equivalence class are added to IgnoreSet. Characters that
 // match at least one other character are added to SpecialAddSet.
+// Supplementary code points are ignored throughout: non-unicode matching
+// compares UTF-16 code units, so they can never match a BMP character.
+//
+// The generator additionally emits SupplementaryEquivalentsSet, the BMP
+// characters whose Unicode case closure contains supplementary code points.
+// This set is used for unicode-mode matching, see HasSupplementaryEquivalents.
 
 class RegExpCaseFolding final : public AllStatic {
  public:
+  enum class Mode { kNonUnicode, kUnicode };
+
   static const icu::UnicodeSet& IgnoreSet();
   static const icu::UnicodeSet& SpecialAddSet();
 
@@ -107,6 +115,43 @@ class RegExpCaseFolding final : public AllStatic {
 
     // h. Return cu.
     return cu;
+  }
+
+  // Close a set of characters under case equivalence, preserving its
+  // original members. Non-unicode inputs must be UTF-16 code units.
+  static void CloseOver(icu::UnicodeSet& set, Mode mode) {
+    if (mode == Mode::kUnicode) {
+      set.closeOver(USET_SIMPLE_CASE_INSENSITIVE);
+      return;
+    }
+    DCHECK(!set.containsSome(0x10000, 0x10ffff));
+    if (IgnoreSet().containsNone(set)) {
+      CloseOverNonUnicode(set);
+      return;
+    }
+    if (IgnoreSet().containsAll(set)) return;
+    // Ignored characters neither contribute nor acquire equivalents, but
+    // must remain in the result if they were explicitly present.
+    icu::UnicodeSet ignored(set);
+    ignored.retainAll(IgnoreSet());
+    set.removeAll(IgnoreSet());
+    CloseOverNonUnicode(set);
+    set.addAll(ignored);
+  }
+
+  // Whether c has supplementary Unicode case equivalents.
+  static bool HasSupplementaryEquivalents(base::uc16 c) {
+    return SupplementaryEquivalentsSet().contains(c);
+  }
+
+ private:
+  static const icu::UnicodeSet& SupplementaryEquivalentsSet();
+
+  // Requires a set containing no IgnoreSet characters.
+  static void CloseOverNonUnicode(icu::UnicodeSet& set) {
+    set.closeOver(USET_SIMPLE_CASE_INSENSITIVE);
+    set.removeAll(IgnoreSet());
+    set.remove(0x10000, 0x10ffff);
   }
 };
 
