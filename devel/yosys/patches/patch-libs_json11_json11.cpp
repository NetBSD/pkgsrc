$NetBSD: patch-libs_json11_json11.cpp,v 1.1 2025/04/20 23:01:47 js Exp $

--- libs/json11/json11.cpp.orig	2025-04-20 22:55:02.840778212 +0000
+++ libs/json11/json11.cpp
@@ -22,8 +22,9 @@
 #include "json11.hpp"
 #include <cassert>
 #include <cmath>
-#include <cstdlib>
+#include <cstdint>
 #include <cstdio>
+#include <cstdlib>
 #include <limits>
 
 namespace json11 {
