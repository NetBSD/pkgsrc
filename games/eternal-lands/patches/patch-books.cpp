$NetBSD: patch-books.cpp,v 1.1 2023/11/21 18:05:59 nia Exp $

Missing header for std::round.

--- books.cpp.orig	2022-03-12 13:48:44.000000000 +0000
+++ books.cpp
@@ -2,6 +2,7 @@
 #include <string>
 #include <unordered_map>
 #include <vector>
+#include <cmath>
 #include "asc.h"
 #include "books.h"
 #include "elconfig.h"
