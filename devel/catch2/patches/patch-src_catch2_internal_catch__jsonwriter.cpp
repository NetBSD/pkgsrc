$NetBSD: patch-src_catch2_internal_catch__jsonwriter.cpp,v 1.1 2026/11/22 11:57:24 nros Exp $

Make sure Catch::isnan() is seen on SunOS

--- src/catch2/internal/catch_jsonwriter.cpp.orig	2026-11-22 01:36:51.175690001 +0000
+++ src/catch2/internal/catch_jsonwriter.cpp
@@ -7,12 +7,13 @@
 // SPDX-License-Identifier: BSL-1.0
 #include <catch2/internal/catch_enforce.hpp>
 #include <catch2/internal/catch_jsonwriter.hpp>
-#include <catch2/internal/catch_polyfills.hpp>
 #include <catch2/internal/catch_unreachable.hpp>
 
 #include <cmath>
 #include <locale>
 
+#include <catch2/internal/catch_polyfills.hpp>
+
 namespace Catch {
 
     namespace {
