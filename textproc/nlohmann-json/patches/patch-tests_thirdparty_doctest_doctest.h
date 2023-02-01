$NetBSD: patch-tests_thirdparty_doctest_doctest.h,v 1.1 2023/02/01 17:34:55 jperkin Exp $

Avoid ambiguous function call.

--- tests/thirdparty/doctest/doctest.h.orig	2022-08-12 13:06:06.000000000 +0000
+++ tests/thirdparty/doctest/doctest.h
@@ -5803,9 +5803,9 @@ namespace {
             separator_to_stream();
             s << std::dec;
 
-            auto totwidth = int(std::ceil(log10((std::max(p.numTestCasesPassingFilters, static_cast<unsigned>(p.numAsserts))) + 1)));
-            auto passwidth = int(std::ceil(log10((std::max(p.numTestCasesPassingFilters - p.numTestCasesFailed, static_cast<unsigned>(p.numAsserts - p.numAssertsFailed))) + 1)));
-            auto failwidth = int(std::ceil(log10((std::max(p.numTestCasesFailed, static_cast<unsigned>(p.numAssertsFailed))) + 1)));
+            auto totwidth = int(std::ceil(std::log10((std::max(p.numTestCasesPassingFilters, static_cast<unsigned>(p.numAsserts))) + 1)));
+            auto passwidth = int(std::ceil(std::log10((std::max(p.numTestCasesPassingFilters - p.numTestCasesFailed, static_cast<unsigned>(p.numAsserts - p.numAssertsFailed))) + 1)));
+            auto failwidth = int(std::ceil(std::log10((std::max(p.numTestCasesFailed, static_cast<unsigned>(p.numAssertsFailed))) + 1)));
             const bool anythingFailed = p.numTestCasesFailed > 0 || p.numAssertsFailed > 0;
             s << Color::Cyan << "[doctest] " << Color::None << "test cases: " << std::setw(totwidth)
               << p.numTestCasesPassingFilters << " | "
