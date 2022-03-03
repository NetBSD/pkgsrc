$NetBSD: patch-contrib_doctest_doctest_doctest.h,v 1.1 2022/03/03 16:23:31 jperkin Exp $

Explicitly use std::log10().

--- contrib/doctest/doctest/doctest.h.orig	2021-11-01 14:33:30.000000000 +0000
+++ contrib/doctest/doctest/doctest.h
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
