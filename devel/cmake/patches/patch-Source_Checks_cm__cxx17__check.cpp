$NetBSD: patch-Source_Checks_cm__cxx17__check.cpp,v 1.1 2018/05/11 13:39:57 jperkin Exp $

Test for an issue in the illumos headers related to C++17.

--- Source/Checks/cm_cxx17_check.cpp.orig	2018-04-17 12:28:52.000000000 +0000
+++ Source/Checks/cm_cxx17_check.cpp
@@ -1,5 +1,7 @@
+#include <cassert>
 #include <cstdio>
 #include <unordered_map>
+#include <type_traits>
 
 int main()
 {
