$NetBSD: patch-src_catch2_matchers_catch__matchers__floating__point.cpp,v 1.1 2024/01/18 09:52:28 nros Exp $

Make sure Catch::isnan() is seen on SunOS

--- src/catch2/matchers/catch_matchers_floating_point.cpp.orig	2024-01-18 10:39:21.370763696 +0000
+++ src/catch2/matchers/catch_matchers_floating_point.cpp
@@ -7,7 +7,6 @@
 // SPDX-License-Identifier: BSL-1.0
 #include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <catch2/internal/catch_enforce.hpp>
-#include <catch2/internal/catch_polyfills.hpp>
 #include <catch2/internal/catch_to_string.hpp>
 #include <catch2/catch_tostring.hpp>
 #include <catch2/internal/catch_floating_point_helpers.hpp>
@@ -20,6 +19,7 @@
 #include <iomanip>
 #include <limits>
 
+#include <catch2/internal/catch_polyfills.hpp>
 
 namespace Catch {
 namespace {
