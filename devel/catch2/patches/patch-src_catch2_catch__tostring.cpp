$NetBSD: patch-src_catch2_catch__tostring.cpp,v 1.1 2024/01/18 09:52:27 nros Exp $

Make sure Catch::isnan() is seen on SunOS

--- src/catch2/catch_tostring.cpp.orig	2024-01-15 13:13:53.000000000 +0000
+++ src/catch2/catch_tostring.cpp
@@ -9,11 +9,12 @@
 #include <catch2/catch_tostring.hpp>
 #include <catch2/interfaces/catch_interfaces_config.hpp>
 #include <catch2/internal/catch_context.hpp>
-#include <catch2/internal/catch_polyfills.hpp>
 
 #include <cmath>
 #include <iomanip>
 
+#include <catch2/internal/catch_polyfills.hpp>
+
 namespace Catch {
 
 namespace Detail {
