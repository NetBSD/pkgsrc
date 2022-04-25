$NetBSD: patch-tests_include_doctest.h,v 1.1 2022/04/25 13:58:46 tnn Exp $

avoid ambigous call to std::log10.

--- tests/include/doctest.h.orig	2022-01-10 10:00:49.000000000 +0000
+++ tests/include/doctest.h
@@ -5914,9 +5914,9 @@ namespace {
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
