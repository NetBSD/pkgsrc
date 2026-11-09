$NetBSD: patch-include_fmt_format.h,v 1.1 2026/11/09 17:39:42 tsutsui Exp $

- pull upstream fix for uint128_t bitwise not
 https://github.com/fmtlib/fmt/pull/4813
 https://github.com/fmtlib/fmt/commit/588b3a0f8f6a8bcf2a959cae882d5b2703e86737

--- include/fmt/format.h.orig	2026-11-08 16:03:05.306707509 +0000
+++ include/fmt/format.h
@@ -327,6 +327,9 @@ class uint128 {
       -> uint128 {
     return {lhs.hi_ & rhs.hi_, lhs.lo_ & rhs.lo_};
   }
+  friend constexpr auto operator~(const uint128& n) -> uint128 {
+    return {~n.hi_, ~n.lo_};
+  }
   friend FMT_CONSTEXPR auto operator+(const uint128& lhs, const uint128& rhs)
       -> uint128 {
     auto result = uint128(lhs);
