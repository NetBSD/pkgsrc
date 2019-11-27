$NetBSD: patch-Source_Checks_cm__cxx17__check.cpp,v 1.5 2019/11/27 22:32:27 adam Exp $

Test for an issue in the illumos headers related to C++17.

--- Source/Checks/cm_cxx17_check.cpp.orig	2019-11-26 14:18:07.000000000 +0000
+++ Source/Checks/cm_cxx17_check.cpp
@@ -1,8 +1,10 @@
 #include <cstdio>
 #include <iterator>
+#include <cassert>
 #include <memory>
 #include <optional>
 #include <unordered_map>
+#include <type_traits>
 
 #ifdef _MSC_VER
 #  include <comdef.h>
