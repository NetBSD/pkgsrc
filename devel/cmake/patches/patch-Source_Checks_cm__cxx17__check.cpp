$NetBSD: patch-Source_Checks_cm__cxx17__check.cpp,v 1.4 2019/07/19 09:06:23 adam Exp $

Test for an issue in the illumos headers related to C++17.

--- Source/Checks/cm_cxx17_check.cpp.orig	2019-07-17 12:07:17.000000000 +0000
+++ Source/Checks/cm_cxx17_check.cpp
@@ -1,7 +1,9 @@
 #include <cstdio>
 #include <iterator>
+#include <cassert>
 #include <memory>
 #include <unordered_map>
+#include <type_traits>
 
 #ifdef _MSC_VER
 #  include <comdef.h>
