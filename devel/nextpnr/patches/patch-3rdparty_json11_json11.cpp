$NetBSD: patch-3rdparty_json11_json11.cpp,v 1.1 2025/04/20 22:29:14 js Exp $

--- 3rdparty/json11/json11.cpp.orig	2025-04-20 22:21:53.808130724 +0000
+++ 3rdparty/json11/json11.cpp
@@ -22,8 +22,9 @@
 #include "json11.hpp"
 #include <cassert>
 #include <cmath>
-#include <cstdlib>
+#include <cstdint>
 #include <cstdio>
+#include <cstdlib>
 #include <climits>
 #include <cerrno>
 
