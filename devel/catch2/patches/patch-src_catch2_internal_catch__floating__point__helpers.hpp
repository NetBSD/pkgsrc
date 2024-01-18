$NetBSD: patch-src_catch2_internal_catch__floating__point__helpers.hpp,v 1.1 2024/01/18 09:52:28 nros Exp $

Make sure Catch::isnan() is seen on SunOS

--- src/catch2/internal/catch_floating_point_helpers.hpp.orig	2024-01-15 13:13:53.000000000 +0000
+++ src/catch2/internal/catch_floating_point_helpers.hpp
@@ -8,14 +8,14 @@
 #ifndef CATCH_FLOATING_POINT_HELPERS_HPP_INCLUDED
 #define CATCH_FLOATING_POINT_HELPERS_HPP_INCLUDED
 
-#include <catch2/internal/catch_polyfills.hpp>
-
 #include <cassert>
 #include <cmath>
 #include <cstdint>
 #include <utility>
 #include <limits>
 
+#include <catch2/internal/catch_polyfills.hpp>
+
 namespace Catch {
     namespace Detail {
 
