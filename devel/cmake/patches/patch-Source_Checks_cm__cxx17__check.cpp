$NetBSD: patch-Source_Checks_cm__cxx17__check.cpp,v 1.3 2019/03/18 09:05:59 adam Exp $

Test for an issue in the illumos headers related to C++17.

--- Source/Checks/cm_cxx17_check.cpp.orig	2019-03-14 13:15:54.000000000 +0000
+++ Source/Checks/cm_cxx17_check.cpp
@@ -1,7 +1,9 @@
 #include <cstdio>
 #include <iterator>
+#include <cassert>
 #include <memory>
 #include <unordered_map>
+#include <type_traits>
 
 int main()
 {
