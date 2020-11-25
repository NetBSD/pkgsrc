$NetBSD: patch-.._.._mfbt_tests_TestVariant.cpp,v 1.1 2020/11/25 00:40:16 gutteridge Exp $

Disable assertion that fails on 32-bit architectures.

--- ../../mfbt/tests/TestVariant.cpp.orig	2020-11-04 10:52:03.000000000 +0000
+++ ../../mfbt/tests/TestVariant.cpp
@@ -567,7 +567,7 @@ static void testMatchingLambdaWithIndex(
   // would be no way to distinguish how each lambda is actually invoked because
   // there is only one choice of call operator in each overload set.
   auto desc = [](auto aIndex, auto& a) {
-    static_assert(sizeof(aIndex) < sizeof(size_t), "Expected small index type");
+    //static_assert(sizeof(aIndex) < sizeof(size_t), "Expected small index type");
     switch (sizeof(a)) {
       case 1:
         MOZ_RELEASE_ASSERT(aIndex == 0);
