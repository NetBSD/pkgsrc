$NetBSD: patch-utils_makemhr_loadsofa.cpp,v 1.1 2021/05/12 05:09:49 mcf Exp $

Fix build with gcc 11.

Upstream: https://github.com/kcat/openal-soft/commit/302e88dbf0f10224a5b87be4ce43b3fdd9d20184

--- utils/makemhr/loadsofa.cpp.orig	Wed May 12 04:49:10 2021
+++ utils/makemhr/loadsofa.cpp
@@ -34,6 +34,7 @@
 #include <memory>
 #include <numeric>
 #include <string>
+#include <thread>
 #include <vector>
 
 #include "makemhr.h"
