$NetBSD: patch-src_test-C-API.cpp,v 1.1 2024/06/24 14:53:16 jperkin Exp $

Requires cmath.

--- src/test-C-API.cpp.orig	2024-06-24 14:51:06.244855568 +0000
+++ src/test-C-API.cpp
@@ -9,6 +9,7 @@
 
 // All test files should include the <testthat.h>
 // header file.
+#include <cmath>
 #include <testthat.h>
 #include "test-C-API.h"
 #include <nlopt.h>
