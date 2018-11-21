$NetBSD: patch-Source_Checks_cm__cxx17__check.cpp,v 1.2 2018/11/21 16:58:52 adam Exp $

Test for an issue in the illumos headers related to C++17.

--- Source/Checks/cm_cxx17_check.cpp.orig	2018-11-20 14:49:09.000000000 +0000
+++ Source/Checks/cm_cxx17_check.cpp
@@ -1,6 +1,8 @@
 #include <cstdio>
+#include <cassert>
 #include <memory>
 #include <unordered_map>
+#include <type_traits>
 
 int main()
 {
